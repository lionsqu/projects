#ifndef QUCANVAS_H
#define QUCANVAS_H

#include <FL/Fl_Widget.h>
#include <FL/fl_draw.h>



class QuCanvas : public Fl_Widget
{
    public:
        QuCanvas(int x,int y,int w,int h,const char*l=0);
        virtual ~QuCanvas();

        void draw();

    protected:
    private:
};

#endif // QUCANVAS_H
