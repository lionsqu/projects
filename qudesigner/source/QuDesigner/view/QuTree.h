//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUTREE_H
#define QUTREE_H

#include <FL/Fl_Tree.h>
#include <QuView.h>


class QuTree : public Fl_Tree
{
    public:
        QuTree(class QuView *view, int w, int h, const char *l = 0);
        virtual ~QuTree();

        int handle(int event);
        int update();

    protected:
    private:
        QuView      *m_view;
        QuCoreKeg   *m_keg;
};

#endif // QUTREE_H
