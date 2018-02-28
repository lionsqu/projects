//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUVIEW_H
#define QUVIEW_H


#include <FL/Fl.h>
#include <QuCore.h>
#include <QuWindow.h>



class QuView
{
    public:
        QuView(class QuCore *core);
        virtual ~QuView();

        class QuCore      *m_core;


        int show();
        int run();

        int update();

    protected:
        int create();

    private:

        class QuWindow    *m_main;
};

#endif // QUVIEW_H
