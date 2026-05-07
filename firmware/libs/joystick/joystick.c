/**
 * @file Joystick.c
 *
 * @brief Implementation of joystick handling module (STM32 HAL).
 *
 * @author bslrd
 * @date 2026
 *
 *
 *  SPDX-License-Identifier: MIT
 */

#include "joystick.h"


/***********************************/
// CONFIGURATION
/***********************************/
#define JOYSTICK_TH_LOW 100
#define JOYSTICK_TH_HIGH 3900

/***********************************/
// STATIC VARIABLES & FUNCTIONS
/***********************************/
static ADC_HandleTypeDef *hadc_joystick;

static void ADC_SetActiveChannel(ADC_HandleTypeDef *hadc, uint32_t AdcChannel)
{
	ADC_ChannelConfTypeDef sConfig = {0};
	sConfig.Channel = AdcChannel;
	sConfig.Rank = 1;
	sConfig.SamplingTime = 480;
	if (HAL_ADC_ConfigChannel(hadc, &sConfig) != HAL_OK)
	{
		Error_Handler();
	}
}

/***********************************/
// PUBLIC API
/***********************************/
void joystick_init(ADC_HandleTypeDef * adc_handler)
{
	hadc_joystick = adc_handler;
	HAL_ADC_Start(hadc_joystick);
}

vec2_t joystick_read(void)
{
	vec2_t joystick;
	if(HAL_ADC_PollForConversion(hadc_joystick, 10) == HAL_OK)
	{
		joystick.x = HAL_ADC_GetValue(hadc_joystick); // Get X value
		ADC_SetActiveChannel(hadc_joystick, ADC_CHANNEL_7);
		HAL_ADC_Start(hadc_joystick);
	}

	if(HAL_ADC_PollForConversion(hadc_joystick, 10) == HAL_OK)
	{
		joystick.y = HAL_ADC_GetValue(hadc_joystick); // Get Y value
		ADC_SetActiveChannel(hadc_joystick, ADC_CHANNEL_6);
		HAL_ADC_Start(hadc_joystick);
	}
	return joystick;
}

bool joystick_check_tilt(void)
{
	vec2_t joystick_values = joystick_read();
	if(joystick_values.x<JOYSTICK_TH_LOW || joystick_values.x>JOYSTICK_TH_HIGH || joystick_values.y < JOYSTICK_TH_LOW || joystick_values.y > JOYSTICK_TH_HIGH)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

direction_t joystick_get_direction(void)
{
	vec2_t joystick_values = joystick_read();
	if(joystick_values.x < JOYSTICK_TH_LOW)
	{
		return LEFT;
	}
	else if(joystick_values.x > JOYSTICK_TH_HIGH)
	{
		return RIGHT;
	}
	else if(joystick_values.y > JOYSTICK_TH_HIGH)
	{
		return DOWN;
	}
	else if(joystick_values.y < JOYSTICK_TH_LOW)
	{
		return UP;
	}
	else
	{
		return NONE;
	}
}

