//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuCallback.h"

Fl_Menu_Item menuitems[2] =
{
    {"File",            0,              0,              0,              FL_SUBMENU},
    {"Exit",            0,              (Fl_Callback*)QuCallback::quit_cb}
};


Fl_Menu_Item popupitems[2] =
{
    {"File",            0,              0,              0,              FL_SUBMENU},
    {"Exit",            0,              (Fl_Callback*)QuCallback::quit_cb}
};



QuCore *QuCallback::m_core = 0;



QuCallback::QuCallback(QuCore *core)
{
    //ctor
}

QuCallback::~QuCallback()
{
    //dtor
}

void QuCallback::quit_cb()
{
    QuCallback::m_core->quit();
}

void QuCallback::popup_cb()
{
    QuCallback::m_core->quit();
}
