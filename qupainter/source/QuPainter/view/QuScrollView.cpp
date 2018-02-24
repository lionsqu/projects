#include "QuScrollView.h"

QuScrollView::QuScrollView(int x, int y, int w, int h, const char*l):
    Fl_Scroll(x, y, w, h, l)
{
    //ctor
    m_canvas = new QuCanvas(0, 0, 2000, 2000, l);
}

QuScrollView::~QuScrollView()
{
    //dtor
}

int QuScrollView::handle(int event)
{
    switch(event)
    {
        case FL_PUSH:
            handle_push(event);
            break;
        default:
            break;
    }

    return Fl_Scroll::handle(event);
}

int QuScrollView::handle_push(int event)
{
    int button = 0;
    int x = 0;
    int y = 0;

    button = Fl::event_button();

    switch(button)
    {
        case FL_LEFT_MOUSE:
            break;
        case FL_RIGHT_MOUSE:
            break;
        default:
            break;
    }
    return 0;
}

void QuScrollView::draw()
{
    //fl_push_clip(100, 100, 400, 400);
    //Fl_Widget::window();

    //fl_arc(100, 100, 100, 0, 180);
    //(0, 0, 100, 100);



    //fl_draw_box(FL_FLAT_BOX, 0, 0, 10, 10, 1);

    Fl_Scroll::draw();
    //m_canvas->draw();
}

void QuScrollView::redraw()
{
    //fl_line(0, 0, 100, 100);
}
