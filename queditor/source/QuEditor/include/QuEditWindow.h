//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUEDITWINDOW_H
#define QUEDITWINDOW_H



#include <FL/Fl_Double_Window.h>
#include <FL/Fl_Input.h>
#include <FL/Fl_Button.h>
#include <FL/Fl_Return_Button.h>
#include <FL/Fl_Text_Buffer.h>
#include <FL/Fl_Text_Editor.h>
#include <common.h>


class QuEditWindow : public Fl_Double_Window
{
    public:
        QuEditWindow(int x, int y, int w, int h, const char *l = 0);
        virtual ~QuEditWindow();

        Fl_Text_Buffer *m_buffer;
        Fl_Text_Editor *m_editor;

        int			wrap_mode;
        int			line_numbers;

    Fl_Window          *replace_dlg;
    Fl_Input           *replace_find;
    Fl_Input           *replace_with;
    Fl_Button          *replace_all;
    Fl_Return_Button   *replace_next;
    Fl_Button          *replace_cancel;

        char               search[256];

    protected:
        int create();
        int destroy();

    private:
};

#endif // QUEDITWINDOW_H
