//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//

#include "QuEditView.h"


#include <QuCallback.h>



Fl_Menu_Item menuitems[] =
{
    { "&File",              0, 0, 0, FL_SUBMENU },
    { "&New File",        0, (Fl_Callback *)QuCallback::new_cb },
    { "&Open File...",    FL_COMMAND + 'o', (Fl_Callback *)QuCallback::open_cb },
    { "&Insert File...",  FL_COMMAND + 'i', (Fl_Callback *)QuCallback::insert_cb, 0, FL_MENU_DIVIDER },
    { "&Save File",       FL_COMMAND + 's', (Fl_Callback *)QuCallback::save_cb },
    { "Save File &As...", FL_COMMAND + FL_SHIFT + 's', (Fl_Callback *)QuCallback::saveas_cb, 0, FL_MENU_DIVIDER },
    {
        "New &View",        FL_ALT
#ifdef __APPLE__
        + FL_COMMAND
#endif
        + 'v', (Fl_Callback *)QuCallback::view_cb, 0
    },
    { "&Close View",      FL_COMMAND + 'w', (Fl_Callback *)QuCallback::close_cb, 0, FL_MENU_DIVIDER },
    { "E&xit",            FL_COMMAND + 'q', (Fl_Callback *)QuCallback::quit_cb, 0 },
    { 0 },

    { "&Edit", 0, 0, 0, FL_SUBMENU },
    { "Cu&t",             FL_COMMAND + 'x', (Fl_Callback *)QuCallback::cut_cb },
    { "&Copy",            FL_COMMAND + 'c', (Fl_Callback *)QuCallback::copy_cb },
    { "&Paste",           FL_COMMAND + 'v', (Fl_Callback *)QuCallback::paste_cb },
    { "&Delete",          0, (Fl_Callback *)QuCallback::delete_cb },
    { "Preferences",      0, 0, 0, FL_SUBMENU },
    { "Line Numbers",   FL_COMMAND + 'l', (Fl_Callback *)QuCallback::linenumbers_cb, 0, FL_MENU_TOGGLE },
    { "Word Wrap",      0,                (Fl_Callback *)QuCallback::wordwrap_cb, 0, FL_MENU_TOGGLE },
    { 0 },
    { 0 },

    { "&Search", 0, 0, 0, FL_SUBMENU },
    { "&Find...",         FL_COMMAND + 'f', (Fl_Callback *)QuCallback::find_cb },
    { "F&ind Again",      FL_COMMAND + 'g', QuCallback::find2_cb },
    { "&Replace...",      FL_COMMAND + 'r', QuCallback::replace_cb },
    { "Re&place Again",   FL_COMMAND + 't', QuCallback::replace2_cb },
    { 0 },

    { 0 }
};

QuEditView::QuEditView()
{
    //ctor
}

QuEditView::~QuEditView()
{
    //dtor
}

int QuEditView::create()
{
    Fl_Menu_Bar *bar;

    m_window = new QuEditWindow(0, 0, 640, 480, "QuEditor");
    bar = new Fl_Menu_Bar(0, 0, m_window->w(), 30);
    bar->copy(menuitems, m_window);

    m_window->end();

}

int QuEditView::show()
{
    m_window->show();
}
