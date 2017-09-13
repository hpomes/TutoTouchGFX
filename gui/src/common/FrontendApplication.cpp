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
#include <new>
#include <gui/common/FrontendApplication.hpp>
#include <gui/slide_screen/SlideView.hpp>
#include <gui/slide_screen/SlidePresenter.hpp>
#include <mvp/View.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/transitions/NoTransition.hpp>
#include <touchgfx/transitions/SlideTransition.hpp>
#include <gui/template_screen/TemplateView.hpp>
#include <gui/first_screen/FirstView.hpp>
#include <gui/slide_screen/SlideView.hpp>
#include <gui/template_screen/TemplatePresenter.hpp>
#include <gui/first_screen/FirstPresenter.hpp>
#include <gui/slide_screen/SlidePresenter.hpp>
#include <gui/common/FrontendHeap.hpp>

using namespace touchgfx;


FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : touchgfx::MVPApplication(),
      transitionCallback(),
      frontendHeap(heap),
      model(m)
{
}

void FrontendApplication::gotoTemplateScreen()
{
    transitionCallback = touchgfx::Callback< FrontendApplication >(this, &FrontendApplication::gotoTemplateScreenImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotoTemplateScreenImpl()
{
    makeTransition< TemplateView, TemplatePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplication::gotoFirstScreen()
{
	transitionCallback = touchgfx::Callback< FrontendApplication >(this, &FrontendApplication::gotoFirstScreenImpl);
	pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotoFirstScreenImpl()
{
	makeTransition< FirstView, FirstPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplication::gotoSlideScreen()
{ 
    transitionCallback = Callback< FrontendApplication >(this, &FrontendApplication::gotoSlideScreenImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotoSlideScreenImpl()
{
    makeTransition< SlideView, SlidePresenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
