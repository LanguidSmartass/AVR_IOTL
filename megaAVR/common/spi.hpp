/*
 * spi.hpp
 *
 * Created: 02/09/2018 04:53:18 PM
 *  Author: Novoselov Ivan
 */

#ifndef SPI_HPP_
#define SPI_HPP_

#include "ioregs.hpp"
#include "../../../bitops.hpp" // temporary

namespace megaAVR {

namespace spi {

template <
    std::uintptr_t spcr_addr,
    std::uintptr_t spsr_addr,
    std::uintptr_t spdr_addr
>
struct CTRL {
    // SPI registers
    using spcr  = IOreg_8bit<spcr_addr>;
    using spsr  = IOreg_8bit<spsr_addr>;
    using spdr  = IOreg_8bit<spdr_addr>;
    // spcr register bits
    using spie  = IObit<spcr, SPIE>;
    using spe   = IObit<spcr, SPE> ;
    using dord  = IObit<spcr, DORD>;
    using mstr  = IObit<spcr, MSTR>;
    using cpol  = IObit<spcr, CPOL>;
    using cpha  = IObit<spcr, CPHA>;
    using spr1  = IObit<spcr, SPR1>;
    using spr0  = IObit<spcr, SPR0>;
    // spsr register bits
    using spif  = IObit<spsr, SPIF>;
    using wcol  = IObit<spsr, WCOL>;
    using spi2x = IObit<spsr, SPI2X>;
};

template <
    class IOport,
    class PinMOSI,
    class PinMISO,
    class PinSCK,
    class PinCS
>
class GPIO {
    using port = IOport;
    using mosi = PinMOSI;
    using miso = PinMISO;
    using sck  = PinSCK;
    using cs   = PinCS;
};

namespace opmode {
    using type = bool;
    enum opmode : type {
        slave = false, master = true
    };
}

namespace spimode {
    using type = std::uint8_t;
    enum spimode : type {
        m0 = 0, m1 = 1, m2 = 2, m3 = 3
    };
}

namespace dataorder {
    using type = bool;
    enum dataorder : type {
        MSBfirst = false, LSBfirst = true
    };
}

namespace prescbits {
    using type = std::uint8_t;
    enum prescbits : type {
        p4 = 0, p16 = 1, p64 = 2, p128 = 3, p2 = 4, p8 = 5, p32 = 6, p64d = 7
    };
}
// PrescVal enum is just for reference, it does not participate in any calculations within the SPI class
namespace prescval {
    using type = std::uint8_t;
    enum prescval : type {
        p4 = 4, p16 = 16, p64 = 64, p128 = 128, p2 = 2, p8 = 8, p32 = 32, p64d = 64
    };
}
// These two enums are technically packed into the spimode enum,
// where clockpolarity is the MSBit and clockphase is the LSBit
namespace clockpolarity {
    using type = bool;
    enum clockpolarity : type {
        normal = false, inverted = true
    };
}
namespace clockphase {
    using type = bool;
    enum clockphase : type {
        normal = false, inverted = true
    };
}

template <
    class SPIGPIO,
    class SPICTRL
>
struct SPI {
    using ctrl = SPICTRL;
    using gpio = SPIGPIO;

    static void block_until_spif_is_set () { while (ctrl::spif::is_clr()) {} }

    static void cs_init () {
        gpio::cs::dirset_inp();
        gpio::cs::inp_pullup();
    }

    static void init (opmode::type opm, spimode::type md, dataorder::type dord, prescbits::type prsc) {
        ctrl::spcr::clr();
        cs_init();
        static_cast<bool>(dord) ? ctrl::dord::set() : ctrl::dord::clr();
        static_cast<bool>(opm) ? ctrl::mstr::set() : ctrl::mstr::clr();
        ctrl::spcr::set_msk(static_cast<uint8_t>(md) << CPHA);
        ctrl::spcr::set_msk(static_cast<uint8_t>(prsc) & bitops::msk_set_except<uint8_t>(3));
        bitops::chk_pos<uint8_t>(static_cast<uint8_t>(prsc), 3) ? ctrl::spi2x::set() : ctrl::spi2x::clr();
        ctrl::spe::set();
    }

    static void terminate () {
        ctrl::spie::clr();
        ctrl::spe::clr();
    }

    static void isr_enable () { ctrl::spie::set(); }

    static void isr_disable () { ctrl::spie::clr(); }

    static void send_nonblock (std::uint8_t b) { ctrl::spdr::set_val(b); }

    static void send_blocking (std::uint8_t b) {
        send_nonblock(b);
        block_until_spif_is_set();
    }

    static std::uint8_t recv_nonblock () { return ctrl::spdr::get_val(); }

    static std::uint8_t recv_blocking () {
        block_until_spif_is_set();
        return recv_nonblock();
    }

    static std::uint8_t transf_noblock (std::uint8_t b) {
        send_nonblock(b);
        return recv_nonblock();
    }

    static std::uint8_t transf_blocking (std::uint8_t b) {
        send_blocking(b);
        return recv_nonblock();
    }

     SPI () = delete;
    ~SPI () = delete;
};

} // namespace spi

} // namespace megaAVR

#endif /* SPI_HPP_ */
