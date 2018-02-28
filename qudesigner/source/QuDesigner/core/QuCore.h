//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUCORE_H
#define QUCORE_H

#include <QuStore.h>
#include <QuCoreKeg.h>
#include <QuView.h>
#include <QuScheme.h>



class QuCore
{
    public:
        QuCore(class QuStore *store);
        virtual ~QuCore();

        int create();
        int run(int argc, char **argv);
        int quit();

        class QuView  *m_view;

    protected:
        int create_quskeleton();

    private:
        QuStore      *m_store;

    public:
        QuCoreKeg   m_keg;
        QuScheme    *m_sch;
        int            m_load;
};

#endif // QUCORE_H
