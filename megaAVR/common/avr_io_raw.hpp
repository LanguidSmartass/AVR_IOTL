/*
 * avr_raw_addr.hpp
 *
 * Created: 02/09/2018 05:09:58 PM
 *  Author: user21
 */

#ifndef AVR_RAW_ADDR_HPP_
#define AVR_RAW_ADDR_HPP_

// This #define makes the registers macro (like PORTA or DDRB) expand into integer-constants (addresses)
// instead of the volatile pointer dereference expression *(volatile uint8_t *)ADDR
#ifndef _SFR_ASM_COMPAT
#define _SFR_ASM_COMPAT 1
#endif

#if _SFR_ASM_COMPAT

#include <avr/io.h>

#else /* !_SFR_ASM_COMPAT */
#error "The AVR-LibC must be configured to use RAW addressed. Otherwise the C++ IO templates won't compile." \
       "You will see quite a lot of errors which look like this:" \
       "__*42 is not a constant expression__" \
       ", meaning the compiler stumbles upon raw address dereferencing where a constant number is required."
#endif /* _SFR_ASM_COMPAT */

#endif /* AVR_RAW_ADDR_HPP_ */
