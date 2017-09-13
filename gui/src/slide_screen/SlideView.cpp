#include <gui/slide_screen/SlideView.hpp>
#include <BitmapDatabase.hpp>
#include <touchgfx/Color.hpp>

void SlideView::setupScreen()
{
	background2.setPosition(0, 0, HAL::DISPLAY_WIDTH, HAL::DISPLAY_HEIGHT);
	background2.setColor(Color::getColorFrom24BitRGB(0xFF, 0xFF, 0x00));
	add(background2);
}

void SlideView::tearDownScreen()
{

}
