#ifndef WINDOW_CONTROLLER_H
#define WINDOW_CONTROLLER_H

#include<iostream>
#include<gtkmm.h>

#include "player/Player.hpp"

#define GLADE_FILE "GoProDVR.glade"

class WindowController
{
    private:
        Glib::RefPtr<Gtk::Builder> builder;
        Player *m_player;

        void player_widget_on_realize();
        void on_open();
        void on_playpause();
        void on_stop();
        void destroy();        

    public:
        WindowController(Player *player);
        ~WindowController();
        Gtk::Window* getMainWindow(void);

};

#endif
