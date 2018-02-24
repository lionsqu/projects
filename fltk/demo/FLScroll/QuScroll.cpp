#include "QuScroll.h"

QuScroll::QuScroll(int x,int y,int w,int h,const char*l):
    Fl_Scroll(x, y, w, h, l)
{
    //ctor
    canvas = new QuCanvas(0, 0, 2000, 2000);
}

QuScroll::~QuScroll()
{
    //dtor
}
