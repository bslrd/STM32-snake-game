/**
 * @file Joystick.h
 *
 * @brief Joystick handling module based on ADC (STM32 HAL).
 *
 * @author bslrd
 * @date 2026
 *
 *
 *  SPDX-License-Identifier: MIT
 */

#ifndef INC_JOYSTICK_H_
#define INC_JOYSTICK_H_

#include "2dspace.h"
#include "main.h"
#include <stdbool.h>

/**
 * @brief Initializes joystick handling by passing given ADC handler and starting ADC.
 *
 * @param adc_handler pointer to ADC handler of choice.
 *
 * @note Should be called from main() before use of other joystick functions
 */
void joystick_init(ADC_HandleTypeDef * adc_handler);

/**
 * @brief Reads current joystick position from ADC.
 *
 * @param adc_handler pointer to ADC handler of choice.
 *
 * @return vec2_t type vector with vec.x and vec.y values of joystick position.
 */
vec2_t joystick_read(void);

/**
 * @brief Checks if joystick is tilted past the defined dead zone.
 *
 * @return returns true if joystick is outside the deadzone and false otherwise
 */
bool joystick_check_tilt(void);

/**
 * @brief interprets current joystick state as one of 4 directions or NONE.
 *
 * @return direction type value.
 */
direction_t joystick_get_direction(void);


#endif /* INC_JOYSTICK_H_ */
