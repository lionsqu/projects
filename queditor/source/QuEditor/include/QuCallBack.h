//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUCALLBACK_H
#define QUCALLBACK_H


#include <FL/Fl.h>
#include <FL/filename.H>
#include <FL/Fl_Menu_Bar.h>
#include <FL/Fl_Text_Editor.h>
#include <FL/Fl_Native_File_Chooser.H>
#include <common.h>
#include <QuEditWindow.h>
#include <QuStyle.h>



extern QuEditWindow *editwindow;
extern Fl_Menu_Item menuitems[];
extern char filename[FL_PATH_MAX];
extern char title[FL_PATH_MAX];


//style
extern void style_unfinished_cb(int, void*);

//Editor
extern void save_cb();
extern void saveas_cb();
extern void find_cb(Fl_Widget* w, void* v);
extern void find2_cb(Fl_Widget*, void*);
extern void replace_cb(Fl_Widget*, void* v);
extern void replall_cb(Fl_Widget*, void*);
extern void replace2_cb(Fl_Widget*, void*);
extern void replcan_cb(Fl_Widget*, void*);


extern int check_save(void);
extern void load_file(const char *newfile, int ipos);
extern void save_file(const char *newfile);
extern void set_title(Fl_Window* w);


extern void copy_cb(Fl_Widget*, void* v);
extern void cut_cb(Fl_Widget*, void* v);
extern void delete_cb(Fl_Widget*, void*);
extern void linenumbers_cb(Fl_Widget *w, void* v);
extern void wordwrap_cb(Fl_Widget *w, void* v);

extern void changed_cb(int, int nInserted, int nDeleted,int, const char*, void* v);
extern void new_cb(Fl_Widget*, void*);
extern void open_cb(Fl_Widget*, void*);
extern void insert_cb(Fl_Widget*, void *v);
extern void paste_cb(Fl_Widget*, void* v);
extern void close_cb(Fl_Widget*, void* v);
extern void quit_cb(Fl_Widget*, void*);

extern void view_cb(Fl_Widget*, void*);
extern Fl_Window* new_view();




#endif // QUCALLBACK_H
