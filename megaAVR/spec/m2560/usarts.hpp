/*
 * usarts.hpp
 *
 * Created: 03/13/2018 02:53:36 PM
 *  Author: user21
 */ 

#ifndef MEGAAVR_M2560_USARTS_HPP_
#define MEGAAVR_M2560_USARTS_HPP_

#include "megaAVR/common/usarts.hpp"

namespace megaAVR {

namespace m2560 {

using DataBits    = megaAVR::usart_stngs::DataBits    ;
using Parity      = megaAVR::usart_stngs::Parity      ;
using StopBits    = megaAVR::usart_stngs::StopBits    ;
using DoubleSpeed = megaAVR::usart_stngs::DoubleSpeed ;
using Synchronous = megaAVR::usart_stngs::Synchronous ;

using Usart0_regs = megaAVR::UsartRegisters<UDR0, UCSR0A, UCSR0B, UCSR0C, UBRR0>;
using Usart1_regs = megaAVR::UsartRegisters<UDR1, UCSR1A, UCSR1B, UCSR1C, UBRR1>;
using Usart2_regs = megaAVR::UsartRegisters<UDR2, UCSR2A, UCSR2B, UCSR2C, UBRR2>;
using Usart3_regs = megaAVR::UsartRegisters<UDR3, UCSR3A, UCSR3B, UCSR3C, UBRR3>;

template <
uint32_t    f_cpu    ,
uint32_t    baud     ,
DataBits    datab    ,
Parity      parity   ,
StopBits    stopb    ,
DoubleSpeed dsp_en   ,
Synchronous sync_en
>
using Usart0 = megaAVR::USART<Usart0_regs, f_cpu, baud, datab, parity, stopb, dsp_en, sync_en>;

template <
uint32_t    f_cpu    ,
uint32_t    baud     ,
DataBits    datab    ,
Parity      parity   ,
StopBits    stopb    ,
DoubleSpeed dsp_en   ,
Synchronous sync_en
>
using Usart1 = megaAVR::USART<Usart1_regs, f_cpu, baud, datab, parity, stopb, dsp_en, sync_en>;

template <
uint32_t    f_cpu    ,
uint32_t    baud     ,
DataBits    datab    ,
Parity      parity   ,
StopBits    stopb    ,
DoubleSpeed dsp_en   ,
Synchronous sync_en
>
using Usart2 = megaAVR::USART<Usart2_regs, f_cpu, baud, datab, parity, stopb, dsp_en, sync_en>;

template <
uint32_t    f_cpu    ,
uint32_t    baud     ,
DataBits    datab    ,
Parity      parity   ,
StopBits    stopb    ,
DoubleSpeed dsp_en   ,
Synchronous sync_en
>
using Usart3 = megaAVR::USART<Usart3_regs, f_cpu, baud, datab, parity, stopb, dsp_en, sync_en>;

} // namespace m2560

} // namespace megaAVR

#endif /* MEGAAVR_M2560_USARTS_HPP_ */
