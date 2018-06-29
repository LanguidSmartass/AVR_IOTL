/*
 * pcint.hpp
 *
 * Created: 03/07/2018 11:47:44 AM
 *  Author: user21
 */ 


#ifndef MEGAAVR_M2560_PCINT_HPP_
#define MEGAAVR_M2560_PCINT_HPP_

#include "../../common/avr_io_raw.hpp"
#include "../../common/pcint.hpp"
#include "../../common/isr_class_macro.hpp"
#include "gpio.hpp"

namespace megaAVR {

namespace m2560 {

using PcicrBit0 = megaAVR::PcicrBit<PCICR, 0>;
using PcicrBit1 = megaAVR::PcicrBit<PCICR, 1>;
using PcicrBit2 = megaAVR::PcicrBit<PCICR, 2>;

using PcifrBit0 = megaAVR::PcifrBit<PCIFR, 0>;
using PcifrBit1 = megaAVR::PcifrBit<PCIFR, 1>;
using PcifrBit2 = megaAVR::PcifrBit<PCIFR, 2>;

using Pcint0to7   = megaAVR::Pcint<PcicrBit0, PcifrBit0, PCMSK0, gpio::PortB>;
using Pcint8to15  = megaAVR::Pcint<PcicrBit1, PcifrBit1, PCMSK1, gpio::PortJ>;
using Pcint16to23 = megaAVR::Pcint<PcicrBit2, PcifrBit2, PCMSK2, gpio::PortK>;

} // namespace m2560

} // namespace megaAVR

#endif /* MEGAAVR_M2560_PCINT_HPP_ */
