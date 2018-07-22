/*
 * gpio.hpp
 *
 * Created: 02/05/2018 06:29:11 PM
 *  Author: Novoselov Ivan
 */

#ifndef MEGAAVR_GPIO_HPP_
#define MEGAAVR_GPIO_HPP_

#include "ioregs.hpp"

namespace megaAVR {

template <std::uintptr_t PortRegAddr, std::uintptr_t PinRegAddr, std::uintptr_t DataDirRegAddr>
struct GPIOport {
    using PortReg    = IOreg_8bit<PortRegAddr>;
    using PinReg     = IOreg_8bit<PinRegAddr>;
    using DataDirReg = IOreg_8bit<DataDirRegAddr>;

    static void dirset_out (std::size_t n) { DataDirReg::set_bit(n); }

    static void dirset_inp (std::size_t n) { DataDirReg::clr_bit(n); }

    static void out_set (std::size_t n) { PortReg::set_bit(n); }

    static void out_clr (std::size_t n) { PortReg::clr_bit(n); }

    // writing a logic 1 to PINxn toggles the value of PORTxn, independent of value of DDRxn
    static void out_tg (std::size_t n) { PinReg::set_bit(n); }

    // while the gpio is in output mode reading PIN register returns the current output state
    static bool out_is_set (std::size_t n) { return inp_is_set(n); }

    static bool out_is_clr (std::size_t n) { return inp_is_clr(n); }

    static void inp_pullup (std::size_t n) { PortReg::set_bit(n); }

    static void inp_trist (std::size_t n) { PortReg::clr_bit(n); }

    static bool dir_is_out (std::size_t n) { return DataDirReg::is_set(n); }

    static bool dir_is_inp (std::size_t n) { return DataDirReg::is_clr(n); }

    static bool inp_is_set (std::size_t n) { return PinReg::is_set(n); }

    static bool inp_is_clr (std::size_t n) { return PinReg::is_clr(n); }

    static typename PinReg::width
    get_inp_reg () { return PinReg::get_val(); }

    static void
    set_inp_reg (typename PinReg::width val) { PinReg::set_val(val); }
};

} // namespace megaAVR

#endif /* MEGAAVR_GPIO_HPP_ */
