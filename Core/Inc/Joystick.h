/*
 * Joystick.h
 *
 *  Created on: 30 kwi 2026
 *      Author: dominik
 */

#ifndef SRC_JOYSTICK_H_
#define SRC_JOYSTICK_H_

#include "direction.h"
#include "main.h"

#define JOYSTICK_TH_LOW 100
#define JOYSTICK_TH_HIGH 3900
void Joystick_init(ADC_HandleTypeDef * adc_handler);
void ADC_SetActiveChannel(ADC_HandleTypeDef *hadc, uint32_t AdcChannel);
void joystick_read();
int8_t joystick_check_tilt();
direction joystick_get_direction();


#endif /* SRC_JOYSTICK_H_ */
