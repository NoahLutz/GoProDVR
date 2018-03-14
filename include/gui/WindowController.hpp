#ifndef WINDOW_CONTROLLER_H
#define WINDOW_CONTROLLER_H

#include<iostream>
#include<gtkmm.h>

#define GLADE_FILE "GoProDVR.glade"

class WindowController
{
    private:
        Glib::RefPtr<Gtk::Builder> builder;
        void player_widget_on_realize(Gtk::Widget widget);
        void on_open();
        void on_playpause();
        void on_stop();
        void destroy();        

    public:
        WindowController();
        ~WindowController();
        Gtk::Window* getMainWindow(void);

};

#endif
