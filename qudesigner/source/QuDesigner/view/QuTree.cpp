//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuTree.h"

#include <FL/Fl_Menu_Button.h>


QuTree::QuTree(class QuView *view, int w, int h, const char *l) :
    Fl_Tree(0, 30, w, h, l),
    m_view(view)
{
    //ctor
}

QuTree::~QuTree()
{
    //dtor
}

int QuTree::handle(int event)
{
    switch(event)
    {
        case FL_PUSH:
            {
                Fl_Menu_Button mb(0, 0, 200, 400, "Popup");
                mb.type(Fl_Menu_Button::POPUP3);
                mb.box(FL_NO_BOX);
                mb.menu(popupitems);
                //mb.remove(1);
                //mb.callback((Fl_Callback*)QuCallback::popup_cb);

                const Fl_Menu_Item *item = popupitems->popup(Fl::event_x(), Fl::event_y());
                if(item)item->do_callback(this, item->user_data());
            }
            break;
        default:
            break;
    }
    return Fl_Tree::handle(event);
}
