#ifndef QUSCROLL_H
#define QUSCROLL_H

#include <FL/Fl_Scroll.h>
#include <QuCanvas.h>



class QuScroll : public Fl_Scroll
{
    public:
        QuScroll(int x,int y,int w,int h,const char*l=0);
        virtual ~QuScroll();
    protected:
    private:
        QuCanvas *canvas;
};

#endif // QUSCROLL_H
