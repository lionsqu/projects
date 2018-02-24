//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuView.h"




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




QuView::QuView()
{
    //ctor
}

QuView::~QuView()
{
    //dtor
}


int QuView::Create()
{
    CreateWindow();
    CreateMenuBar();
    CreateToolsBar();
    //CreateTabs();
    CreateMain();
    //CreateStatusBar();

    return 0;
}

int QuView::Destroy()
{
    DestroyStatusBar();
    DestroyMain();
    DestroyTabs();
    DestroyToolsBar();
    DestroyMenuBar();
    DestroyWindow();

    return 0;
}

int QuView::CreateWindow()
{
    m_window = new Fl_Window (640, 480, "QuPainter");
    m_window->resizable(m_window);
    return 0;
}

int QuView::CreateMenuBar()
{
    m_menubar = new Fl_Menu_Bar(0, 0, 640, 30);
    m_menubar->copy(Qu_menuitems);
    return 0;
}

int QuView::CreateToolsBar()
{
    return 0;
}

int QuView::CreateMain()
{
    /*
    Fl_Box *box;

    box = new Fl_Box (20, 40, 260, 100, "Hello World!");

    box->box (FL_UP_BOX);
    box->labelsize (36);
    box->labelfont (FL_BOLD+FL_ITALIC);
    box->labeltype (FL_SHADOW_LABEL);
    */

    /*
    //m_scroll = new QuScrollView(200, 30, 640-230, 480-60);
    m_scroll = new QuScrollView(0, 0, 640, 480);
    m_scroll->type(Fl_Scroll::BOTH_ALWAYS);

    //m_verticalbar = new Fl_Scrollbar(640-30,30, 30, 480-60);
    //m_horizontalbar = new Fl_Scrollbar(0,480-30, 640-30, 30);
    //m_horizontalbar->type(FL_HORIZONTAL);
    */

    m_tabs = new Fl_Tabs(0, 30, 300, m_window->h() - 60);
    m_group = new Fl_Group(0, 60, m_tabs->w(), m_tabs->h() - 30, "模型");

    m_browser = new Fl_Browser(0, 60, m_tabs->w(), m_group->h());
    m_browser->end();
    m_group->resizable(m_browser);
    m_group->end();
    m_tabs->resizable(m_group);
    m_tabs->end();

    m_scroll = new QuScrollView(300, 30, m_window->w() - 300, m_window->h() - 60);
    m_scroll->type(Fl_Scroll::BOTH_ALWAYS);
    m_window->resizable(m_tabs);
    m_window->resizable(m_scroll);
    m_scroll->end();

    return 0;
}

int QuView::CreateTabs()
{
    m_tabs = new Fl_Tabs(0, 30, 200, 480-60);
    m_browser = new Fl_Browser(0, 30, 100, 480-60, "模型");
    m_browser->end();
    m_tabs->add(m_browser);
    m_tabs->end();
    return 0;
}

int QuView::CreateStatusBar()
{
    return 0;
}

int QuView::DestroyWindow()
{
    return 0;
}

int QuView::DestroyMenuBar()
{
    return 0;
}

int QuView::DestroyToolsBar()
{
    return 0;
}

int QuView::DestroyMain()
{
    return 0;
}

int QuView::DestroyTabs()
{
    return 0;
}

int QuView::DestroyStatusBar()
{
    return 0;
}


int QuView::run()
{
    m_window->end ();
    m_window->show ();

    return Fl::run();
}
