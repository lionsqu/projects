//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuCallBack.h"


QuEditWindow *editwindow = 0;

char filename[FL_PATH_MAX] = "";
char title[FL_PATH_MAX] = "";


Fl_Menu_Item menuitems[] =
{
    { "&File",              0, 0, 0, FL_SUBMENU },
    { "&New File",        0, (Fl_Callback *)new_cb },
    { "&Open File...",    FL_COMMAND + 'o', (Fl_Callback *)open_cb },
    { "&Insert File...",  FL_COMMAND + 'i', (Fl_Callback *)insert_cb, 0, FL_MENU_DIVIDER },
    { "&Save File",       FL_COMMAND + 's', (Fl_Callback *)save_cb },
    { "Save File &As...", FL_COMMAND + FL_SHIFT + 's', (Fl_Callback *)saveas_cb, 0, FL_MENU_DIVIDER },
    {
        "New &View",        FL_ALT
#ifdef __APPLE__
        + FL_COMMAND
#endif
        + 'v', (Fl_Callback *)view_cb, 0
    },
    { "&Close View",      FL_COMMAND + 'w', (Fl_Callback *)close_cb, 0, FL_MENU_DIVIDER },
    { "E&xit",            FL_COMMAND + 'q', (Fl_Callback *)quit_cb, 0 },
    { 0 },

    { "&Edit", 0, 0, 0, FL_SUBMENU },
    { "Cu&t",             FL_COMMAND + 'x', (Fl_Callback *)cut_cb },
    { "&Copy",            FL_COMMAND + 'c', (Fl_Callback *)copy_cb },
    { "&Paste",           FL_COMMAND + 'v', (Fl_Callback *)paste_cb },
    { "&Delete",          0, (Fl_Callback *)delete_cb },
    { "Preferences",      0, 0, 0, FL_SUBMENU },
    { "Line Numbers",   FL_COMMAND + 'l', (Fl_Callback *)linenumbers_cb, 0, FL_MENU_TOGGLE },
    { "Word Wrap",      0,                (Fl_Callback *)wordwrap_cb, 0, FL_MENU_TOGGLE },
    { 0 },
    { 0 },

    { "&Search", 0, 0, 0, FL_SUBMENU },
    { "&Find...",         FL_COMMAND + 'f', (Fl_Callback *)find_cb },
    { "F&ind Again",      FL_COMMAND + 'g', find2_cb },
    { "&Replace...",      FL_COMMAND + 'r', replace_cb },
    { "Re&place Again",   FL_COMMAND + 't', replace2_cb },
    { 0 },

    { 0 }
};




//style
void style_unfinished_cb(int, void*)
{
}

//Editor
void save_cb()
{
    if (filename[0] == '\0')
    {
        // No filename - get one!
        saveas_cb();
        return;
    }
    else save_file(filename);
}

void saveas_cb()
{
    Fl_Native_File_Chooser fnfc;
    fnfc.title("Save File As?");
    fnfc.type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
    if ( fnfc.show() ) return;
    save_file(fnfc.filename());
}

void find_cb(Fl_Widget* w, void* v)
{
    QuEditWindow* e = (QuEditWindow*)v;
    const char *val;

    val = fl_input("Search String:", e->search);
    if (val != NULL)
    {
        // User entered a string - go find it!
        strcpy(e->search, val);
        find2_cb(w, v);
    }
}

void find2_cb(Fl_Widget* w, void* v)
{
    QuEditWindow* e = (QuEditWindow*)v;
    if (e->search[0] == '\0')
    {
        // Search string is blank; get a new one...
        find_cb(w, v);
        return;
    }

    int pos = e->m_editor->insert_position();
    int found = editwindow->m_buffer->search_forward(pos, e->search, &pos);
    if (found)
    {
        // Found a match; select and update the position...
        editwindow->m_buffer->select(pos, pos+strlen(e->search));
        e->m_editor->insert_position(pos+strlen(e->search));
        e->m_editor->show_insert_position();
    }
    else fl_alert("No occurrences of \'%s\' found!", e->search);
}

void replace_cb(Fl_Widget*, void* v)
{
    QuEditWindow* e = (QuEditWindow*)v;
    e->replace_dlg->show();
}

void replall_cb(Fl_Widget* w, void* v)
{
    QuEditWindow* e = (QuEditWindow*)v;
    const char *find = e->replace_find->value();
    const char *replace = e->replace_with->value();

    find = e->replace_find->value();
    if (find[0] == '\0')
    {
        // Search string is blank; get a new one...
        e->replace_dlg->show();
        return;
    }

    e->replace_dlg->hide();

    e->m_editor->insert_position(0);
    int times = 0;

    // Loop through the whole string
    for (int found = 1; found;)
    {
        int pos = e->m_editor->insert_position();
        found = editwindow->m_buffer->search_forward(pos, find, &pos);

        if (found)
        {
            // Found a match; update the position and replace text...
            editwindow->m_buffer->select(pos, pos+strlen(find));
            editwindow->m_buffer->remove_selection();
            editwindow->m_buffer->insert(pos, replace);
            e->m_editor->insert_position(pos+strlen(replace));
            e->m_editor->show_insert_position();
            times++;
        }
    }

    if (times) fl_message("Replaced %d occurrences.", times);
    else fl_alert("No occurrences of \'%s\' found!", find);
}

void replace2_cb(Fl_Widget* w, void* v)
{
    QuEditWindow* e = (QuEditWindow*)v;
    const char *find = e->replace_find->value();
    const char *replace = e->replace_with->value();

    if (find[0] == '\0')
    {
        // Search string is blank; get a new one...
        e->replace_dlg->show();
        return;
    }

    e->replace_dlg->hide();

    int pos = e->m_editor->insert_position();
    int found = editwindow->m_buffer->search_forward(pos, find, &pos);

    if (found)
    {
        // Found a match; update the position and replace text...
        editwindow->m_buffer->select(pos, pos+strlen(find));
        editwindow->m_buffer->remove_selection();
        editwindow->m_buffer->insert(pos, replace);
        editwindow->m_buffer->select(pos, pos+strlen(replace));
        e->m_editor->insert_position(pos+strlen(replace));
        e->m_editor->show_insert_position();
    }
    else fl_alert("No occurrences of \'%s\' found!", find);
}

void replcan_cb(Fl_Widget* w, void* v)
{
    QuEditWindow* e = (QuEditWindow*)v;
    e->replace_dlg->hide();
}

int check_save(void)
{
    if (!changed) return 1;

    int r = fl_choice("The current file has not been saved.\n"
                      "Would you like to save it now?",
                      "Cancel", "Save", "Don't Save");

    if (r == 1)
    {
        save_cb(); // Save the file...
        return !changed;
    }

    return (r == 2) ? 1 : 0;
}

void load_file(const char *newfile, int ipos)
{
    loading = 1;
    int insert = (ipos != -1);
    changed = insert;
    if (!insert) strcpy(filename, "");
    int r;
    if (!insert) r = editwindow->m_buffer->loadfile(newfile);
    else r = editwindow->m_buffer->insertfile(newfile, ipos);
    changed = changed || editwindow->m_buffer->input_file_was_transcoded;
    if (r)
        fl_alert("Error reading from file \'%s\':\n%s.", newfile, strerror(errno));
    else if (!insert) strcpy(filename, newfile);
    loading = 0;
    editwindow->m_buffer->call_modify_callbacks();
}

void save_file(const char *newfile)
{
    if (editwindow->m_buffer->savefile(newfile))
        fl_alert("Error writing to file \'%s\':\n%s.", newfile, strerror(errno));
    else
        strcpy(filename, newfile);
    changed = 0;
    editwindow->m_buffer->call_modify_callbacks();
}

void set_title(Fl_Window* w)
{
    if (filename[0] == '\0') strcpy(title, "Untitled");
    else
    {
        char *slash;
        slash = strrchr(filename, '/');
#ifdef WIN32
        if (slash == NULL) slash = strrchr(filename, '\\');
#endif
        if (slash != NULL) strcpy(title, slash + 1);
        else strcpy(title, filename);
    }

    if (changed) strcat(title, " (modified)");

    w->label(title);
}

void copy_cb(Fl_Widget*, void* v)
{
    QuEditWindow* e = (QuEditWindow*)v;
    Fl_Text_Editor::kf_copy(0, e->m_editor);
}

void cut_cb(Fl_Widget*, void* v)
{
    QuEditWindow* e = (QuEditWindow*)v;
    Fl_Text_Editor::kf_cut(0, e->m_editor);
}

void delete_cb(Fl_Widget*, void*)
{
    editwindow->m_buffer->remove_selection();
}


void lnum_cb(Fl_Widget *w, void* v)
{
    QuEditWindow* ew = (QuEditWindow*)v;
    Fl_Text_Editor *ed = (Fl_Text_Editor*)ew->m_editor;
    ew->line_numbers = 1 - ew->line_numbers;
    if (ew->line_numbers)
    {
        ed->linenumber_width(line_num_width);	// enable
        ed->linenumber_size(ed->textsize());
    }
    else
    {
        ed->linenumber_width(0);			// disable
    }
    ew->redraw();
}



void linenumbers_cb(Fl_Widget *w, void* v)
{
    QuEditWindow* e = (QuEditWindow*)v;
    Fl_Menu_Bar* m = (Fl_Menu_Bar*)w;
    const Fl_Menu_Item* i = m->mvalue();
    if ( i->value() )
    {
        e->m_editor->linenumber_width(line_num_width);	// enable
        e->m_editor->linenumber_size(e->m_editor->textsize());
    }
    else
    {
        e->m_editor->linenumber_width(0);	// disable
    }
    e->line_numbers = (i->value()?1:0);
    e->redraw();
}

void wordwrap_cb(Fl_Widget *w, void* v)
{
    QuEditWindow* e = (QuEditWindow*)v;
    Fl_Menu_Bar* m = (Fl_Menu_Bar*)w;
    const Fl_Menu_Item* i = m->mvalue();
    if ( i->value() )
        e->m_editor->wrap_mode(Fl_Text_Display::WRAP_AT_BOUNDS, 0);
    else
        e->m_editor->wrap_mode(Fl_Text_Display::WRAP_NONE, 0);
    e->wrap_mode = (i->value()?1:0);
    e->redraw();
}


void changed_cb(int, int nInserted, int nDeleted,int, const char*, void* v)
{
    if ((nInserted || nDeleted) && !loading) changed = 1;
    QuEditWindow *w = (QuEditWindow *)v;
    set_title(w);
    if (loading) w->m_editor->show_insert_position();
}

void new_cb(Fl_Widget*, void*)
{
    if (!check_save()) return;

    filename[0] = '\0';
    editwindow->m_buffer->select(0, editwindow->m_buffer->length());
    editwindow->m_buffer->remove_selection();
    changed = 0;
    editwindow->m_buffer->call_modify_callbacks();
}

void open_cb(Fl_Widget*, void*)
{
    if (!check_save()) return;
    Fl_Native_File_Chooser fnfc;
    fnfc.title("Open file");
    fnfc.type(Fl_Native_File_Chooser::BROWSE_FILE);
    if ( fnfc.show() ) return;
    load_file(fnfc.filename(), -1);
}

void insert_cb(Fl_Widget*, void *v)
{
    Fl_Native_File_Chooser fnfc;
    fnfc.title("Insert file");
    fnfc.type(Fl_Native_File_Chooser::BROWSE_FILE);
    if ( fnfc.show() ) return;
    QuEditWindow *w = (QuEditWindow *)v;
    load_file(fnfc.filename(), w->m_editor->insert_position());
}

void paste_cb(Fl_Widget*, void* v)
{
    QuEditWindow* e = (QuEditWindow*)v;
    Fl_Text_Editor::kf_paste(0, e->m_editor);
}

void close_cb(Fl_Widget*, void* v)
{
    QuEditWindow* w = (QuEditWindow*)v;

    if (num_windows == 1)
    {
        if (!check_save())
            return;
    }

    w->hide();
    w->m_editor->buffer(0);
    w->m_buffer->remove_modify_callback(style_update, w->m_editor);
    w->m_buffer->remove_modify_callback(changed_cb, w);
    Fl::delete_widget(w);

    num_windows--;
    if (!num_windows) exit(0);
}

void quit_cb(Fl_Widget*, void*)
{
    if (changed && !check_save())
        return;

    exit(0);
}

void view_cb(Fl_Widget*, void*)
{
    Fl_Window* w = new_view();
    w->show();
}


Fl_Window* new_view()
{
    QuEditWindow* w = new QuEditWindow(0, 0, 660, 400, title);


    w->begin();
    Fl_Menu_Bar* m = new Fl_Menu_Bar(0, 0, 660, 30);
    m->copy(menuitems, w);
    w->m_editor = new Fl_Text_Editor(0, 30, 660, 370);
    w->m_editor->textfont(FL_COURIER);
    w->m_editor->textsize(TS);
    //w->m_editor->wrap_mode(Fl_Text_Editor::WRAP_AT_BOUNDS, 250);
    w->m_editor->buffer(w->m_buffer);
    w->m_editor->highlight_data(stylebuf, styletable,
                              sizeof(styletable) / sizeof(styletable[0]),
                              'A', style_unfinished_cb, 0);


    w->end();
    w->resizable(w->m_editor);
    w->size_range(300,200);
    w->callback((Fl_Callback *)close_cb, w);

    w->m_buffer->add_modify_callback(style_update, w->m_editor);
    w->m_buffer->add_modify_callback(changed_cb, w);
    w->m_buffer->call_modify_callbacks();
    num_windows++;
    return w;
}

