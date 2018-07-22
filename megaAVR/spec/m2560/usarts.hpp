/*
 * usarts.hpp
 *
 * Created: 03/13/2018 02:53:36 PM
 *  Author: user21
 */ 

#ifndef MEGAAVR_M2560_USARTS_HPP_
#define MEGAAVR_M2560_USARTS_HPP_

#include "../../common/usarts.hpp"
#include "gpio.hpp"

namespace megaAVR {

namespace m2560 {

namespace databits    = megaAVR::usart::databits;
namespace parity      = megaAVR::usart::parity;
namespace stopbits    = megaAVR::usart::stopbits;
namespace doublespeed = megaAVR::usart::doublespeed;
namespace synchronous = megaAVR::usart::synchronous;

using Usart0GPIO = megaAVR::usart::GPIO<PortE, PinE0, PinE1, PinE2>;
using Usart1GPIO = megaAVR::usart::GPIO<PortD, PinD2, PinD3, PinD5>;
using Usart2GPIO = megaAVR::usart::GPIO<PortH, PinH0, PinH1, PinH2>;
using Usart3GPIO = megaAVR::usart::GPIO<PortJ, PinJ0, PinJ1, PinJ2>;

using Usart0CTRL = megaAVR::usart::CTRL<UDR0, UCSR0A, UCSR0B, UCSR0C, UBRR0>;
using Usart1CTRL = megaAVR::usart::CTRL<UDR1, UCSR1A, UCSR1B, UCSR1C, UBRR1>;
using Usart2CTRL = megaAVR::usart::CTRL<UDR2, UCSR2A, UCSR2B, UCSR2C, UBRR2>;
using Usart3CTRL = megaAVR::usart::CTRL<UDR3, UCSR3A, UCSR3B, UCSR3C, UBRR3>;

using Usart0 = megaAVR::usart::USART<Usart0GPIO, Usart0CTRL>;
using Usart1 = megaAVR::usart::USART<Usart1GPIO, Usart1CTRL>;
using Usart2 = megaAVR::usart::USART<Usart2GPIO, Usart2CTRL>;
using Usart3 = megaAVR::usart::USART<Usart3GPIO, Usart3CTRL>;

} // namespace m2560

} // namespace megaAVR

#endif /* MEGAAVR_M2560_USARTS_HPP_ */
