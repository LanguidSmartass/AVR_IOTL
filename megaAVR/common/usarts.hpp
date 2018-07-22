/*
 * usarts.hpp
 *
 * Created: 02/09/2018 04:52:07 PM
 *  Author: Novoselov Ivan
 */

#ifndef MEGAAVR_USARTS_HPP_
#define MEGAAVR_USARTS_HPP_

#include "ioregs.hpp"
#include "interrupt.hpp"
#include "../../../bitops.hpp" // temporary

namespace megaAVR {

namespace usart {

template <
    std::uintptr_t udr_addr,
    std::uintptr_t ucsra_addr, std::uintptr_t ucsrb_addr,
    std::uintptr_t ucsrc_addr, std::uintptr_t ubrr_addr
>
struct CTRL {
    // USART registers
    using udr     = IOreg_8bit<udr_addr>;
    using ucsra   = IOreg_8bit<ucsra_addr>;
    using ucsrb   = IOreg_8bit<ucsrb_addr>;
    using ucsrc   = IOreg_8bit<ucsrc_addr>;
    using ubrr    = IOreg_8bit<ubrr_addr>;
    // ucsra register bits
    using rxc     = IObit<ucsra, 7>;
    using txc     = IObit<ucsra, 6>;
    using udre    = IObit<ucsra, 5>;
    using fe      = IObit<ucsra, 4>;
    using dor     = IObit<ucsra, 3>;
    using upe     = IObit<ucsra, 2>;
    using u2x     = IObit<ucsra, 1>;
    using mpcm    = IObit<ucsra, 0>;
    // ucsrb register bits
    using rxcie   = IObit<ucsrb, 7>;
    using txcie   = IObit<ucsrb, 6>;
    using udrie   = IObit<ucsrb, 5>;
    using rxen    = IObit<ucsrb, 4>;
    using txen    = IObit<ucsrb, 3>;
    using ucsz_2  = IObit<ucsrb, 2>;
    using rxb8    = IObit<ucsrb, 1>;
    using txb8    = IObit<ucsrb, 0>;
    // ucsrc register bits
    using umsel_1 = IObit<ucsrc, 7>;
    using umsel_0 = IObit<ucsrc, 6>;
    using upm_1   = IObit<ucsrc, 5>;
    using upm_0   = IObit<ucsrc, 4>;
    using usbs    = IObit<ucsrc, 3>;
    using ucsz_1  = IObit<ucsrc, 2>;
    using ucsz_0  = IObit<ucsrc, 1>;
    using ucpol   = IObit<ucsrc, 0>;
};

template <
    class IOport,
    class PinRX,
    class PinTX,
    class PinXCK
>
class GPIO {
    using port = IOport;
    using rx   = PinRX;
    using tx   = PinTX;
    using xck  = PinXCK;
};

namespace databits {
    using type = std::uint8_t;
    enum databits : type {
        five = 5, six = 6, seven = 7, eight = 8, nine = 9
    };
}
namespace parity {
    using type = std::uint8_t;
    enum parity : type {
        none = 0, odd = 1, even = 2
    };
}
namespace stopbits {
    using type = std::uint8_t;
    enum stopbits : type {
        one = 1, two = 2
    };
}
namespace doublespeed {
    using type = bool;
    enum doublespeed : type {
        disable = false, enable = true
    };
}
namespace synchronous {
    using type = bool;
    enum synchronous : type {
        disable = false, enable = true
    };
}

template <
    class USARTGPIO,
    class USARTCTRL
>
struct USART {
    using ctrl = USARTCTRL;
    using gpio = USARTGPIO;

    static void init (
        std::uint32_t     f_cpu,
        std::uint32_t     baud,
        databits::type    datab,
        parity::type      par,
        stopbits::type    stopb,
        doublespeed::type dsp_en,
        synchronous::type sync_en
                     ) {
        cli();
        // Clear frame error bit
        ctrl::fe::clr();
        // Calculate baud setting
        std::uint32_t baud_divider = 2;
        /* Set Sync/Async */
        if (sync_en == synchronous::enable) {
            baud_divider = 2;
            ctrl::u2x::clr();
        } else {
            if (dsp_en == doublespeed::enable) {
                baud_divider = 8;
                ctrl::u2x::set();
            } else {
                baud_divider = 16;
                ctrl::u2x::clr();
            }
        }
        std::uint16_t baud_setting = static_cast<decltype(baud_setting)>(((f_cpu / baud_divider) / baud) - 1);
        /**< Set Baud Rate */
        ctrl::ubrr::set_val(baud_setting);
        /**< Enable Receiver and Transmitter**/
        tx_enable();
        rx_enable();
        /**< Enable Interrupt on Recieve Complete */
        rxci_enable();
        /**< Preliminary disable Interrupt on USART Data Register Empty */
        udri_disable();

        /**< Set Frame Format */
        if        (datab == databits::five) {
            ctrl::ucsz_2::clr();
            ctrl::ucsz_1::clr();
            ctrl::ucsz_0::clr();
        } else if (datab == databits::six) {
            ctrl::ucsz_2::clr();
            ctrl::ucsz_1::clr();
            ctrl::ucsz_0::set();
        } else if (datab == databits::seven) {
            ctrl::ucsz_2::clr();
            ctrl::ucsz_1::set();
            ctrl::ucsz_0::clr();
        } else if (datab == databits::eight) {
            ctrl::ucsz_2::clr();
            ctrl::ucsz_1::set();
            ctrl::ucsz_0::set();
        } else if (datab == databits::nine) {
            ctrl::ucsz_2::set();
            ctrl::ucsz_1::set();
            ctrl::ucsz_0::set();
        }

        if        (par == parity::none) {
            ctrl::upm_1::clr();
            ctrl::upm_0::clr();
        } else if (par == parity::even) {
            ctrl::upm_1::set();
            ctrl::upm_0::clr();
        } else if (par == parity::odd) {
            ctrl::upm_1::set();
            ctrl::upm_0::set();
        }

        if      (stopb == stopbits::one) { ctrl::usbs::clr(); }
        else if (stopb == stopbits::two) { ctrl::usbs::set(); }

        sei();
    }

    static void send_raw (std::uint8_t val) {
        ctrl::udr::set_val(val);
    }

    static void send_raw (char val) {
        send_raw(static_cast<uint8_t>(val));
    }

    static void send_raw (std::uint16_t val) {
        ctrl::txb8::clr();
        if (val & 0x0100) { ctrl::txb8::set(); }
        ctrl::udr::set_val(val);
    }

    static void recv_raw (std::uint8_t& dest) {
        dest = ctrl::udr::get_val();
    }

    static void recv_raw (char& dest) {
        dest = static_cast<char>(ctrl::udr::get_val());
    }

    static void recv_raw (std::uint16_t& dest) {
        std::uint16_t tmp = ctrl::udr::get_val();
        if (ctrl::rxb8::is_set()) { bitops::set_pos<std::uint16_t>(tmp, 9); }
        dest = tmp;
    }

    static void send (std::uint8_t val) {
        block_until_udre_is_set();
        send_raw(val);
    }

    static void send (char c) {
        send(static_cast<std::uint8_t>(c));
    }

    static void send (std::uint16_t val) {
        block_until_udre_is_set();
        send_raw(val);
    }

    static void recv (std::uint8_t& dest) {
        block_until_rcx_is_set();
        recv_raw(dest);
    }

    static void recv (char& dest) {
        recv(reinterpret_cast<std::uint8_t&>(dest));
    }

    static void recv (std::uint16_t& dest) {
        block_until_rcx_is_set();
        recv_raw(dest);
    }

    static void tx_disable () {
        ctrl::txen::clr();
    }

    static void tx_enable () {
        ctrl::txen::set();
    }

    static void rx_disable () {
        ctrl::rxen::clr();
    }

    static void rx_enable () {
        ctrl::rxen::set();
    }

    /**< Disable/enable interrupt on Usart Data Register Empty */
    static void udri_disable () {
        ctrl::udrie::clr();
    }

    static void udri_enable () {
        ctrl::udrie::set();
    }

    /**< Disable/enable interrupt on Recieve Complete */
    static void rxci_disable () {
        ctrl::rxcie::clr();
    }

    static void rxci_enable () {
        ctrl::rxcie::set();
    }

    /**< Disable/enable interrupt on Transmit Complete */
    static void txci_disable () {
        ctrl::txcie::clr();
    }

    static void txci_enable () {
        ctrl::txcie::set();
    }

    static void block_until_rcx_is_set () {
        while (ctrl::rxc::is_clr()) {}
    }

    static void block_until_udre_is_set () {
        while (ctrl::udre::is_clr()) {}
    }

     USART() = delete;
    ~USART() = delete;
};

}

} // namespace megaAVR

#endif /* MEGAAVR_USARTS_HPP_ */
