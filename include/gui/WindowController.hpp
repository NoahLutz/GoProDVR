#ifndef WINDOW_CONTROLLER_H
#define WINDOW_CONTROLLER_H

#include<iostream>
#include<gtkmm.h>

#include "player/Player.hpp"
#include "gui/URLEntryDialog.hpp"
#include "gui/SeekBar.hpp"

#define GLADE_FILE "GoProDVR.glade"

class WindowController
{
    private:
        Glib::RefPtr<Gtk::Builder> builder;
        Player *m_player;
        Gtk::Button *m_playpause_button;
        Gtk::Button *m_stop_button;
        Gtk::Button *m_record_button;
        SeekBar m_seek_bar;

        void player_widget_on_realize();
        void on_open();
        void on_playpause();
        void on_stop();

    public:
        WindowController(Player *player);
        ~WindowController();
        Gtk::Window* getMainWindow(void);
        void open_media(std::string uri);

};

#endif
