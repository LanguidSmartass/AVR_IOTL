/*
 * spi.hpp
 *
 * Created: 03/14/2018 03:32:16 PM
 *  Author: user21
 */ 

#ifndef MEGAAVR_M2560_SPI_HPP_
#define MEGAAVR_M2560_SPI_HPP_

#include "../../common/spi.hpp"

namespace megaAVR {

namespace m2560 {

using OpMode    = megaAVR::spi_stngs::OpMode   ;
using SPIMode   = megaAVR::spi_stngs::SPIMode  ;
using PrescBits = megaAVR::spi_stngs::PrescBits;
using PrescVal  = megaAVR::spi_stngs::PrescVal ;

using SPIPort   = megaAVR::SPIPort<PortB, PinB2, PinB3, PinB1, PinB0>;
using SPI       = megaAVR::SPI<SPIPort, SPCR, SPSR, SPDR>;

} // namespace m2560

} // namespace megaAVR

#endif /* MEGAAVR_M2560_SPI_HPP_ */
