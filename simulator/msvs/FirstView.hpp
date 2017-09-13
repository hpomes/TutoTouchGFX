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
#ifndef FIRST_VIEW_HPP
#define FIRST_VIEW_HPP

#include <mvp/View.hpp>
#include <gui/first_screen/FirstPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/Color.hpp>

using namespace touchgfx;

/**
* The View for a First screen. In the MVP paradigm, the view is a
* passive interface that only displays the user interface and routes
* any events from the user interface to the presenter. Normally it is the
* responsibility of the presenter to act upon those events.
*
* By deriving from View, this class has a presenter pointer, which is configured
* automatically.
*/
class FirstView : public View<FirstPresenter>
{
public:
	
	FirstView()
	{
	}

	virtual ~FirstView() { }
	virtual void setupScreen();
	/*
	{
		background2.setPosition(0, 0, HAL::DISPLAY_WIDTH, HAL::DISPLAY_HEIGHT);
		background2.setColor(Color::getColorFrom24BitRGB(0xFF, 0x00, 0xFF));
		add(background2);
	}
	*/
	virtual void tearDownScreen();

private:
	Box background2;
};

#endif // FIRST_VIEW_HPP
