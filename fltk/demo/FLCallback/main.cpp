#include <FL/Fl.H>
#include <FL/Fl_Double_Window.h>
#include <FL/Fl_Menu_Bar.h>


class CallBack
{
    public:

    static Fl_Callback* quit_cb()
    {
        printf("quit_cb");
    };
};



Fl_Menu_Item menuitems[] =
{
    {"&File", 0, 0, 0, FL_SUBMENU},
    {"E&xit", FL_COMMAND + 'q', (Fl_Callback*)CallBack::quit_cb, 0},
    {0}
};




int main (int argc, char ** argv)
{
    Fl_Double_Window *window;
    Fl_Menu_Bar *bar;

    window = new Fl_Double_Window(640, 480);
    bar = new Fl_Menu_Bar(0, 0, 640, 30);
    bar->copy(menuitems, window);

    window->end ();
    window->show (argc, argv);

    return(Fl::run());
}
