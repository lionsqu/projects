//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUENTITY_H
#define QUENTITY_H

#include <QuObject.h>


class QuEntity : public QuObject
{
    public:
        QuEntity();
        virtual ~QuEntity();
    protected:
    private:
        int x;
        int y;
        int z;
};

#endif // QUENTITY_H
