/*
 * ioregs.h
 *
 * Created: 03/14/2018 10:56:52 AM
 *  Author: user21
 */

#ifndef MEGAAVR_IOREGS_HPP_
#define MEGAAVR_IOREGS_HPP_

#include "../../ioregs.hpp"
#include "avr_io_raw.hpp"

namespace megaAVR {

template <typename T, std::uintptr_t addr>
using IOreg = genericIO::IOreg<T, addr>;

template <std::uintptr_t addr>
using IOreg_8bit = genericIO::IOreg_8bit<addr>;

template <typename R, std::uint8_t n>
using IObit = genericIO::IObit<R, n>;

} // namespace megaAVR

#endif /* MEGAAVR_IOREGS_HPP_ */
