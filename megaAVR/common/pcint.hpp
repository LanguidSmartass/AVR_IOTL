/*
 * pcint.hpp
 *
 * Created: 03/07/2018 11:55:13 AM
 *  Author: user21
 */


#ifndef MEGAAVR_PCINT_HPP_
#define MEGAAVR_PCINT_HPP_

#include "ioregs.hpp"

namespace megaAVR {

template <std::uintptr_t pcicr_addr, std::size_t n>
struct PcicrBit {
    using reg = IOreg_8bit<pcicr_addr>;

    static void set () { reg::set_bit(n); }

    static void clr () { reg::clr_bit(n); }
};

template <std::uintptr_t pcifr_addr, std::size_t n>
struct PcifrBit {
    using reg = IOreg_8bit<pcifr_addr>;

    static bool is_set () { return reg::is_set(n); }

    // PCIFRxn bit is cleared by writing a logical 1 into it
    static void clr () { reg::set_bit(n); }
};

template <
    class PcicrBit,
    class PcifrBit, std::uintptr_t pcmsk_addr,
    class GPIOport
>
struct Pcint {
    using pcmsk = IOreg_8bit<pcmsk_addr>;
    using IOport = GPIOport;

    static void enable_isr () { PcicrBit::set(); }

    static void disable_isr () { PcicrBit::clr(); }

    // % 8 (same as & 7 in this case) is to ensure that if someone uses, say, n as 23 meaning PCINT23 pin,
    // the 23 % 8 would transform to 7, which is a valid pin number
    static void inp_enable (const size_t n) {
        IOport::dirset_inp(n & 7);
        pcmsk::set_bit(n & 7);
    }

    static void inp_disable (const size_t n) { pcmsk::clr_bit(n & 7); }

    static bool inp_is_set (const size_t n) { return IOport::inp_is_set(n); }

    static bool inp_is_clr (const size_t n) { return IOport::inp_is_clr(n); }

    static bool flag_is_set () { return PcifrBit::is_set(); }

    static void flag_clr () { PcifrBit::clr(); }
};

}

#endif /* MEGAAVR_PCINT_HPP_ */
