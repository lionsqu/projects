//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuView.h"

QuView::QuView(QuCore *core) :
    m_core(core)
{
    //ctor
    create();
}

QuView::~QuView()
{
    //dtor
}

int QuView::show()
{
    m_main->end();
    m_main->show();
}

int QuView::run()
{
    return(Fl::run());
}

int QuView::create()
{
    m_main = new QuWindow(this, 640, 480, "QuDesigner");
}
