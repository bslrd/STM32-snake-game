/*
 * Joystick.c
 *
 *  Created on: 30 kwi 2026
 *      Author: dominik
 */
#include "Joystick.h"

static int Joystick[2];
ADC_HandleTypeDef *hadc_joystick;

void Joystick_init(ADC_HandleTypeDef * adc_handler)
{
	hadc_joystick = adc_handler;
	HAL_ADC_Start(hadc_joystick);
}

void ADC_SetActiveChannel(ADC_HandleTypeDef *hadc, uint32_t AdcChannel)
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


void joystick_read()
{
	if(HAL_ADC_PollForConversion(hadc_joystick, 10) == HAL_OK)
	{
		Joystick[0] = HAL_ADC_GetValue(hadc_joystick); // Get X value
		ADC_SetActiveChannel(hadc_joystick, ADC_CHANNEL_7);
		HAL_ADC_Start(hadc_joystick);
	}

	if(HAL_ADC_PollForConversion(hadc_joystick, 10) == HAL_OK)
	{
		Joystick[1] = HAL_ADC_GetValue(hadc_joystick); // Get Y value
		ADC_SetActiveChannel(hadc_joystick, ADC_CHANNEL_6);
		HAL_ADC_Start(hadc_joystick);
	}

}


int8_t joystick_check_tilt()
{
	if(Joystick[0]<100 || Joystick[0]>3900 || Joystick[1] < 100 || Joystick[1] > 3900)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


direction joystick_get_direction()
{
	if(Joystick[0] < 100)
	{
		return LEFT;
	}
	else if(Joystick[0] > 3900)
	{
		return RIGHT;
	}
	else if(Joystick[1] > 3900)
	{
		return DOWN;
	}
	else //if(Joystick[1] < 1300)
	{
		return UP;
	}
}

