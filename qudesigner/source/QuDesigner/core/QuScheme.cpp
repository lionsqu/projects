//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuScheme.h"


#include <QuLayer.h>
#include <QuClass.h>



QuScheme::QuScheme()
{
    //ctor
}

QuScheme::~QuScheme()
{
    //dtor
}

int QuScheme::create()
{
    QuObject *lay = NULL;
    QuObject *obj = NULL;

    lay = new QuLayer("start");
    m_data.push_back(lay);
    obj = new QuClass("QuStarter");
    lay->m_children.push_back(obj);

    lay = new QuLayer("data");
    m_data.push_back(lay);
    obj = new QuClass("QuObject");
    lay->m_children.push_back(obj);
    obj = new QuClass("QuCommon");
    lay->m_children.push_back(obj);

    lay = new QuLayer("store");
    m_data.push_back(lay);
    obj = new QuClass("QuStore");
    lay->m_children.push_back(obj);
    obj = new QuClass("QuXmlFile");
    lay->m_children.push_back(obj);
    obj = new QuClass("QuBinFile");
    lay->m_children.push_back(obj);

    lay = new QuLayer("core");
    m_data.push_back(lay);
    obj = new QuClass("QuCore");
    lay->m_children.push_back(obj);
    obj = new QuClass("QuCallback");
    lay->m_children.push_back(obj);
    obj = new QuClass("QuCoreKeg");
    lay->m_children.push_back(obj);

    lay = new QuLayer("view");
    m_data.push_back(lay);
    obj = new QuClass("QuView");
    lay->m_children.push_back(obj);
    obj = new QuClass("QuWindow");
    lay->m_children.push_back(obj);
    obj = new QuClass("QuWidget");
    lay->m_children.push_back(obj);

    obj = new QuClass("main");
    m_data.push_back(obj);
}
