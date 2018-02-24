#include "QuCanvas.h"

QuCanvas::QuCanvas(int x,int y,int w,int h,const char*l):
    Fl_Widget(x, y, w, h, l)
{
    //ctor
}

QuCanvas::~QuCanvas()
{
    //dtor
}

void QuCanvas::draw()
{
    fl_color(color());
    //fl_rectf(x(),y(),w(),h());

    fl_color(FL_BLACK);

    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    x1 = 0;
    y1 = 0;
    x2 = 1999;
    y2 = 1999;

    x3 = x1 + x();
    y3 = y1 + y();

    x4 = x2 + x();
    y4 = x2 + y();

    fl_line(x3, y3, x4, y4);

}
