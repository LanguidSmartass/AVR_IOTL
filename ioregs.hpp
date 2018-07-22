/*
 * ioregs.hpp
 *
 * Created: 02/05/2018 05:34:17 PM
 *  Author: Novoselov Ivan
 */

#ifndef GENERIC_IO_IOREGS_HPP_
#define GENERIC_IO_IOREGS_HPP_

#include <cinttypes>

namespace genericIO {

// Targeted
// Since I pass a hardware address it is better to use uintptr_t as a template parameter type
template <typename T, std::uintptr_t regaddr>
struct IOreg {
private:
    // Can't enforce RegWidth to be unsigned integer without the STL
    static volatile T& val () { return *(volatile T*)regaddr; }

public:
    using width = T;

    static void clr () { val() = 0; }

    // Read the value from register
    static T get_val () { return val(); }

    // Write a whole register by value
    static void set_val (T vl) { val() = vl; }

    // Set   one or several bits using a mask, !! the bits to be set     must be 1 in the mask
    static void set_msk (T msk) { val() or_eq msk; }

    // Clear one or several bits using a mask, !! the bits to be cleared must be 1 in the mask
    static void clr_msk (T msk) { val() and_eq ~msk; }

    // I hope that the platform-dependent size_t will be enough to represent any hardware IO register bit number until I die
    static void set_bit (std::size_t n) { val() or_eq (1 << n); } // reg |=  (1 << bit)
    static void clr_bit (std::size_t n) { val() and_eq ~(1 << n); } // reg &= ~(1 << bit)
    static void tgl_bit (std::size_t n) { val() xor_eq (1 << n); } // reg ^=  (1 << bit)

    static bool is_set (std::size_t n) { return val() & (1 << n); }

    static bool is_clr (std::size_t n) { return !is_set(n); }
};

template <class IOreg, std::size_t n>
struct IObit {
    using reg = IOreg;

    static void set () { reg::set_bit(n); }

    static void clr () { reg::clr_bit(n); }

    static void tgl () { reg::tgl_bit(n); }

    static bool is_set () { return reg::is_set(n); }

    static bool is_clr () { return reg::is_clr(n); }
};

template <class GPIOport, std::size_t n>
struct GPIOpin {
    using port = GPIOport;
    constexpr static std::size_t num = n;

    static void dirset_out () { port::dirset_out(n); }

    static void dirset_inp () { port::dirset_inp(n); }

    static void out_set () { port::out_set(n); }

    static void out_clr () { port::out_clr(n); }

    static void out_tgl () { port::out_tgl(n); }

    static bool out_is_set () { return port::out_is_set(n); }

    static bool out_is_clr () { return port::out_is_clr(n); }

    static void inp_pullup () { port::inp_pullup(n); }

    static void inp_trist () { port::inp_trist(n); }

    static void inp_pulldn () { port::inp_pulldn(n); }

    static bool dir_is_out () { return port::dir_is_out(n); }

    static bool dir_is_inp () { return port::dir_is_inp(n); }

    static bool inp_is_set () { return port::inp_is_set(n); }

    static bool inp_is_clr () { return port::inp_is_clr(n); }
};
// Some aliases for common width registers just for the sake of simplicity
template <std::uintptr_t RegAddr>
using IOreg_8bit = IOreg<std::uint8_t, RegAddr>;

template <std::uintptr_t RegAddr>
using IOreg_16bit = IOreg<std::uint16_t, RegAddr>;

template <std::uintptr_t RegAddr>
using IOreg_32bit = IOreg<std::uint32_t, RegAddr>;

template <std::uintptr_t RegAddr>
using IOreg_64bit = IOreg<std::uint64_t, RegAddr>;

// Some helper function templates for generic IO configurations
template <class Pin>
inline void init_input_pullup () {
    Pin::dirset_inp();
    Pin::inp_pullup();
}

template <class Pin>
inline void init_input_trist () {
    Pin::dirset_inp();
    Pin::inp_trist();
}

template <class Pin>
inline void init_input_pulldn () {
    Pin::dirset_inp();
    Pin::inp_pulldn();
}

template <class Pin>
inline void init_output_hi () {
    Pin::dirset_out();
    Pin::out_set();
}

template <class Pin>
inline void init_output_lo () {
    Pin::dirset_out();
    Pin::out_clr();
}

} // namespace genericIO

#endif /* GENERIC_IO_IOREGS_HPP_ */
