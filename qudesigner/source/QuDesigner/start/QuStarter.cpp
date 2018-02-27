//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuStarter.h"

QuStarter::QuStarter()
{
    //ctor
}

QuStarter::~QuStarter()
{
    //dtor
}

int QuStarter::run(int argc, char **argv)
{
    m_store = new QuStore();
    m_core = new QuCore(m_store);
    m_view = new QuView(m_core);

    m_core->run(argc, argv);
    m_view->show();
    m_view->run();
}
