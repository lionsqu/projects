//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUCOREKEG_H
#define QUCOREKEG_H


#include <QuCommon.h>


class QuCoreKeg
{
    public:
        QuCoreKeg();
        virtual ~QuCoreKeg();

        int insert(QuObject *obj);
        int remove(QuObject *obj);
        int remove(std::string key);

    protected:
    private:

    public:
        //QuHashmap   m_keg;
        QuList          m_keg;
};

#endif // QUCOREKEG_H
