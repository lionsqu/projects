//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuTree.h"

#include <FL/Fl_Menu_Button.h>
#include <QuObject.h>




QuTree::QuTree(class QuView *view, int w, int h, const char *l) :
    Fl_Tree(0, 30, w, h, l),
    m_view(view)
{
    //ctor
    m_keg = &(m_view->m_core->m_keg);
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
        click();
    }
    break;
    default:
        break;
    }
    return Fl_Tree::handle(event);
}

int QuTree::popupmenu(int x, int y)
{
    if(this->first_selected_item() == NULL)return 0;

    Fl_Menu_Button mb(0, 0, 200, 400, "Popup");
    mb.type(Fl_Menu_Button::POPUP3);
    mb.box(FL_NO_BOX);
    mb.menu(popupitems);
    //mb.remove(1);
    //mb.callback((Fl_Callback*)QuCallback::popup_cb);

    const Fl_Menu_Item *item = popupitems->popup(x, y);
    if(item)item->do_callback(this, item->user_data());
}

int QuTree::click()
{
    switch(Fl::event_button())
    {
    case FL_LEFT_MOUSE:
    {
    }
    break;
    case FL_MIDDLE_MOUSE:
    {
    }
    break;
    case FL_RIGHT_MOUSE:
    {
        popupmenu(Fl::event_x(), Fl::event_y());
    }
    break;
    }
}

int QuTree::update()
{
    clear();

    QuObject *obj;

    /*
    for(QuHashmap::iterator it = m_keg->m_keg.begin(); it != m_keg->m_keg.end(); ++it)
    {
        obj = it->second;
        this->add(obj->m_title.c_str());
    }


    for(QuList::iterator it=m_keg->m_keg.begin();it!=m_keg->m_keg.end();++it)
    {
        obj = *it;
        this->add(obj->m_title.c_str());
    }
    */

    if(this->m_view->m_core->m_load == 3)
        add(this->root(), &(this->m_view->m_core->m_sch->m_data));

}

int QuTree::add(Fl_Tree_Item* parent, QuList *list)
{
    QuObject *obj;
    Fl_Tree_Item *item;
    for(QuList::iterator it=list->begin(); it!=list->end(); ++it)
    {
        obj = *it;
        if(parent == NULL)
            item = Fl_Tree::add(obj->m_title.c_str());
        else
            item = Fl_Tree::add(parent, obj->m_title.c_str());
        add(item, &(obj->m_children));
    }
}
