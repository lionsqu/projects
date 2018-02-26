//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QULINE_H
#define QULINE_H


#include <QuPoint.h>



class QuLine : public QuEntity
{
    public:
        QuLine(int x1, int y1, int x2, int y2);
        virtual ~QuLine();

        class QuPoint m_start;
        class QuPoint m_end;


    protected:
    private:
};

#endif // QULINE_H
