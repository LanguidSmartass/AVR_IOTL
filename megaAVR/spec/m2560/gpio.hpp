/*
 * gpio.hpp
 *
 * Created: 02/06/2018 03:39:06 PM
 *  Author: Novoselov Ivan
 */ 

#ifndef MEGAAVR_M2560_GPIO_HPP_
#define MEGAAVR_M2560_GPIO_HPP_

#include "../../common/gpio.hpp"

namespace megaAVR {

namespace m2560 {

//template <intptr_t PortRegAddr, intptr_t PinRegAddr, intptr_t DataDirRegAddr>
//using GPIOport = megaAVR::GPIOport<PortRegAddr, PinRegAddr, DataDirRegAddr>;

template <class GPIOport, size_t n>
using GPIOpin  = genericIO::GPIOpin<GPIOport, n>;

using PortA = GPIOport<PORTA, PINA, DDRA>;
using PortB = GPIOport<PORTB, PINB, DDRB>;
using PortC = GPIOport<PORTC, PINC, DDRC>;
using PortD = GPIOport<PORTD, PIND, DDRD>;
using PortE = GPIOport<PORTE, PINE, DDRE>;
using PortF = GPIOport<PORTF, PINF, DDRF>;
using PortG = GPIOport<PORTG, PING, DDRG>;
using PortH = GPIOport<PORTH, PINH, DDRH>;
// No 'I' port
using PortJ = GPIOport<PORTJ, PINJ, DDRJ>;
using PortK = GPIOport<PORTK, PINK, DDRK>;
using PortL = GPIOport<PORTL, PINL, DDRL>;

using PinA0 = GPIOpin<PortA, 0>;
using PinA1 = GPIOpin<PortA, 1>;
using PinA2 = GPIOpin<PortA, 2>;
using PinA3 = GPIOpin<PortA, 3>;
using PinA4 = GPIOpin<PortA, 4>;
using PinA5 = GPIOpin<PortA, 5>;
using PinA6 = GPIOpin<PortA, 6>;
using PinA7 = GPIOpin<PortA, 7>;

using PinB0 = GPIOpin<PortB, 0>;
using PinB1 = GPIOpin<PortB, 1>;
using PinB2 = GPIOpin<PortB, 2>;
using PinB3 = GPIOpin<PortB, 3>;
using PinB4 = GPIOpin<PortB, 4>;
using PinB5 = GPIOpin<PortB, 5>;
using PinB6 = GPIOpin<PortB, 6>;
using PinB7 = GPIOpin<PortB, 7>;

using PinC0 = GPIOpin<PortC, 0>;
using PinC1 = GPIOpin<PortC, 1>;
using PinC2 = GPIOpin<PortC, 2>;
using PinC3 = GPIOpin<PortC, 3>;
using PinC4 = GPIOpin<PortC, 4>;
using PinC5 = GPIOpin<PortC, 5>;
using PinC6 = GPIOpin<PortC, 6>;
using PinC7 = GPIOpin<PortC, 7>;

using PinD0 = GPIOpin<PortD, 0>;
using PinD1 = GPIOpin<PortD, 1>;
using PinD2 = GPIOpin<PortD, 2>;
using PinD3 = GPIOpin<PortD, 3>;
using PinD4 = GPIOpin<PortD, 4>;
using PinD5 = GPIOpin<PortD, 5>;
using PinD6 = GPIOpin<PortD, 6>;
using PinD7 = GPIOpin<PortD, 7>;

using PinE0 = GPIOpin<PortE, 0>;
using PinE1 = GPIOpin<PortE, 1>;
using PinE2 = GPIOpin<PortE, 2>;
using PinE3 = GPIOpin<PortE, 3>;
using PinE4 = GPIOpin<PortE, 4>;
using PinE5 = GPIOpin<PortE, 5>;
using PinE6 = GPIOpin<PortE, 6>;
using PinE7 = GPIOpin<PortE, 7>;

using PinF0 = GPIOpin<PortF, 0>;
using PinF1 = GPIOpin<PortF, 1>;
using PinF2 = GPIOpin<PortF, 2>;
using PinF3 = GPIOpin<PortF, 3>;
using PinF4 = GPIOpin<PortF, 4>;
using PinF5 = GPIOpin<PortF, 5>;
using PinF6 = GPIOpin<PortF, 6>;
using PinF7 = GPIOpin<PortF, 7>;

using PinG0 = GPIOpin<PortG, 0>;
using PinG1 = GPIOpin<PortG, 1>;
using PinG2 = GPIOpin<PortG, 2>;
using PinG3 = GPIOpin<PortG, 3>;
using PinG4 = GPIOpin<PortG, 4>;
using PinG5 = GPIOpin<PortG, 5>;
// no PinG6 pin
// no PinG7 pin

using PinH0 = GPIOpin<PortH, 0>;
using PinH1 = GPIOpin<PortH, 1>;
using PinH2 = GPIOpin<PortH, 2>;
using PinH3 = GPIOpin<PortH, 3>;
using PinH4 = GPIOpin<PortH, 4>;
using PinH5 = GPIOpin<PortH, 5>;
using PinH6 = GPIOpin<PortH, 6>;
using PinH7 = GPIOpin<PortH, 7>;

using PinJ0 = GPIOpin<PortJ, 0>;
using PinJ1 = GPIOpin<PortJ, 1>;
using PinJ2 = GPIOpin<PortJ, 2>;
using PinJ3 = GPIOpin<PortJ, 3>;
using PinJ4 = GPIOpin<PortJ, 4>;
using PinJ5 = GPIOpin<PortJ, 5>;
using PinJ6 = GPIOpin<PortJ, 6>;
using PinJ7 = GPIOpin<PortJ, 7>;

using PinK0 = GPIOpin<PortK, 0>;
using PinK1 = GPIOpin<PortK, 1>;
using PinK2 = GPIOpin<PortK, 2>;
using PinK3 = GPIOpin<PortK, 3>;
using PinK4 = GPIOpin<PortK, 4>;
using PinK5 = GPIOpin<PortK, 5>;
using PinK6 = GPIOpin<PortK, 6>;
using PinK7 = GPIOpin<PortK, 7>;

using PinL0 = GPIOpin<PortL, 0>;
using PinL1 = GPIOpin<PortL, 1>;
using PinL2 = GPIOpin<PortL, 2>;
using PinL3 = GPIOpin<PortL, 3>;
using PinL4 = GPIOpin<PortL, 4>;
using PinL5 = GPIOpin<PortL, 5>;
using PinL6 = GPIOpin<PortL, 6>;
using PinL7 = GPIOpin<PortL, 7>;

} // namespace m2560

} // namespace megaAVR

#endif /* MEGAAVR_M2560_GPIO_HPP_ */
