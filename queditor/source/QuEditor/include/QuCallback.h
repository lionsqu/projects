//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//

#ifndef QUCALLBACK_H
#define QUCALLBACK_H


#include <FL/Fl.h>
#include <FL/Fl_Menu_Bar.h>
#include <FL/Fl_Text_Buffer.h>
#include <FL/Fl_Window.h>
#include <FL/filename.h>



class QuCallback
{
    public:
        QuCallback();
        virtual ~QuCallback();

        //全局参数
        static int m_loading;
        static int m_changed;
        static char m_filename[FL_PATH_MAX];
        static char m_title[FL_PATH_MAX];


        static Fl_Text_Buffer m_buffer;

        static const int line_num_width;


        //
        static void new_cb(Fl_Widget*, void*);
        static void open_cb(Fl_Widget*, void*);
        static void quit_cb(Fl_Widget*, void*);

        static void changed_cb(int, int nInserted, int nDeleted, int, const char *, void *v);


        static void insert_cb(Fl_Widget*, void*);
        static void view_cb(Fl_Widget*, void*);
        static void close_cb(Fl_Widget*, void*);
        static void cut_cb(Fl_Widget*, void*);
        static void copy_cb(Fl_Widget*, void*);
        static void paste_cb(Fl_Widget*, void*);
        static void delete_cb(Fl_Widget*, void*);
        static void linenumbers_cb();
        static void wordwrap_cb();


        static void find_cb(Fl_Widget*, void*);
        static void find2_cb(Fl_Widget*, void*);
        static void replace_cb(Fl_Widget*, void*);
        static void replace2_cb(Fl_Widget*, void*);

        static bool check_save();
        static void set_title(Fl_Window *w);



        static void save_cb();
        static void saveas_cb();

        static void save_file(const char *newfile);
        static void load_file(const char *newfile, int ipos);

    protected:

    private:
};

#endif // QUCALLBACK_H
