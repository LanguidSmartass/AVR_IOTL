/*
 * isr_class_macro.h
 *
 * Created: 02/15/2018 05:00:22 PM
 *  Author: Novoselov Ivan
 */

#ifndef ISR_CLASS_MACRO_HPP_
#define ISR_CLASS_MACRO_HPP_

#include "avr_io_raw.hpp"

// this idea would have been smart, but each vector takes 50 more bytes of flash
// than just using ISR(SOME_INT_vector) { /* implementation */ }

#define MAKE_CLASS_WITH_FRIEND_ISR_VECTOR(ClassName, vector, ...) \
extern "C" void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
class ClassName {                                            \
private:                                                     \
    static void body ();                                     \
    friend void vector();                                    \
}

#define MAKE_ISR_VECTOR_EXECUTING_CLASS_BODY_FUNCTION(ClassName, vector)    \
extern "C" void vector (void) { ClassName::body(); }

// // example usage (for generic 8-bit timer with 3 interrupts):
// MAKE_CLASS_WITH_FRIEND_ISR_VECTOR(Tim0_Ovf,   TIMER0_OVF_vect  );
// MAKE_CLASS_WITH_FRIEND_ISR_VECTOR(Tim0_CompA, TIMER0_COMPA_vect);
// MAKE_CLASS_WITH_FRIEND_ISR_VECTOR(Tim0_CompB, TIMER0_COMPB_vect);
//
// void Tim0_Ovf  ::vector(void) { Tim0_Ovf  ::body(); } // this might be absolutely redundant
// void Tim0_CompA::vector(void) { Tim0_CompA::body(); } // this might be absolutely redundant
// void Tim0_CompB::vector(void) { Tim0_CompB::body(); } // this might be absolutely redundant
//
// // Instantiate the class from a template
// using Timer0 = megaAVR::Timer8BitSync <TCCR0A, TCCR0B, TCNT0, OCR0A, OCR0B, TIMSK0, TIFR0, GTCCR, Tim0_Ovf, Tim0_CompA, Tim0_CompB>;
// // Now, every body() function has access to every private member of the Timer0, I got what I wanted.
// // The user only needs to provide a definition of a body() function for each desired interrupt vector handling,
// // to do that the user must include the header with several calls of the macro and do this:
// #include "where_the_macro_were_called.hpp"
//
// void Tim0_Ovf::body() { /* Implementation of the Overflow  interrupt vector handler */}
// void Tim0_Ovf::body() { /* Implementation of the Compare A interrupt vector handler */}
// void Tim0_Ovf::body() { /* Implementation of the Compare B interrupt vector handler */}
// 

#endif /* ISR_CLASS_MACRO_HPP_ */
