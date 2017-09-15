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
#include <gui/template_screen/TemplatePresenter.hpp>
#include <gui/template_screen/TemplateView.hpp>

TemplatePresenter::TemplatePresenter(TemplateView& v)
    : view(v)
{
}

void TemplatePresenter::activate()
{
	view.setCount(0);
}

void TemplatePresenter::deactivate()
{
	
}

bool TemplatePresenter::isBtnClicked()
{
	return model->btnClicked;
}
#include <stdio.h>

void TemplatePresenter::inc()
{
	model->acc = model->acc + 0.1f;
	model->acc = model->acc > 100 ? 100 : model->acc;
}

void TemplatePresenter::dec()
{
	model->acc = model->acc - 0.1f;
	model->acc = model->acc < 0 ? 0 : model->acc;
}

void TemplatePresenter::reset()
{
	model->acc = 0;
	view.setCount(0);
}

float TemplatePresenter::getAcc()
{
	return model->acc;
}

void TemplatePresenter::setAcc(float value)
{
	model->acc = value;
}

void TemplatePresenter::toggle()
{
	model->btnClicked = !model->btnClicked;
}

void TemplatePresenter::pulse()
{
#ifndef SIMULATOR
	model->generatePulsePWM();
#endif
}

void TemplatePresenter::goToFirstScreen()
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotoFirstScreen();
}

void TemplatePresenter::goToSlideScreen()
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotoSlideScreen();
}