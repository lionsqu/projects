//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUTABSVIEW_H
#define QUTABSVIEW_H

#include <FL/Fl.h>
#include <FL/Fl_Tabs.h>


class QuTabsView : public Fl_Tabs
{
    public:
        QuTabsView(int x,int y,int w,int h,const char *l = 0);
        virtual ~QuTabsView();

        int create();
        int handle(int event);
        void draw();

    protected:
    private:
        Fl_Group    *m_tab1;
        Fl_Group    *m_tab2;

        int handle_push(int event);
};

#endif // QUTABSVIEW_H
