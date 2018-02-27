//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUCANVAS_H
#define QUCANVAS_H


#include <FL/fl_draw.h>
#include <FL/Fl_Widget.h>




class QuCanvas : public Fl_Widget
{
    public:
        QuCanvas(int x, int y, int w, int h, const char* l = 0);
        QuCanvas(class QuLogicKeg *keg, int x, int y, int w, int h);

        virtual ~QuCanvas();

        void draw();

    protected:
        int convertx(int x);
        int converty(int y);

    private:
        QuLogicKeg *m_keg;

};

#endif // QUCANVAS_H
