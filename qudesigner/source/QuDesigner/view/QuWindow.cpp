//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuWindow.h"






QuWindow::QuWindow(class QuView *view, int w, int h, const char *l) :
    Fl_Double_Window(0, 0, w, h, l),
    m_view(view)
{
    //ctor
    create();
}

QuWindow::~QuWindow()
{
    //dtor
}

int QuWindow::create()
{
    m_bar = new Fl_Menu_Bar(0, 0, w(), 30);
    m_bar->copy(menuitems, this);

    m_tree = new QuTree(m_view, 300, h());

    m_group = new Fl_Group(300, 30, w()-300, h());
    this->resizable(m_group);
}

void QuWindow::draw()
{
    Fl_Double_Window::draw();

    //

}

int QuWindow::update()
{
    m_tree->update();
}
