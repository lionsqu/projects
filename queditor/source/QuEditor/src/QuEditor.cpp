//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuEditor.h"


int Qu_changed = 0;
int Qu_loading = 0;
int Qu_errno = 0;
char Qu_filename[256] = "";
char Qu_title[256] = "";


Fl_Menu_Item Qu_menuitems[] =
{
    { "&File",              0, 0, 0, FL_SUBMENU },
    { "&New File",        0, (Fl_Callback *)new_cb },
    { "&Open File...",    FL_COMMAND + 'o', (Fl_Callback *)open_cb },
    { "&Insert File...",  FL_COMMAND + 'i', (Fl_Callback *)insert_cb, 0, FL_MENU_DIVIDER },
    { "&Save File",       FL_COMMAND + 's', (Fl_Callback *)save_cb },
    { "Save File &As...", FL_COMMAND + FL_SHIFT + 's', (Fl_Callback *)saveas_cb, 0, FL_MENU_DIVIDER },
    { "New &View", FL_ALT + 'v', (Fl_Callback *)view_cb, 0 },
    { "&Close View", FL_COMMAND + 'w', (Fl_Callback *)close_cb, 0, FL_MENU_DIVIDER },
    { "E&xit", FL_COMMAND + 'q', (Fl_Callback *)quit_cb, 0 },
    { 0 },
    { "&Edit", 0, 0, 0, FL_SUBMENU },
    { "&Undo",       FL_COMMAND + 'z', (Fl_Callback *)undo_cb, 0, FL_MENU_DIVIDER },
    { "Cu&t",        FL_COMMAND + 'x', (Fl_Callback *)cut_cb },
    { "&Copy",       FL_COMMAND + 'c', (Fl_Callback *)copy_cb },
    { "&Paste",      FL_COMMAND + 'v', (Fl_Callback *)paste_cb },
    { "&Delete",     0, (Fl_Callback *)delete_cb },
    { 0 },
    { "&Search", 0, 0, 0, FL_SUBMENU },
    { "&Find...",       FL_COMMAND + 'f', (Fl_Callback *)find_cb },
    { "F&ind Again",    FL_COMMAND + 'g', find2_cb },
    { "&Replace...",    FL_COMMAND + 'r', replace_cb },
    { "Re&place Again", FL_COMMAND + 't', replace2_cb },
    { 0 },
    { 0 }
};


void new_cb(Fl_Widget*, void*)
{

}

void open_cb(Fl_Widget*, void*)
{

}

void insert_cb(Fl_Widget*, void*)
{

}

void save_cb(void)
{

}

void saveas_cb(void)
{

}

void view_cb(Fl_Widget*, void*)
{

}

void close_cb(Fl_Widget*, void*)
{

}

void quit_cb(Fl_Widget*, void*)
{
    if(Qu_changed && !check_save())
        return;
    exit(0);
}


void undo_cb(Fl_Widget*, void*)
{

}

void cut_cb(Fl_Widget*, void*)
{

}

void copy_cb(Fl_Widget*, void*)
{

}

void paste_cb(Fl_Widget*, void*)
{

}

void delete_cb(Fl_Widget*, void*)
{

}


void find_cb(Fl_Widget*, void*)
{

}

void find2_cb(Fl_Widget*, void*)
{

}

void replace_cb(Fl_Widget*, void*)
{

}

void replace2_cb(Fl_Widget*, void*)
{

}



int check_save(void)
{
    if(!Qu_changed)return 1;
    int r = fl_choice("The current file has not been saved.\n"
                      "Would you like to save it now?",
                      "Cancel", "Save", "Discard");
    if(r == 1)
    {
        save_cb();
        return !Qu_changed;
    }
    return (r == 2) ? 1 : 0;
}



QuEditor::QuEditor()
{
    //ctor
}

QuEditor::~QuEditor()
{
    //dtor
    delete m_window;
}

int QuEditor::create()
{
    m_window = new QuEditorWindow(640, 480, "QuEditor");
    m_window->createMenu(Qu_menuitems);
    m_window->resizable(m_window);
    return 0;
}

int QuEditor::show(int& argc, char**& argv)
{
    m_window->end();
    m_window->show(argc, argv);
    return 0;
}

int QuEditor::run()
{
    return Fl::run();
}
