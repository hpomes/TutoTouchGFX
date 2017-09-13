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
	}
	else if (!btnClicked && ledOn)
	{
		BSP_LED_Off(LED1);
		ledOn = false;
	}
#endif
}

