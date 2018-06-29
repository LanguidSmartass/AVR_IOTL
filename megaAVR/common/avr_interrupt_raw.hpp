/*
 * avr_interrupt_raw.h
 *
 * Created: 26.03.2018 22:27:06
 *  Author: Waffle
 */

#ifndef AVR_INTERRUPT_RAW_HPP_
#define AVR_INTERRUPT_RAW_HPP_

#ifndef _SFR_ASM_COMPAT
#define _SFR_ASM_COMPAT 1
#endif

#if _SFR_ASM_COMPAT

#include <avr/interrupt.h>

#else /* !_SFR_ASM_COMPAT */
#error "The AVR-LibC must be configured to use RAW addressed. Otherwise the C++ IO templates won't compile." \
       "You will see quite a lot of errors which look like this:" \
       "__*42 is not a constant expression__" \
       ", meaning the compiler stumbles upon raw address dereferencing where a constant number is required."
#endif /* _SFR_ASM_COMPAT */

#endif /* AVR_INTERRUPT_RAW_HPP_ */
