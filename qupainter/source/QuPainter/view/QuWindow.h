//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUWINDOW_H
#define QUWINDOW_H

#include <FL/Fl_Double_Window.h>


class QuWindow : public Fl_Double_Window
{
    public:
        QuWindow(int x, int y, int w, int h, const char *l = 0);
        virtual ~QuWindow();
    protected:
    private:
};

#endif // QUWINDOW_H
