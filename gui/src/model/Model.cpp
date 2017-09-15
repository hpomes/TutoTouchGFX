/******************************************************************************
 *
 * @brief     This file is part of the TouchGFX 4.6.1 evaluation distribution.
 *
 * @author    Draupner Graphics A/S <http://www.touchgfx.com>
 *
 ******************************************************************************
 *
 * @section Copyright
 *
 * This file is free software and is provided for example purposes. You may
 * use, copy, and modify within the terms and conditions of the license
 * agreement.
 *
 * This is licensed software for evaluation use, any use must strictly comply
 * with the evaluation license agreement provided with delivery of the
 * TouchGFX software.
 *
 * The evaluation license agreement can be seen on www.touchgfx.com
 *
 * @section Disclaimer
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Draupner Graphics A/S has
 * no obligation to support this software. Draupner Graphics A/S is providing
 * the software "AS IS", with no express or implied warranties of any kind,
 * including, but not limited to, any implied warranties of merchantability
 * or fitness for any particular purpose or warranties against infringement
 * of any proprietary rights of a third party.
 *
 * Draupner Graphics A/S can not be held liable for any consequential,
 * incidental, or special damages, or any other relief, or for any claim by
 * any third party, arising from your use of this software.
 *
 *****************************************************************************/
#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
	#include "stm32f769i_discovery.h"
#endif

Model::Model() : modelListener(0)
{
	#ifndef SIMULATOR
		BSP_LED_Init(LED1);
		BSP_LED_Off(LED1);
		initPulsePWM();
	#endif
	btnClicked = false;
	acc = 0;
	ledOn = false;
}

void Model::tick()
{
#ifndef SIMULATOR
	if (btnClicked && !ledOn)
	{
		BSP_LED_On(LED1);
		ledOn = true;
		generatePulsePWM();
	}
	else if (!btnClicked && ledOn)
	{
		BSP_LED_Off(LED1);
		ledOn = false;
	}
#endif
}

#ifndef SIMULATOR
void Model::initPulsePWM()
{
	__HAL_RCC_GPIOA_CLK_ENABLE(); // Enable gpioa
	__HAL_RCC_TIM1_CLK_ENABLE(); // Rnable timer 1
	
	GPIO_Init.Pin = GPIO_PIN_11; //D10 on CN9
	GPIO_Init.Mode = GPIO_MODE_AF_PP;
	GPIO_Init.Pull = GPIO_NOPULL;
	GPIO_Init.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_Init.Alternate = GPIO_AF1_TIM1; // Peripheral connected to pin
	HAL_GPIO_Init(GPIOA, &GPIO_Init);
	
	TIM_Handle.Instance = TIM1;

	TIM_Base.Prescaler = 4;
	TIM_Base.CounterMode = TIM_COUNTERMODE_UP;
	TIM_Base.Period = 3999;
	TIM_Base.ClockDivision = 0;
	TIM_Base.RepetitionCounter = 0;
	
	
	TIM_Handle.Init = TIM_Base;
	TIM_Handle.Channel = HAL_TIM_ACTIVE_CHANNEL_4;
	HAL_TIM_OC_Init(&TIM_Handle);
	
	TIM_OC.OCMode = TIM_OCMODE_PWM1;
	TIM_OC.Pulse = 1;
	TIM_OC.OCPolarity = TIM_OCPOLARITY_LOW;
	TIM_OC.OCNPolarity = TIM_OCNPOLARITY_LOW;
	TIM_OC.OCFastMode = TIM_OCFAST_DISABLE;
	TIM_OC.OCIdleState = TIM_OCIDLESTATE_SET;
	TIM_OC.OCNIdleState = TIM_OCNIDLESTATE_SET;
	HAL_TIM_OC_ConfigChannel(&TIM_Handle, &TIM_OC, TIM_CHANNEL_4);
	
	dc_SetCompare = TIM_Base.Period - (acc/100)*(TIM_Base.Period);
	__HAL_TIM_SetCompare(&TIM_Handle, TIM_CHANNEL_4, dc_SetCompare);

	HAL_TIM_PWM_Start(&TIM_Handle, TIM_CHANNEL_4);
}
#endif

#ifndef SIMULATOR
	void Model::generatePulsePWM()
	{
		TIM_Handle.Instance = TIM1;
		TIM_Base.Prescaler = 4;
		TIM_Base.Period = 3999;
		TIM_Handle.Init = TIM_Base;
		TIM_Handle.Channel = HAL_TIM_ACTIVE_CHANNEL_4;
		HAL_TIM_OC_Init(&TIM_Handle);

		HAL_TIM_OC_ConfigChannel(&TIM_Handle, &TIM_OC, TIM_CHANNEL_4);

		dc_SetCompare = TIM_Base.Period - (acc / 100)*(TIM_Base.Period);
		__HAL_TIM_SetCompare(&TIM_Handle, TIM_CHANNEL_4, dc_SetCompare);

		HAL_TIM_PWM_Start(&TIM_Handle, TIM_CHANNEL_4);
	}
#endif
