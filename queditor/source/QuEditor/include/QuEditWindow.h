//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//

#ifndef QUEDITWINDOW_H
#define QUEDITWINDOW_H


#include <FL/Fl.h>
#include <FL/Fl_Double_Window.h>
#include <FL/Fl_Text_Editor.h>



class QuEditWindow : public Fl_Double_Window
{
    public:
        QuEditWindow(int x, int y, int w, int h, const char *l = 0);
        virtual ~QuEditWindow();

        Fl_Text_Editor *m_editor;

    protected:
        int create();
        int destroy();

    private:
};

#endif // QUEDITWINDOW_H
