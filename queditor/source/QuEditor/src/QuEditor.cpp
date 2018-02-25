//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//

#include "QuEditor.h"

QuEditor::QuEditor()
{
    //ctor
    create();
}

QuEditor::~QuEditor()
{
    //dtor
    destroy();
}

int QuEditor::show(int argc, char** argv)
{
    m_view->show();
}

int QuEditor::run()
{
    return(Fl::run());
}

int QuEditor::create()
{
    m_view = new QuEditView();
    m_view->create();
}

int QuEditor::destroy()
{
    delete m_view;
}
