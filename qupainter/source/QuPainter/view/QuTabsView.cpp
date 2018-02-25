#include "QuTabsView.h"


#include <resources/line.xpm>
#include <FL/Fl_Pixmap.h>
#include <FL/Fl_Box.h>



QuTabsView::QuTabsView(int x,int y,int w,int h,const char *l):
    Fl_Tabs(x, y, w, h, l)
{
    //ctor
}

QuTabsView::~QuTabsView()
{
    //dtor
}

int QuTabsView::create()
{
    m_tab1 = new Fl_Group(0, 60, 200, 480-90, "类");
    this->add(m_tab1);

    Fl_Pixmap *line = new Fl_Pixmap(line_xpm);

    Fl_Box *line_box = new Fl_Box(0,60,32,32);
    line_box->image(line);

    m_tab1->end();

    m_tab2 = new Fl_Group(0, 60, 200, 480-90, "流程");
    this->add(m_tab2);

    m_tab2->end();
}

int QuTabsView::handle(int event)
{
    switch(event)
    {
        case FL_PUSH:
            handle_push(event);
            break;
        default:
            break;
    }

    return Fl_Tabs::handle(event);
}

void QuTabsView::draw()
{
    Fl_Tabs::draw();
}


int QuTabsView::handle_push(int event)
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
