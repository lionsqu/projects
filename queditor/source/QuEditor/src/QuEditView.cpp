//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//

#include "QuEditView.h"


#include <QuCallback.h>




Fl_Menu_Item menuitems[] =
{
    {"&File",       0,       0,       0,       FL_SUBMENU},
    {"&New",        0,  (Fl_Callback*)QuCallback::new_cb},
    {"&Open...",    FL_COMMAND + 'o', (Fl_Callback*)QuCallback::open_cb,    0,  FL_MENU_DIVIDER},

    {"E&xit",        FL_COMMAND + 'q',      (Fl_Callback*)QuCallback::quit_cb,      0},
    {0}
};


QuEditView::QuEditView()
{
    //ctor
}

QuEditView::~QuEditView()
{
    //dtor
}

int QuEditView::create()
{
    Fl_Menu_Bar *bar;

    m_window = new QuEditWindow(0, 0, 640, 480, "QuEditor");
    bar = new Fl_Menu_Bar(0, 0, m_window->w(), 30);
    bar->copy(menuitems, m_window);

    m_window->end();

}

int QuEditView::show()
{
    m_window->show();
}
