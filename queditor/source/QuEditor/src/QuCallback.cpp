//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//

#include "QuCallback.h"


#include <errno.h>
#include <FL/fl_ask.h>
#include <FL/Fl_Native_File_Chooser.h>
#include <QuEditWindow.h>



Fl_Text_Buffer QuCallback::m_buffer = Fl_Text_Buffer();
int QuCallback::m_loading = 0;
int QuCallback::m_changed = 0;
char QuCallback::m_filename[FL_PATH_MAX] = "";
char QuCallback::m_title[FL_PATH_MAX] = "";
const int QuCallback::line_num_width = 75;


QuCallback::QuCallback()
{
    //ctor
}

QuCallback::~QuCallback()
{
    //dtor
}

void QuCallback::new_cb(Fl_Widget*, void*)
{
    if(!check_save())return;

    m_filename[0] = '\0';
    m_buffer.select(0, m_buffer.length());
    m_buffer.remove_selection();
    m_changed = 0;
    m_buffer.call_modify_callbacks();
}

void QuCallback::open_cb(Fl_Widget*, void*)
{
    if(!check_save())return;
    Fl_Native_File_Chooser fnfc;
    fnfc.title("Open file");
    fnfc.type(Fl_Native_File_Chooser::BROWSE_FILE);
    if(fnfc.show())return;
    load_file(fnfc.filename(), -1);
}

void QuCallback::quit_cb(Fl_Widget*, void*)
{
    if(m_changed && !check_save())return;
    exit(0);
}


bool QuCallback::check_save()
{
    if(!m_changed)return 1;

    int r = fl_choice("The current file has not been saved.\n"
                      "Would you like to save it now?",
                      "Cancel", "Save", "Don't Save");

    if(r == 1)
    {
        save_cb();
        return !m_changed;
    }

    return (r == 2) ? 1 : 0;
}

void QuCallback::set_title(Fl_Window *w)
{
    if(m_filename[0] == '\0')strcpy(m_title, "Untitled");
    else{
        char *slash;
        slash - strrchr(m_filename, '/');
#ifdef WIN32
        if (slash == NULL) slash = strrchr(filename, '\\');
#endif
        if (slash != NULL) strcpy(m_title, slash + 1);
        else strcpy(m_title, m_filename);
    }
    if (m_changed) strcat(m_title, " (modified)");

    w->label(m_title);
}

void QuCallback::changed_cb(int, int nInserted, int nDeleted, int, const char *, void *v)
{
    if((nInserted || nDeleted) && !m_loading)m_changed = 1;
    QuEditWindow *w = (QuEditWindow*)v;
    set_title(w);
    if(m_loading)w->m_editor->show_insert_position();
}

void QuCallback::save_cb()
{
    if(m_filename[0] == '\0')
    {
        saveas_cb();
        return;
    }else{
        save_file(m_filename);
    }
}

void QuCallback::saveas_cb()
{
    Fl_Native_File_Chooser fnfc;
    fnfc.title("Save File As?");
    fnfc.type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
    if(fnfc.show())return;
    save_file(fnfc.filename());
}

void QuCallback::save_file(const char *newfile)
{
    if(m_buffer.savefile(newfile))
        fl_alert("Error writing to file \'%s\':\n%s.", newfile, strerror(errno));
    else
        strcpy(m_filename, newfile);

    m_changed = 0;
    m_buffer.call_modify_callbacks();
}

void QuCallback::load_file(const char *newfile, int ipos)
{
    m_loading = 1;
    int insert = (ipos != -1);
    m_changed = insert;
    if(!insert)strcpy(m_filename, "");
    int r;
    if(!insert)r = m_buffer.loadfile(newfile);
    else
        r = m_buffer.insertfile(newfile, ipos);

    m_changed = m_changed || m_buffer.input_file_was_transcoded;
    if(r)
        fl_alert("Error reading from file \'%s\':\n%s.", newfile, strerror(errno));
    else if(!insert)strcpy(m_filename, newfile);
    m_loading = 0;
    m_buffer.call_modify_callbacks();

}

void QuCallback::insert_cb(Fl_Widget*, void*)
{
}

void QuCallback::view_cb(Fl_Widget*, void*)
{
}

void QuCallback::close_cb(Fl_Widget*, void*)
{
}

void QuCallback::cut_cb(Fl_Widget*, void*)
{
}

void QuCallback::copy_cb(Fl_Widget*, void*)
{
}

void QuCallback::paste_cb(Fl_Widget*, void*)
{
}

void QuCallback::delete_cb(Fl_Widget*, void*)
{
}

void QuCallback::linenumbers_cb()
{
}

void QuCallback::wordwrap_cb()
{
}

void QuCallback::find_cb(Fl_Widget*, void*)
{
}

void QuCallback::find2_cb(Fl_Widget*, void*)
{
}

void QuCallback::replace_cb(Fl_Widget*, void*)
{
}

void QuCallback::replace2_cb(Fl_Widget*, void*)
{

}
