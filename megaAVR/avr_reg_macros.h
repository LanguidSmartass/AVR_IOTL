/** @file avr_reg_macros.h
 *
 * @brief This header file provides bitwise functionality on integers.
 * @author Novoselov Ivan (i.novoselov\@quantumspace.ru)
 * @date   2017-11-16-11.15.13
 * @copyright Quantum Systems, Inc.
 *
 * @details This header file provides bitwise functionality on integers. @n It is
 *          intended for use with AVR8 I/O registers,
 *          thus macros are named accordingly. @n Depends on bitOperations.h.
 */

#ifndef AVR_REG_MACROS_H_
#define AVR_REG_MACROS_H_

#include "bitOperations/bitOperations.h"

#define PIN_HIGH  1
#define PIN_LOW   0

#define PIN_PULLUP   1
#define PIN_PULLDOWN 0

/** @def PIN_OUT_SET_HIGH(portr, pinn)
 * @brief Sets the number @p pinn in register @p portr HIGH (one).
 *        @li @p portr -- port register
 *        @li @p pinn -- pin number (bit position)
 */
#define PIN_OUT_SET_HIGH(portr, pinn) SET_BIT((portr), (pinn))

/** @def PIN_OUT_SET_LOW(portr, pinn)
* @brief Sets the number @p pinn in register @p portr LOW (zero).
 *        @li @p portr -- port register
 *        @li @p pinn -- pin number (bit position)
 */
#define PIN_OUT_SET_LOW(portr, pinn)  CLR_BIT((portr), (pinn))

/** @def PIN_INP_GET_VAL(pinr, pinn)
 * @brief Checks the value of bit @p pinn in register @p pinr.
 *        @li @p pinr -- pin register
 *        @li @p pinn -- pin number (bit position)
 */
#define PIN_INP_GET_VAL(pinr, pinn) CHK_BITP((pinr), (pinn))

/** @def PIN_OUT_SET_VAL(portr, pinn, hilo)
 * @brief Changes the value of bit @p pinn in @p pinr depending on @p hilo.
 *        If @p hilo is 0, bit @p pinn is cleared. If not -- bit is set.
 *        @li @p portr -- port register
 *        @li @p pinn -- pin number (bit position)
 *        @li @p hilo -- select pin state, HIGH (1) or LOW (0)
 */
#define PIN_OUT_SET_VAL(portr, pinn, hilo) \
do { \
    (hilo == 0) ? PIN_OUT_SET_LOW((portr), (pinn)) : \
                  PIN_OUT_SET_HIGH((portr), (pinn)); \
} while (0)

/** @def INIT_PIN_OUT(ddr, portr, pinn, hilo)
 * @brief Initiates selected pin as an output. HIGH or LOW depends on
 *        value of hilo.
 *        @li @p ddr -- data direction register
 *        @li @p portr -- port register
 *        @li @p pinn -- pin number (bit position)
 *        @li @p hilo -- select default pin state, HIGH (1) or LOW (0)
 */
#define INIT_PIN_OUT(ddr, portr, pinn, hilo) \
do { \
    SET_BIT((ddr), (pinn)); \
    PIN_OUT_SET_VAL((portr), (pinn), (hilo)); \
} while (0)

/** @def INIT_PIN_INP(ddr, portr, pinn, pupd)
 * @brief Initiates selected pin as an input. Pull-up or Pull-down depends on
 *        value of pupd.
 *        @li @p ddr -- data direction register
 *        @li @p portr -- port register
 *        @li @p pinn -- pin number (bit position)
 *        @li @p pupd -- select default pin state,
 *                       Pulled-up (1) or Pulled-down (0)
 */
#define INIT_PIN_INP(ddr, portr, pinn, pupd) \
do { \
    CLR_BIT((ddr), (pinn)); \
    PIN_OUT_SET_VAL((portr), (pinn), (pupd)); \
} while (0)

#endif /* AVR_REG_MACROS_H_ */

