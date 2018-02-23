//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuViewKeg.h"


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>



QuViewKeg::QuViewKeg()
{
    //ctor
}

QuViewKeg::~QuViewKeg()
{
    //dtor
}

int QuViewKeg::run()
{
    Fl_Window *window;
    Fl_Box *box;

    window = new Fl_Window (300, 180);
    box = new Fl_Box (20, 40, 260, 100, "Hello World!");

    box->box (FL_UP_BOX);
    box->labelsize (36);
    box->labelfont (FL_BOLD+FL_ITALIC);
    box->labeltype (FL_SHADOW_LABEL);
    window->end ();
    //window->show (argc, argv);
    window->show (0, 0);

    return Fl::run();
}
