#ifndef SLIDE_VIEW_HPP
#define SLIDE_VIEW_HPP

#include <mvp/View.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <gui/slide_screen/SlidePresenter.hpp>

using namespace touchgfx;

class SlideView : public View<SlidePresenter>
{
public:
	SlideView() {}
	virtual ~SlideView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

private:
	Box background2;
};

#endif
