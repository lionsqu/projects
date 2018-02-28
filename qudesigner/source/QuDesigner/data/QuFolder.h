//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUFOLDER_H
#define QUFOLDER_H

#include <QuObject.h>


class QuFolder : public QuObject
{
    public:
        QuFolder(std::string title);
        virtual ~QuFolder();
    protected:
    private:
};

#endif // QUFOLDER_H
