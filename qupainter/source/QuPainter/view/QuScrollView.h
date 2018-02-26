//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUSCROLLVIEW_H
#define QUSCROLLVIEW_H

#include <FL/Fl.h>
#include <FL/Fl_Scroll.h>
#include <FL/x.h>
#include <FL/fl_draw.h>
#include <QuCanvas.h>
#include <QuLogic.h>
#include <QuView.h>



class QuScrollView : public Fl_Scroll
{
    public:
        QuScrollView(int x, int y, int w, int h, const char*l = 0);
        QuScrollView(class QuView *view, int x, int y, int w, int h);
        virtual ~QuScrollView();
    protected:
        int handle(int event);
        void draw();
        void redraw();

    private:
        int handle_push(int event);

        QuCanvas *m_canvas;
        QuView *m_view;
        QuLogic *m_logic;
};

#endif // QUSCROLLVIEW_H
