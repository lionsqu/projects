//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuScrollView.h"

QuScrollView::QuScrollView(int x, int y, int w, int h, const char*l):
    Fl_Scroll(x, y, w, h, l)
{
    //ctor
    m_canvas = new QuCanvas(0, 0, 2000, 2000, l);
}

QuScrollView::QuScrollView(QuView *view, int x, int y, int w, int h):
    Fl_Scroll(x, y, w, h),
    m_view(view)
{
    m_logic = m_view->m_logic;
    m_canvas = new QuCanvas(0, 0, 2000, 2000);
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
    //test
    static int x = 0;
    static int y = 0;
    int x2 = 0;
    int y2 = 0;

    button = Fl::event_button();

    switch(button)
    {
        case FL_LEFT_MOUSE:
            x2 = Fl::event_x();
            y2 = Fl::event_y();

            //m_logic->addline(100, 100, 300, 100);
            m_logic->addline(x, y, x2, y2);
            x = x2;
            y = y2;
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

    //fl_line(0, 0, 1000, 1000);
}

void QuScrollView::redraw()
{
    //fl_line(0, 0, 100, 100);
}
