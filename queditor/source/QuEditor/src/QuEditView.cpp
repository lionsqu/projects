//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuEditView.h"

QuEditView::QuEditView()
{
    //ctor
}

QuEditView::~QuEditView()
{
    //dtor
    destroy();
}

int QuEditView::create()
{
    m_editwindow = new QuEditWindow(0, 30, 640, 480, "QuEditor");

    m_menubar = new Fl_Menu_Bar(0, 0, m_editwindow->w(), 30);
    m_menubar->copy(menuitems, m_editwindow);

    //m_editwindow->create();

    editwindow = m_editwindow;
}

int QuEditView::destroy()
{
    delete m_editwindow;
}

int QuEditView::show(int argc, char** argv)
{
    m_editwindow->end ();
    m_editwindow->show (argc, argv);
}

int QuEditView::run()
{
    return(Fl::run());
}
