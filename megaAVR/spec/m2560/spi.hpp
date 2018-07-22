/*
 * spi.hpp
 *
 * Created: 03/14/2018 03:32:16 PM
 *  Author: user21
 */ 

#ifndef MEGAAVR_M2560_SPI_HPP_
#define MEGAAVR_M2560_SPI_HPP_

#include "../../common/spi.hpp"
#include "gpio.hpp"

namespace megaAVR {

namespace m2560 {

namespace opmode        = megaAVR::spi::opmode;
namespace spimode       = megaAVR::spi::spimode;
namespace dataorder     = megaAVR::spi::dataorder;
namespace prescbits     = megaAVR::spi::prescbits;
namespace prescval      = megaAVR::spi::prescval;
namespace clockpolarity = megaAVR::spi::clockpolarity;
namespace clockphase    = megaAVR::spi::clockphase;

using SpiGPIO = megaAVR::spi::GPIO<PortB, PinB2, PinB3, PinB1, PinB0>;
using SpiCTRL = megaAVR::spi::CTRL<SPCR, SPSR, SPDR>;
using Spi     = megaAVR::spi::SPI<SpiGPIO, SpiCTRL>;

} // namespace m2560

} // namespace megaAVR

#endif /* MEGAAVR_M2560_SPI_HPP_ */
