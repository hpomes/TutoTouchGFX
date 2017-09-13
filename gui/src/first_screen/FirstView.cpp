#include <gui/first_screen/FirstView.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>


void FirstView::setupScreen()
{
	background2.setPosition(0, 0, HAL::DISPLAY_WIDTH, HAL::DISPLAY_HEIGHT);
	background2.setColor(Color::getColorFrom24BitRGB(0xFF, 0x00, 0xFF));
	add(background2);
}

void FirstView::tearDownScreen()
{

}