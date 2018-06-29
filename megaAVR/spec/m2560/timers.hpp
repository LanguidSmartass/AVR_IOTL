/*
 * timers.hpp
 *
 * Created: 02/15/2018 01:36:13 PM
 *  Author: user21
 */ 


#ifndef MEGAAVR_M2560_TIMERS_HPP_
#define MEGAAVR_M2560_TIMERS_HPP_

#include "../../common/timers.hpp"
#include "../../common/isr_class_macro.hpp"

namespace megaAVR {

namespace m2560 {

// 8-bit timer
using Timer0 = megaAVR::Timer8BitSync<
TCCR0A, TCCR0B, TCNT0, 
OCR0A, OCR0B, 
TIMSK0, TIFR0, GTCCR
>;
// 8-bit timer with async functionality
using Timer2 = megaAVR::Timer8BitAsync<
TCCR2A, TCCR2B, TCNT2, 
OCR2A, OCR2B, 
TIMSK2, TIFR2, GTCCR,  ASSR
>;
// 16-bit timers
using Timer1 = megaAVR::Timer16BitSync<
TCCR1A, TCCR1B, TCCR1C, TCNT1, 
OCR1A, OCR1B, OCR1C, 
TIMSK1, TIFR1, GTCCR, ICR1
>;

using Timer3 = megaAVR::Timer16BitSync<
TCCR3A, TCCR3B, TCCR3C, TCNT3, 
OCR3A, OCR3B, OCR3C, 
TIMSK3, TIFR3, GTCCR, ICR3
>;

using Timer4 = megaAVR::Timer16BitSync<
TCCR4A, TCCR4B, TCCR4C, TCNT4, 
OCR4A, OCR4B, OCR4C, 
TIMSK4, TIFR4, GTCCR, ICR4
>;

using Timer5 = megaAVR::Timer16BitSync<
TCCR5A, TCCR5B, TCCR5C, TCNT5, 
OCR5A, OCR5B, OCR5C, 
TIMSK5, TIFR5, GTCCR, ICR5
>;

} // namespace m2560

} // namespace megaAVR

#endif /* MEGAAVR_M2560_TIMERS_HPP_ */
