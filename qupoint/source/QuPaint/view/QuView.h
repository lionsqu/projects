//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物和可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUVIEW_H
#define QUVIEW_H


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>



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
        int CreateStatusBar();

        int DestroyWindow();
        int DestroyMenuBar();
        int DestroyToolsBar();
        int DestroyMain();
        int DestroyStatusBar();

    private:
        Fl_Window *m_window;
};

#endif // QUVIEW_H
