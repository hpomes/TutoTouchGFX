#ifndef SLIDE_PRESENTER_HPP
#define SLIDE_PRESENTER_HPP

#include <mvp/Presenter.hpp>
#include <gui/model/ModelListener.hpp>

using namespace touchgfx;

class SlideView;

class SlidePresenter : public Presenter, public ModelListener
{
public:
    SlidePresenter(SlideView& v);
    virtual void activate();
    virtual void deactivate();
    virtual ~SlidePresenter() {};
private:
    SlidePresenter();

    SlideView& view;
};

#endif
