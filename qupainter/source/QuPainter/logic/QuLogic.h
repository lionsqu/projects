//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QULOGIC_H
#define QULOGIC_H



#include <QuLogicKeg.h>
#include <QuStore.h>



class QuLogic
{
    public:
        QuLogic(QuStore *store);
        virtual ~QuLogic();


        int addline(int x1, int y1, int x2, int y2);

    protected:
    private:
        QuLogicKeg * m_keg;
        QuStore *m_store;
};

#endif // QULOGIC_H
