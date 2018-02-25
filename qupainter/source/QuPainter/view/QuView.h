//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUVIEW_H
#define QUVIEW_H


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu.h>
#include <FL/Fl_Menu_Bar.h>
#include <FL/Fl_Scroll.h>
#include <FL/Fl_Scrollbar.h>
#include <FL/Fl_Tabs.h>
//#include <FL/Fl_Browser.h>

#include <QuScrollView.h>
#include <QuTabsView.h>



extern Fl_Menu_Item Qu_menuitems[];



extern void new_cb(Fl_Widget*, void*);
extern void open_cb(Fl_Widget*, void*);
extern void insert_cb(Fl_Widget*, void*);
extern void save_cb(void);
extern void saveas_cb(void);
extern void view_cb(Fl_Widget*, void*);
extern void close_cb(Fl_Widget*, void*);
extern void quit_cb(Fl_Widget*, void*);

extern void undo_cb(Fl_Widget*, void*);
extern void cut_cb(Fl_Widget*, void*);
extern void copy_cb(Fl_Widget*, void*);
extern void paste_cb(Fl_Widget*, void*);
extern void delete_cb(Fl_Widget*, void*);

extern void find_cb(Fl_Widget*, void*);
extern void find2_cb(Fl_Widget*, void*);
extern void replace_cb(Fl_Widget*, void*);
extern void replace2_cb(Fl_Widget*, void*);



class QuView
{
    public:
        QuView();
        virtual ~QuView();

    public:
        int Create();
        int Destroy();

        int run();

    protected:
        int CreateWindow();
        int CreateMenuBar();
        int CreateToolsBar();
        int CreateMain();
        int CreateTabs();
        int CreateStatusBar();

        int DestroyWindow();
        int DestroyMenuBar();
        int DestroyToolsBar();
        int DestroyMain();
        int DestroyTabs();
        int DestroyStatusBar();

    private:
        Fl_Window *m_window;
        Fl_Menu_Bar *m_menubar;

        QuTabsView *m_tabs;
        Fl_Group *m_group;
        //Fl_Browser *m_browser;
        Fl_Scroll *m_list;
        Fl_Scroll *m_scroll;


        //Fl_Scrollbar *m_horizontalbar;
        //Fl_Scrollbar *m_verticalbar;
};

#endif // QUVIEW_H
