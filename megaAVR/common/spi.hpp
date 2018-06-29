/*
 * spi.hpp
 *
 * Created: 02/09/2018 04:53:18 PM
 *  Author: Novoselov Ivan
 */

#ifndef SPI_HPP_
#define SPI_HPP_

#include "ioregs.hpp"
#include <generic/bitops/bitops.hpp>

namespace megaAVR {

template <
    class IOport,
    class PinMOSI,
    class PinMISO,
    class PinSCK,
    class PinCS
>
class SPIPort {
    using port = IOport;
    using mosi = PinMOSI;
    using miso = PinMISO;
    using sck  = PinSCK;
    using cs   = PinCS;
};

namespace spi_stngs {

enum class OpMode :
    bool {
    slave = 0, master = 1
};
enum class SPIMode :
    uint8_t {
    m0 = 0, m1 = 1, m2 = 2, m3 = 3
};
enum class DataOrder :
    bool {
    MSBfirst = 0, LSBfirst = 1
};
enum class PrescBits :
    uint8_t {
    p4 = 0, p16 = 1, p64 = 2, p128 = 3, p2 = 4, p8 = 5, p32 = 6, p64d = 7
};
// PrescVal enum is just for reference, it does not participate in any calculations within the SPI class
enum class PrescVal :
    uint8_t {
    p4 = 4, p16 = 16, p64 = 64, p128 = 128, p2 = 2, p8 = 8, p32 = 32, p64d = 64
};

} // namespace spi_stngs

template <
    class SPIPort, std::uintptr_t spcr_addr, std::uintptr_t spsr_addr, std::uintptr_t spdr_addr
>
struct SPI {
    // SPI port pins
    using mosi  = SPIPort::mosi;
    using miso  = SPIPort::miso;
    using sck   = SPIPort::sck;
    using cs    = SPIPort::cs;
    // SPI registers
    using spcr  = IOreg_8bit<spcr_addr>;
    using spsr  = IOreg_8bit<spsr_addr>;
    using spdr  = IOreg_8bit<spdr_addr>;
    // spcr register bits
    using spie  = IObit<spcr, SPIE>;
    using spe   = IObit<spcr, SPE>;
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
    // These two enums are technically packed into the SPIMode enum,
    // where ClockPolarity is the MSBit and ClockPhase is the LSBit
    enum class ClockPolarity { normal = 0, inverted = 1 };
    enum class ClockPhase { normal = 0, inverted = 1 };
    using namespace spi_stngs;

    static void block_until_spif_is_set () { while (spif::is_clr()) {} }

    static void cs_init () {
        cs::dirset_inp();
        cs::inp_pullup();
    }

    static void init (OpMode opm, SPIMode md, DataOrder datord, PrescBits prsc) {
        spcr::clr();
        cs_init();
        static_cast<bool>(datord) ? dord::set() : dord::clr();
        static_cast<bool>(opm) ? mstr::set() : mstr::clr();
        spcr::set_msk(static_cast<uint8_t>(md) << CPHA);
        spcr::set_msk(static_cast<uint8_t>(prsc) & bitops::all_set_except<uint8_t>(3));
        bitops::chk_pos<uint8_t>(static_cast<uint8_t>(prsc), 3) ? spi2x::set() : spi2x::clr();
        spe::set();
    }

    static void terminate () {
        spie::clr();
        spe::clr();
    }

    static void isr_enable () { spie::set(); }

    static void isr_disable () { spie::clr(); }

    static void send_nonblock (std::uint8_t b) { spdr::set_val(b); }

    static void send_blocking (std::uint8_t b) {
        send_nonblock(b);
        block_until_spif_is_set();
    }

    static std::uint8_t recv_nonblock () { return spdr::get_val(); }

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
};

} // namespace megaAVR

#endif /* SPI_HPP_ */
