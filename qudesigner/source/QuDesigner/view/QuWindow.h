//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUWINDOW_H
#define QUWINDOW_H

#include <FL/Fl_Double_Window.h>
#include <FL/Fl_Menu_Bar.h>
#include <QuView.h>
#include <QuCallback.h>
#include <QuTree.h>
#include <FL/Fl_Group.h>



class QuWindow : public Fl_Double_Window
{
    public:
        QuWindow(class QuView *view, int w, int h, const char *l = 0);
        virtual ~QuWindow();
    protected:
        int create();
    private:
        QuView          *m_view;
        Fl_Menu_Bar     *m_bar;
        class QuTree    *m_tree;
        Fl_Group        *m_group;
};

#endif // QUWINDOW_H
