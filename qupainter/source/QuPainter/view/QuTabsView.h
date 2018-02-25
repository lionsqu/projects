#ifndef QUTABSVIEW_H
#define QUTABSVIEW_H

#include <FL/Fl.h>
#include <FL/Fl_Tabs.h>


class QuTabsView : public Fl_Tabs
{
    public:
        QuTabsView(int x,int y,int w,int h,const char *l = 0);
        virtual ~QuTabsView();

        int create();
        int handle(int event);
        void draw();

    protected:
    private:
        Fl_Group    *m_tab1;
        Fl_Group    *m_tab2;

        int handle_push(int event);
};

#endif // QUTABSVIEW_H
