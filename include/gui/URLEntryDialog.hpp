#ifndef URL_ENTRY_H
#define URL_ENTRY_H

#include<iostream>
#include<gtkmm.h>

#include "gui/WindowController.hpp"
class WindowController;
class URLEntryDialog
{
    public:
        URLEntryDialog(WindowController *controller, Glib::RefPtr<Gtk::Builder> builder);
        ~URLEntryDialog();
    private:
        void on_cancel();
        void on_open();

        WindowController *m_controller;
        Gtk::Dialog *m_dialog;
        Gtk::Entry *m_entry;
        Gtk::Button *m_cancel;
        Gtk::Button *m_open;
};

#endif
