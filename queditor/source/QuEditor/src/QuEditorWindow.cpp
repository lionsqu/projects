//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuEditorWindow.h"

QuEditorWindow::QuEditorWindow(int w, int h, const char *l):
    Fl_Double_Window(w, h, l),
    m_menubar(0)
{
    //ctor
}

QuEditorWindow::~QuEditorWindow()
{
    //dtor
    if(m_menubar)delete m_menubar;
}

int QuEditorWindow::createMenu(Fl_Menu_Item menuitems[])
{
    m_menubar = new Fl_Menu_Bar(0, 0, 640, 30);
    m_menubar->copy(menuitems);
    return 0;
}
