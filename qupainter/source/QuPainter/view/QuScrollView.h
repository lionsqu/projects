#ifndef QUSCROLLVIEW_H
#define QUSCROLLVIEW_H

#include <FL/Fl.h>
#include <FL/Fl_Scroll.h>
#include <FL/x.h>
#include <FL/fl_draw.h>
#include <QuCanvas.h>



class QuScrollView : public Fl_Scroll
{
    public:
        QuScrollView(int x, int y, int w, int h, const char*l = 0);
        virtual ~QuScrollView();
    protected:
        int handle(int event);
        void draw();
        void redraw();

    private:
        int handle_push(int event);

        QuCanvas *m_canvas;
};

#endif // QUSCROLLVIEW_H
