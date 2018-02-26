//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuCanvas.h"

QuCanvas::QuCanvas(int x, int y, int w, int h, const char* l):
    Fl_Widget(x, y, w, h, l)
{
    //ctor
}

QuCanvas::~QuCanvas()
{
    //dtor
}

void QuCanvas::draw()
{
    fl_color(color());
    //fl_rectf(x(),y(),w(),h());

    fl_color(FL_BLACK);

    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    x1 = 0;
    y1 = 0;
    x2 = 1999;
    y2 = 1999;

    x3 = x1 + x();
    y3 = y1 + y();

    x4 = x2 + x();
    y4 = x2 + y();

    fl_line(x3, y3, x4, y4);

    fl_line(convertx(100), converty(100), convertx(400), converty(100));
}

int QuCanvas::convertx(int X)
{
    return (X + x());
}

int QuCanvas::converty(int Y)
{
    return (Y + y());
}
