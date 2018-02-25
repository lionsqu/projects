//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//

#ifndef QUEDITVIEW_H
#define QUEDITVIEW_H


#include <QuEditWindow.h>



class QuEditView
{
    public:
        QuEditView();
        virtual ~QuEditView();

        int create();
        int show();

    protected:
    private:
        QuEditWindow *m_window;
};

#endif // QUEDITVIEW_H
