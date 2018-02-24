#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>


#include <QuScroll.h>



int main (int argc, char ** argv)
{
    Fl_Window *window;

    window = new Fl_Window (640, 480);
    window->resizable(window);

    QuScroll *scroll = new QuScroll(0, 0, 640, 480);

    window->end ();
    window->show (argc, argv);

    return(Fl::run());
}
