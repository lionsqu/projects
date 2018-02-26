//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuStarter.h"


#include <QuStore.h>
#include <QuLogic.h>
#include <QuView.h>
#include <QuCore.h>



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
    /*
    QuStoreKeg store;
    QuLogicKeg logic;
    QuView view;

    view.Create();

    store.run();
    logic.run();
    view.run();
    */

    QuStore store;
    QuLogic logic(&store);
    QuView view(&logic);

    view.Create();
    //view.show();
    view.run();


    return 0;
}
