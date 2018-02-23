//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物和可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuStarter.h"

QuStarter::QuStarter()
{
    //ctor
}

QuStarter::~QuStarter()
{
    //dtor
}

int QuStarter::run()
{

    QuStoreKeg store;
    QuLogicKeg logic;
    QuViewKeg view;

    store.run();
    logic.run();
    view.run();

    return 0;
}
