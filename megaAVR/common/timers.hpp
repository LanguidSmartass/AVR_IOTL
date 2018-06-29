/*
 * timers.hpp
 *
 * Created: 02/06/2018 04:00:35 PM
 *  Author: Novoselov Ivan
 */

#ifndef MEGAAVR_TIMERS_H_
#define MEGAAVR_TIMERS_H_

#include "ioregs.hpp"
/*
 * This set of templates is an attempt to standardize the code generation for AVR MEGA family of microcontrollers
 */
namespace megaAVR {

template <
    typename BW, // bit width
    std::uintptr_t tccr_a_addr, std::uintptr_t tccr_b_addr, std::uintptr_t tcnt_addr,
    std::uintptr_t ocr_a_addr, std::uintptr_t ocr_b_addr,
    std::uintptr_t timsk_addr, std::uintptr_t tifr_addr, std::uintptr_t gtccr_addr
>
struct TimerCommon {
    using bitwidth = BW;
    // counter and compare registers -- these might require public access
    using tcnt   = IOreg<BW, tcnt_addr>;
    using ocr_a  = IOreg<BW, ocr_a_addr>;
    using ocr_b  = IOreg<BW, ocr_b_addr>;
    // hardware registers, any AVR MEGA timer has these (well, at least quite a lot of them)
    using gtccr = IOreg_8bit<gtccr_addr>;
    // control and interrupt registers -- always 8 bits wide
    using tccr_a = IOreg_8bit<tccr_a_addr>;
    using tccr_b = IOreg_8bit<tccr_b_addr>;
    using timsk  = IOreg_8bit<timsk_addr>;
    using tifr   = IOreg_8bit<tifr_addr>;
    // named bits of the hardware registers above
    // gtccr register bits
    using tsm     = IObit<gtccr, 7>;
    // tccr_a register bits
    using com_a1 = IObit<tccr_a, 7>;
    using com_a0 = IObit<tccr_a, 6>;
    using com_b1 = IObit<tccr_a, 5>;
    using com_b0 = IObit<tccr_a, 4>;
    using wgm_1  = IObit<tccr_a, 1>;
    using wgm_0  = IObit<tccr_a, 0>;
    // tccr_b register bits
    using foc_a = IObit<tccr_b, 7>;
    using foc_b = IObit<tccr_b, 6>;

    using wgm_2  = IObit<tccr_b, 3>;
    using cs_2   = IObit<tccr_b, 2>;
    using cs_1   = IObit<tccr_b, 1>;
    using cs_0   = IObit<tccr_b, 0>;
    // timsk register bits
    using ocie_b = IObit<timsk, 2>;
    using ocie_a = IObit<timsk, 1>;
    using toie   = IObit<timsk, 0>;
    // tifr register bits
    using ocf_b  = IObit<tifr, 2>;
    using ocf_a  = IObit<tifr, 1>;
    using tov    = IObit<tifr, 0>;

    enum class CompOutModeA :
        std::uint8_t {
        normal = 0, toggle = 1, clear = 2, set = 3
    };
    enum class CompOutModeB :
        std::uint8_t {
        normal = 0, toggle = 1, clear = 2, set = 3
    };
    enum class WaveGenMode :
        std::uint8_t {
        m0 = 0, m1 = 1, m2 = 2, m3 = 3, m4 = 4, m5 = 5, m6 = 6, m7 = 7
    };
    enum class PrescBits { p0 = 0, p1 = 1, p8 = 2, p64 = 3, p256 = 4, p1024 = 5, ext_fall = 6, ext_rise = 7 };
    enum class PrescVal { p0 = 0, p1 = 1, p8 = 8, p64 = 64, p256 = 256, p1024 = 1024 };

    static void clear_registers () {
        tcnt::clr();
        ocr_a::clr();
        ocr_b::clr();
        tccr_a::clr();
        tccr_b::clr();
        timsk::clr();
        tifr::set_val(0xFF);
    }

    static void set_compout_mode_a (CompOutModeA md) { tccr_a::set_msk(static_cast<uint8_t>(md) << 6); }

    static void set_compout_mode_b (CompOutModeB md) { tccr_a::set_msk(static_cast<uint8_t>(md) << 4); }

    static void forceout_comp_a () { foc_a::set(); }

    static void forceout_comp_b () { foc_b::set(); }

    static void int_comp_a_enable () { ocie_a::set(); }

    static void int_comp_b_enable () { ocie_b::set(); }

    static void int_timovf_enable () { tov::set(); }

    static void int_comp_a_disable () { ocie_a::clr(); }

    static void int_comp_b_disable () { ocie_b::clr(); }

    static void int_timovf_disable () { tov::clr(); }

    static bool flg_comp_a_is_set () { return ocf_b::is_set(); }

    static bool flg_comp_b_is_set () { return ocf_a::is_set(); }

    static bool flg_timovf_is_set () { return tov::is_set(); }

    static bool flg_comp_a_clr () { return ocf_b::is_set(); }

    static bool flg_comp_b_clr () { return ocf_a::is_set(); }

    static bool flg_timovf_clr () { return tov::is_set(); }

    static void set_wavegen_mode (WaveGenMode md) {
        auto md0 = static_cast<std::uint8_t>(md) & 1u; // uint8_t result will be 0b0000'000z
        auto md1 = static_cast<std::uint8_t>(md) & 2u; // uint8_t result will be 0b0000'00y0
        auto md2 = static_cast<std::uint8_t>(md) & 4u; // uint8_t result will be 0b0000'0x00
        md0 ? wgm_0::set() : wgm_0::clr();
        md1 ? wgm_1::set() : wgm_1::clr();
        md2 ? wgm_2::set() : wgm_2::clr();
    }

    static void sync_mode_on () { tsm::set(); }

    static void sync_mode_off () { tsm::clr(); }

    static void set_prescaler (PrescBits pr) { tccr_b::set_msk(static_cast<std::uint8_t>(pr)); }

    static void stop () { set_prescaler(PrescBits::p0); }
};

template <
    typename BW,
    std::uintptr_t tccr_a_addr, std::uintptr_t tccr_b_addr,
    std::uintptr_t tcnt_addr,
    std::uintptr_t ocr_a_addr, std::uintptr_t ocr_b_addr,
    std::uintptr_t timsk_addr, std::uintptr_t tifr_addr,
    std::uintptr_t gtccr_addr
>
struct TimerSync :
    TimerCommon<
        BW,
        tccr_a_addr, tccr_b_addr,
        tcnt_addr,
        ocr_a_addr, ocr_b_addr,
        timsk_addr, tifr_addr,
        gtccr_addr
    > {
    using Base =
    TimerCommon<BW, tccr_a_addr, tccr_b_addr, tcnt_addr, ocr_a_addr, ocr_b_addr, timsk_addr, tifr_addr, gtccr_addr>;
    using gtccr = IOreg_8bit<gtccr_addr>;
    // gtccr register bits
    using psrsync = IObit<gtccr, 0>;

    static void prescaler_reset () { psrsync::set(); } // caution, this will reset ALL synchronous timers
};

template <
    typename BW,
    std::uintptr_t tccr_a_addr, std::uintptr_t tccr_b_addr,
    std::uintptr_t tcnt_addr,
    std::uintptr_t ocr_a_addr, std::uintptr_t ocr_b_addr,
    std::uintptr_t timsk_addr, std::uintptr_t tifr_addr,
    std::uintptr_t gtccr_addr,
    std::uintptr_t assr_addr
>
struct TimerAsync :
    TimerCommon<
        BW,
        tccr_a_addr, tccr_b_addr,
        tcnt_addr,
        ocr_a_addr, ocr_b_addr,
        timsk_addr, tifr_addr,
        gtccr_addr
    > {
    using Base =
    TimerCommon<BW, tccr_a_addr, tccr_b_addr, tcnt_addr, ocr_a_addr, ocr_b_addr, timsk_addr, tifr_addr, gtccr_addr>;

    using gtccr = IOreg_8bit<gtccr_addr>;
    using assr  = IOreg_8bit<assr_addr>;
    // gtccr register bit
    using psrasy  = IObit<gtccr, 1>;
    // assr register bits
    using exclk   = IObit<assr, 6>;
    using as      = IObit<assr, 5>;
    using tcn_ub  = IObit<assr, 4>;
    using ocr_aub = IObit<assr, 3>;
    using ocr_bub = IObit<assr, 2>;
    using tcr_aub = IObit<assr, 1>;
    using tcr_bub = IObit<assr, 0>;

    // override the prescaler enum
    enum class PrescBits { p0 = 0, p1 = 1, p8 = 2, p32 = 3, p64 = 4, p128 = 5, p256 = 6, p1024 = 7 };
    enum class PrescVal { p0 = 0, p1 = 1, p8 = 8, p32 = 32, p64 = 64, p128 = 128, p256 = 256, p1024 = 1024 };

    static void clear_registers () {
        Base::clear_registers();
        assr::clr();
    }

    // override the set_prescaler method (for provide the appropriate type)
    static void set_prescaler (PrescBits pr) { Base::tccr_b::set_msk(static_cast<uint8_t>(pr)); }

    static void stop () { set_prescaler(PrescBits::p0); }

    static void prescaler_reset () { psrasy::set(); }

    static void extclk_enable () { exclk::set(); }

    static void extclk_disable () { exclk::clr(); }

    static bool tcnt_is_modifiable () { return tcn_ub::is_clr(); }

    static bool ocr_a_is_modifiable () { return ocr_aub::is_clr(); }

    static bool ocr_b_is_modifiable () { return ocr_bub::is_clr(); }

    static bool tccr_a_is_modifiable () { return tcr_aub::is_clr(); }

    static bool tccr_b_is_modifiable () { return tcr_bub::is_clr(); }
};

template <
    typename BW,
    std::uintptr_t tccr_a_addr, std::uintptr_t tccr_b_addr, std::uintptr_t tccr_c_addr,
    std::uintptr_t tcnt_addr,
    std::uintptr_t ocr_a_addr, std::uintptr_t ocr_b_addr, std::uintptr_t ocr_c_addr,
    std::uintptr_t timsk_addr, std::uintptr_t tifr_addr,
    std::uintptr_t gtccr_addr,
    std::uintptr_t icr_addr
>
struct TimerSyncExtended :
    TimerSync<
        BW,
        tccr_a_addr, tccr_b_addr,
        tcnt_addr,
        ocr_a_addr, ocr_b_addr,
        timsk_addr, tifr_addr,
        gtccr_addr
    > {
    // compare and capture registers -- these might require public access
    using ocr_c  = IOreg<BW, ocr_c_addr>;
    using icr    = IOreg<BW, icr_addr>;

    using Base =
    TimerSync<BW, tccr_a_addr, tccr_b_addr, tcnt_addr, ocr_a_addr, ocr_b_addr, timsk_addr, tifr_addr, gtccr_addr>;

    using tccr_b = IOreg_8bit<tccr_b_addr>; // I could not get the tccr_b from the base class template, so redefine it
    using tccr_c = IOreg_8bit<tccr_c_addr>;
    using timsk  = IOreg_8bit<timsk_addr>;
    using tifr   = IOreg_8bit<tifr_addr>;
    // Extended timer tccr_b specific bits
    using icnc   = IObit<tccr_b, 7>;
    using ices   = IObit<tccr_b, 6>;
    using wgm_3  = IObit<tccr_b, 4>;
    // tccr_c specific bits
    // For the extended timers the force output compare methods must be overridden,
    // since the foc bits are located in another register
    using foc_a = IObit<tccr_c, 7>;
    using foc_b = IObit<tccr_c, 6>;
    using foc_c = IObit<tccr_c, 5>;
    // timsk
    using icie   = IObit<timsk, 5>;
    using ocie_c = IObit<timsk, 3>;
    // tifr
    using icf    = IObit<tifr, 5>;
    using ocf_c  = IObit<tifr, 3>;

    enum class CompOutModeC :
        std::uint8_t {
        normal = 0, toggle = 1, clear = 2, set = 3
    };
    enum class WaveGenMode :
        std::uint8_t {
        m0 = 0, m1 = 1, m2 = 2, m3 = 3, m4 = 4, m5 = 5, m6 = 6, m7 = 7,
        m8 = 8, m9 = 9, m11 = 11, m12 = 12, m13 = 13, m14 = 14, m15 = 15
    };
    enum class InputCaptureEdge :
        std::uint8_t {
        falling = 0, rising = 1
    };

    static void clear_registers () {
        Base::clear_registers();
        tccr_c::clr();
        ocr_c::clr();
        icr::clr();
    }

    static void set_compout_mode_c (CompOutModeC md) { Base::tccr_a::set_msk(static_cast<std::uint8_t>(md) << 2); }

    // override 2 base class methods
    static void forceout_comp_a () { foc_a::set(); }

    static void forceout_comp_b () { foc_b::set(); }

    // additional methods for output C
    static void forceout_comp_c () { foc_c::set(); }

    static void int_comp_c_enable () { ocie_c::set(); }

    static void int_comp_c_disable () { ocie_c::clr(); }

    static bool flg_comp_c_is_set () { return ocf_c::is_set(); }

    static void flg_comp_c_clr () { return ocf_c::set(); }

    // override
    static void set_wavegen_mode (WaveGenMode md) {
        auto md0 = static_cast<std::uint8_t>(md) & 1u; // uint8_t result will be 0b0000'000z
        auto md1 = static_cast<std::uint8_t>(md) & 2u; // uint8_t result will be 0b0000'00y0
        auto md2 = static_cast<std::uint8_t>(md) & 4u; // uint8_t result will be 0b0000'0x00
        auto md3 = static_cast<std::uint8_t>(md) & 8u; // uint8_t result will be 0b0000'w000
        md0 ? Base::wgm_0::set() : Base::wgm_0::clr();
        md1 ? Base::wgm_1::set() : Base::wgm_1::clr();
        md2 ? Base::wgm_2::set() : Base::wgm_2::clr();
        md3 ? wgm_3::set() : wgm_3::clr();
    }

    // input capture
    static void inp_capt_cancel_noise (bool b) { b ? icnc::set() : icnc::clr(); }

    static void inp_capt_edge_set (InputCaptureEdge md) { static_cast<bool>(md) ? ices::clr() : ices::set(); }

    static void inp_capt_edge_falling () { ices::clr(); }

    static void inp_capt_edge_rising () { ices::set(); }

    static void inp_capt_edge_tgl () { ices::tgl(); }
};

template <
    std::uintptr_t tccr_a_addr, std::uintptr_t tccr_b_addr, std::uintptr_t tcnt_addr,
    std::uintptr_t ocr_a_addr, std::uintptr_t ocr_b_addr,
    std::uintptr_t timsk_addr, std::uintptr_t tifr_addr,
    std::uintptr_t gtccr_addr
>
using Timer8BitSync = TimerSync<
    std::uint8_t,
    tccr_a_addr, tccr_b_addr, tcnt_addr,
    ocr_a_addr, ocr_b_addr,
    timsk_addr, tifr_addr,
    gtccr_addr
>;

template <
    std::uintptr_t tccr_a_addr, std::uintptr_t tccr_b_addr, std::uintptr_t tcnt_addr,
    std::uintptr_t ocr_a_addr, std::uintptr_t ocr_b_addr,
    std::uintptr_t timsk_addr, std::uintptr_t tifr_addr,
    std::uintptr_t gtccr_addr,
    std::uintptr_t assr_addr
>
using Timer8BitAsync = TimerAsync<
    std::uint8_t,
    tccr_a_addr, tccr_b_addr, tcnt_addr,
    ocr_a_addr, ocr_b_addr,
    timsk_addr, tifr_addr,
    gtccr_addr,
    assr_addr
>;

template <
    std::uintptr_t tccr_a_addr, std::uintptr_t tccr_b_addr, std::uintptr_t tccr_c_addr, std::uintptr_t tcnt_addr,
    std::uintptr_t ocr_a_addr, std::uintptr_t ocr_b_addr, std::uintptr_t ocr_c_addr,
    std::uintptr_t timsk_addr, std::uintptr_t tifr_addr, std::uintptr_t gtccr_addr, std::uintptr_t icr_addr
>
using Timer16BitSync = TimerSyncExtended<
    std::uint16_t,
    tccr_a_addr, tccr_b_addr, tccr_c_addr, tcnt_addr,
    ocr_a_addr, ocr_b_addr, ocr_c_addr,
    timsk_addr, tifr_addr, gtccr_addr, icr_addr
>;

} // namespace megaAVR

#endif /* MEGAAVR_TIMERS_H_ */
