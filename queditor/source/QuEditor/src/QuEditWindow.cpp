//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuEditWindow.h"
#include <QuCallBack.h>


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
    m_buffer = new Fl_Text_Buffer();
    m_editor = new Fl_Text_Editor(0, 30, w(), h());
    m_editor->textfont(FL_COURIER);
    m_editor->textsize(TS);
    m_editor->buffer(m_buffer);
    m_buffer->add_modify_callback(changed_cb, this);
    this->resizable(m_editor);


    replace_dlg = new Fl_Window(300, 105, "Replace");
    replace_find = new Fl_Input(80, 10, 210, 25, "Find:");
    replace_find->align(FL_ALIGN_LEFT);

    replace_with = new Fl_Input(80, 40, 210, 25, "Replace:");
    replace_with->align(FL_ALIGN_LEFT);

    replace_all = new Fl_Button(10, 70, 90, 25, "Replace All");
    replace_all->callback((Fl_Callback *)replall_cb, this);

    replace_next = new Fl_Return_Button(105, 70, 120, 25, "Replace Next");
    replace_next->callback((Fl_Callback *)replace2_cb, this);

    replace_cancel = new Fl_Button(230, 70, 60, 25, "Cancel");
    replace_cancel->callback((Fl_Callback *)replcan_cb, this);
    replace_dlg->end();
    replace_dlg->set_non_modal();

    *search = (char)0;
    wrap_mode = 0;
    line_numbers = 0;
}

int QuEditWindow::destroy()
{
    delete m_editor;
    delete m_buffer;

    delete replace_dlg;
}
