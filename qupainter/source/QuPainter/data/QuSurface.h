//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUSURFACE_H
#define QUSURFACE_H

#include <QuEntity.h>
#include <QuLine.h>



class QuSurface : public QuEntity
{
    public:
        QuSurface();
        virtual ~QuSurface();

        class QuLine m_line1;
        class QuLine m_line2;
        class QuLine m_line3;


    protected:
    private:
};

#endif // QUSURFACE_H
