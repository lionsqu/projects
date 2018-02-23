//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUEDITORWINDOW_H
#define QUEDITORWINDOW_H


#include <FL/Fl.h>
#include <FL/Fl_Double_Window.h>
#include <FL/Fl_Menu_Bar.h>



class QuEditorWindow : public Fl_Double_Window
{
    public:
        QuEditorWindow(int w, int h, const char *l = 0);
        virtual ~QuEditorWindow();

        int createMenu(Fl_Menu_Item[]);

    protected:
        Fl_Menu_Bar     *m_menubar;

    private:
};

#endif // QUEDITORWINDOW_H
