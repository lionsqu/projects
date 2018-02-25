//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//

#include "QuEditWindow.h"

#include <QuCallback.h>


QuEditWindow::QuEditWindow(int x, int y, int w, int h, const char *l):
    Fl_Double_Window(x, y, w, h, l)
{
    //ctor
    create();
}

QuEditWindow::~QuEditWindow()
{
    //dtor
    destroy();
}

int QuEditWindow::create()
{
    m_editor = new Fl_Text_Editor(0, 30, w(), h()-30);

    m_editor->buffer(QuCallback::m_buffer);
    QuCallback::m_buffer.add_modify_callback(QuCallback::changed_cb, this);

    this->resizable(m_editor);
}

int QuEditWindow::destroy()
{
    delete m_editor;
}
