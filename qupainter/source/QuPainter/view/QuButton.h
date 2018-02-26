//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUBUTTON_H
#define QUBUTTON_H

#include <FL/Fl_Button.h>


class QuButton : public Fl_Button
{
    public:
        QuButton(int x, int y, int w, int h, const char *l = 0);
        virtual ~QuButton();

        int handle(int event);
        void draw();

    protected:
    private:
};

#endif // QUBUTTON_H
