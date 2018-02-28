//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuCore.h"


#include <stdlib.h>
#include <QuClass.h>
#include <QuLayer.h>


QuCore::QuCore(QuStore *store) :
    m_store(store),
    m_load(1)
{
    //ctor
}

QuCore::~QuCore()
{
    //dtor
}

int QuCore::create()
{
    create_quskeleton();

    m_view->update();
}

int QuCore::run(int argc, char **argv)
{

}

int QuCore::quit()
{
    exit(0);
}

int QuCore::create_quskeleton()
{
    /*
    QuObject *lay = NULL;
    QuObject *obj = NULL;

    lay = new QuLayer("Store");
    m_keg.insert(lay);
    obj = new QuClass("QuStore");
    m_keg.insert(obj);
    obj = new QuClass("QuXmlFile");
    m_keg.insert(obj);
    obj = new QuClass("QuBinFile");
    m_keg.insert(obj);

    lay = new QuLayer("Logic");
    m_keg.insert(lay);
    obj = new QuClass("QuObject");
    m_keg.insert(obj);
    obj = new QuClass("QuCallback");
    m_keg.insert(obj);
    obj = new QuClass("QuCore");
    m_keg.insert(obj);

    lay = new QuLayer("View");
    m_keg.insert(lay);
    obj = new QuClass("QuView");
    m_keg.insert(obj);
    obj = new QuClass("QuWindow");
    m_keg.insert(obj);
    obj = new QuClass("QuWidget");
    m_keg.insert(obj);
    */

    switch(m_load)
    {
        case 1:
            {
                m_sch = new QuScheme();
                m_sch->create();
                m_load = 3;
            }
            break;
        case 2:
            break;
        case 3:
            {
                delete m_sch;
                m_sch = new QuScheme();
                m_sch->create();
                m_load = 3;
            }
            break;
    }

}
