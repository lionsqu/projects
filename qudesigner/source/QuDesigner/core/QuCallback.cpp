//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuCallback.h"

#include <QuWindow.h>
#include <QuView.h>
#include <QuCore.h>



Fl_Menu_Item menuitems[] =
{
    {"File",            0,              0,              0,              FL_SUBMENU},
    {"New",            0,              (Fl_Callback*)QuCallback::new_cb},
    {"Open...",            0,              (Fl_Callback*)QuCallback::open_cb},
    {"Close",            0,              (Fl_Callback*)QuCallback::close_cb,         0,      FL_MENU_DIVIDER},
    {"Save",            0,              (Fl_Callback*)QuCallback::save_cb},
    {"Save as...",            0,              (Fl_Callback*)QuCallback::saveas_cb,         0,      FL_MENU_DIVIDER},
    {"Write to...",            0,              (Fl_Callback*)QuCallback::writeto_cb,         0,      FL_MENU_DIVIDER},
    {"Exit",            0,              (Fl_Callback*)QuCallback::quit_cb},
    {0}
};


Fl_Menu_Item popupitems[] =
{
    {"Add",            0,              0,              0,              FL_SUBMENU},
    {"Function",            0,              (Fl_Callback*)QuCallback::addfunc_cb},
    {"Class",            0,              (Fl_Callback*)QuCallback::addclass_cb},
    {0},
    {"Delete",            0,              (Fl_Callback*)QuCallback::delete_cb},
    {0}
};



//QuCore *QuCallback::m_core = 0;



QuCallback::QuCallback(QuCore *core)
{
    //ctor
}

QuCallback::~QuCallback()
{
    //dtor
}

void QuCallback::new_cb(Fl_Widget*w, void*v)
{
    QuWindow *win = (QuWindow*)v;
    QuCore *core = win->m_view->m_core;
    core->create();
}

void QuCallback::open_cb(Fl_Widget*w, void*v)
{

}

void QuCallback::close_cb(Fl_Widget*w, void*v)
{

}

void QuCallback::save_cb(Fl_Widget*w, void*v)
{

}

void QuCallback::saveas_cb(Fl_Widget*w, void*v)
{

}

void QuCallback::writeto_cb(Fl_Widget*w, void*v)
{

}

void QuCallback::quit_cb(Fl_Widget*w, void*v)
{
    QuWindow *win = (QuWindow*)v;
    QuCore *core = win->m_view->m_core;
    core->quit();
}

void QuCallback::popup_cb()
{

}

void QuCallback::addfunc_cb()
{

}

void QuCallback::addclass_cb()
{

}

void QuCallback::delete_cb()
{

}
