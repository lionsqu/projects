//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUCALLBACK_H
#define QUCALLBACK_H


#include <FL/Fl_Menu_Bar.h>
#include <QuCore.h>


extern Fl_Menu_Item menuitems[];
extern Fl_Menu_Item popupitems[];


class QuCallback
{
    public:
        QuCallback(class QuCore *core);
        virtual ~QuCallback();

        static void new_cb(Fl_Widget*w, void*v);
        static void open_cb(Fl_Widget*w, void*v);
        static void close_cb(Fl_Widget*w, void*v);

        static void save_cb(Fl_Widget*w, void*v);
        static void saveas_cb(Fl_Widget*w, void*v);

        static void writeto_cb(Fl_Widget*w, void*v);

        static void quit_cb(Fl_Widget*w, void*v);

        static void popup_cb();


        static void addfunc_cb();
        static void addclass_cb();
        static void delete_cb();

    protected:
    private:

    public:
        //QuCore      *m_core;
};

#endif // QUCALLBACK_H
