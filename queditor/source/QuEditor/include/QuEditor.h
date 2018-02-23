//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUEDITOR_H
#define QUEDITOR_H


#include <QuEditorWindow.h>
#include <FL/Fl_Menu.h>
#include <FL/Fl_Text_Buffer.h>
#include <FL/fl_ask.h>


extern Fl_Menu_Item Qu_menuitems[];
extern Fl_Text_Buffer *Qu_textbuff;
extern int Qu_changed;
extern int Qu_loading;
extern int Qu_errno;
extern char Qu_filename[256];
extern char Qu_title[256];


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



extern int check_save(void);




class QuEditor
{
    public:
        QuEditor();
        virtual ~QuEditor();

        int create();
        int show(int& argc, char**& argv);
        int run();

    protected:
        QuEditorWindow  *m_window;

    private:
};

#endif // QUEDITOR_H
