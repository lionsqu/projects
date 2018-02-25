//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUEDITVIEW_H
#define QUEDITVIEW_H


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>


#include <FL/Fl.h>
#include <FL/Fl_Menu_Bar.h>

#include <common.h>
#include <QuCallBack.h>
#include <QuEditWindow.h>




class QuEditView
{
    public:
        QuEditView();
        virtual ~QuEditView();

        int create();
        int destroy();

        int show(int argc, char** argv);
        int run();


        Fl_Menu_Bar     *m_menubar;
        QuEditWindow    *m_editwindow;

    protected:
    private:
};

#endif // QUEDITVIEW_H
