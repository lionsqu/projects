//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuCallBack.h"

Fl_Menu_Item menuitems[] =
{
    { "&File",              0, 0, 0, FL_SUBMENU },
    { "&New File",        0, (Fl_Callback *)new_cb },
    { "&Open File...",    FL_COMMAND + 'o', (Fl_Callback *)open_cb },
    { "&Insert File...",  FL_COMMAND + 'i', (Fl_Callback *)insert_cb, 0, FL_MENU_DIVIDER },
    { "&Save File",       FL_COMMAND + 's', (Fl_Callback *)save_cb },
    { "Save File &As...", FL_COMMAND + FL_SHIFT + 's', (Fl_Callback *)saveas_cb, 0, FL_MENU_DIVIDER },
    {
        "New &View",        FL_ALT
#ifdef __APPLE__
        + FL_COMMAND
#endif
        + 'v', (Fl_Callback *)view_cb, 0
    },
    { "&Close View",      FL_COMMAND + 'w', (Fl_Callback *)close_cb, 0, FL_MENU_DIVIDER },
    { "E&xit",            FL_COMMAND + 'q', (Fl_Callback *)quit_cb, 0 },
    { 0 },

    { "&Edit", 0, 0, 0, FL_SUBMENU },
    { "Cu&t",             FL_COMMAND + 'x', (Fl_Callback *)cut_cb },
    { "&Copy",            FL_COMMAND + 'c', (Fl_Callback *)copy_cb },
    { "&Paste",           FL_COMMAND + 'v', (Fl_Callback *)paste_cb },
    { "&Delete",          0, (Fl_Callback *)delete_cb },
    { "Preferences",      0, 0, 0, FL_SUBMENU },
    { "Line Numbers",   FL_COMMAND + 'l', (Fl_Callback *)linenumbers_cb, 0, FL_MENU_TOGGLE },
    { "Word Wrap",      0,                (Fl_Callback *)wordwrap_cb, 0, FL_MENU_TOGGLE },
    { 0 },
    { 0 },

    { "&Search", 0, 0, 0, FL_SUBMENU },
    { "&Find...",         FL_COMMAND + 'f', (Fl_Callback *)find_cb },
    { "F&ind Again",      FL_COMMAND + 'g', find2_cb },
    { "&Replace...",      FL_COMMAND + 'r', replace_cb },
    { "Re&place Again",   FL_COMMAND + 't', replace2_cb },
    { 0 },

    { 0 }
};




//style
void style_unfinished_cb(int, void*)
{
}

//Editor
void save_cb()
{
}

void saveas_cb()
{
}

void find_cb(Fl_Widget* w, void* v)
{
}

void find2_cb(Fl_Widget*, void*)
{
}

void replace_cb(Fl_Widget*, void* v)
{
}

void replall_cb(Fl_Widget*, void*)
{

}

void replace2_cb(Fl_Widget*, void*)
{
}

void replcan_cb(Fl_Widget*, void*)
{
}

int check_save(void)
{
}

void load_file(const char *newfile, int ipos)
{
}

void save_file(const char *newfile)
{
}

void set_title(Fl_Window* w)
{
}

void copy_cb(Fl_Widget*, void* v)
{
}

void cut_cb(Fl_Widget*, void* v)
{
}

void delete_cb(Fl_Widget*, void*)
{
}

void linenumbers_cb(Fl_Widget *w, void* v)
{
}

void wordwrap_cb(Fl_Widget *w, void* v)
{
}

void changed_cb(int, int nInserted, int nDeleted,int, const char*, void* v)
{
}

void new_cb(Fl_Widget*, void*)
{

}

void open_cb(Fl_Widget*, void*)
{
}

void insert_cb(Fl_Widget*, void *v)
{
}

void paste_cb(Fl_Widget*, void* v)
{
}

void close_cb(Fl_Widget*, void* v)
{
}

void quit_cb(Fl_Widget*, void*)
{
}

void view_cb(Fl_Widget*, void*)
{

}
