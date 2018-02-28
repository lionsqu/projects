//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuCoreKeg.h"

QuCoreKeg::QuCoreKeg()
{
    //ctor
}

QuCoreKeg::~QuCoreKeg()
{
    //dtor
}

int QuCoreKeg::insert(QuObject *obj)
{
    m_keg.insert(std::make_pair(obj->m_title, obj));

    return(0);
}

int QuCoreKeg::remove(QuObject *obj)
{
    for(QuHashmap::iterator it = m_keg.begin(); it != m_keg.end(); ++it)
    {
        if(it->second == obj)m_keg.erase(it);
    }
    return(0);
}

int QuCoreKeg::remove(std::string key)
{
    for(QuHashmap::iterator it = m_keg.begin(); it != m_keg.end(); ++it)
    {
        QuObject *obj = it->second;
        if(obj->m_title == key)
            m_keg.erase(it);
    }
    return(0);
}
