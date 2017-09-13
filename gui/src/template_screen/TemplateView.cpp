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
#include <gui/template_screen/TemplateView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>

void TemplateView::setupScreen()
{	
	
	background2.setPosition(0, 0, HAL::DISPLAY_WIDTH, HAL::DISPLAY_HEIGHT);
	background2.setColor(Color::getColorFrom24BitRGB(0xFF, 0xFF, 0xFF));

	goFirst.setXY(200, 120);
	goFirst.setAction(clickedBtnCb);
	goFirst.setBitmaps(Bitmap(BITMAP_GO_LEFT_ID), Bitmap(BITMAP_GO_RIGHT_ID));

	goSlide.setXY(400, 120);
	goSlide.setAction(clickedBtnCb);
	goSlide.setBitmaps(Bitmap(BITMAP_GO_RIGHT_ID), Bitmap(BITMAP_GO_LEFT_ID));

	btn.setXY(400, 240);
	btn.setAction(clickedBtnCb);
	btn.setBitmaps(Bitmap(BITMAP_ADD_ID), Bitmap(BITMAP_ADD_PRESSED_ID));
	
	//Unicode::snprintf(countTxtbuf, 3, "%3d", 0);
	reset.setXY(200, 240);
	reset.setAction(clickedBtnCb);
	reset.setBitmaps(Bitmap(BITMAP_SUB_ID), Bitmap(BITMAP_SUB_PRESSED_ID));

	setCount(0);
	count.setWildcard(countTxtbuf);
	count.setTypedText(TypedText(T_COUNT));
	count.setXY(300, 240);
	count.setColor(Color::getColorFrom24BitRGB(0xFF, 0x00, 0x00));
	
	add(background2);
	add(goFirst);
	add(goSlide);
	add(reset);
	add(btn);
	add(count);
	
}

void TemplateView::clickedBtn(const AbstractButton &source)
{
	if (&source == &btn)
	{
		presenter->inc();
		setCount(presenter->getAcc());
		if (!presenter->isBtnClicked())
		{
			btn.setBitmaps(Bitmap(BITMAP_ADD_PRESSED_ID), Bitmap(BITMAP_ADD_ID));
			background2.setColor(Color::getColorFrom24BitRGB(0x00, 0x00, 0x00));
		}
		else
		{
			btn.setBitmaps(Bitmap(BITMAP_ADD_ID), Bitmap(BITMAP_ADD_PRESSED_ID));
			background2.setColor(Color::getColorFrom24BitRGB(0xFF, 0xFF, 0xFF));
		}
		background2.invalidate();
		presenter->toggle();
	}
	else if (&source == &reset)
		presenter->reset();
	else if (&source == &goFirst)
		presenter->goToFirstScreen();
	else if (&source == &goSlide)
		presenter->goToSlideScreen();
	
}

void TemplateView::setCount(int value)
{
	Unicode::snprintf(countTxtbuf, 3, "%d", value);
	count.invalidate();
}

void TemplateView::tearDownScreen()
{

}
