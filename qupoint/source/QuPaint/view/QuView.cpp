//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物和可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuView.h"

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
    CreateMain();
    CreateStatusBar();

    return 0;
}

int QuView::Destroy()
{
    DestroyStatusBar();
    DestroyMain();
    DestroyToolsBar();
    DestroyMenuBar();
    DestroyWindow();

    return 0;
}

int QuView::CreateWindow()
{
    m_window = new Fl_Window (300, 180);
    return 0;
}

int QuView::CreateMenuBar()
{
    return 0;
}

int QuView::CreateToolsBar()
{
    return 0;
}

int QuView::CreateMain()
{
    Fl_Box *box;

    box = new Fl_Box (20, 40, 260, 100, "Hello World!");

    box->box (FL_UP_BOX);
    box->labelsize (36);
    box->labelfont (FL_BOLD+FL_ITALIC);
    box->labeltype (FL_SHADOW_LABEL);

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

int QuView::DestroyStatusBar()
{
    return 0;
}


int QuView::run()
{
    m_window->end ();
    //window->show (argc, argv);
    m_window->show (0, 0);

    return Fl::run();
}
