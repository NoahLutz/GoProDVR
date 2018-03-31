#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>

#include<vlc/vlc.h>
#include<gtkmm.h>
#include<gdk/gdkx.h>
#include<gtk/gtk.h>

class Player
{
    public:
        Player(libvlc_instance_t *vlc_inst);
        ~Player();
        void set_media_player_window(Gtk::Widget *widget); 
        void set_media(libvlc_media_t *media);
        void set_media_from_uri(const char *uri);
        libvlc_media_t* get_media(void);
        void release_media(void);
        void pause(void);
        void play(void);
        void stop(void);
        bool is_playing(void);
    private:
        libvlc_instance_t *m_vlc_inst;
        libvlc_media_player_t *m_media_player;
        libvlc_media_t *m_media;
};

#endif

