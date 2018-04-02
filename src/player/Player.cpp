#include "player/Player.hpp"

Player::Player(libvlc_instance_t *vlc_inst)
{
    m_vlc_inst = vlc_inst;
    m_media_player = libvlc_media_player_new(m_vlc_inst);
}

Player::~Player()
{
    libvlc_media_player_release(m_media_player);
}

void Player::set_media_player_window(Gtk::Widget *widget)
{
    libvlc_media_player_set_xwindow(m_media_player, GDK_WINDOW_XID(gtk_widget_get_window(widget->gobj())));
}

void Player::set_media(libvlc_media_t *media)
{
    m_media = media;
    libvlc_media_player_set_media(m_media_player, m_media);
}

void Player::set_media_from_uri(const char *uri)
{
    libvlc_media_t *media = libvlc_media_new_location(m_vlc_inst, uri);
    if(m_media != nullptr)
    {
        libvlc_media_release(m_media);
    }
    this->set_media(media);
}

libvlc_media_t* Player::get_media(void)
{
    return m_media;
}

void Player::release_media(void)
{
    libvlc_media_release(m_media);
}

void Player::pause(void)
{
    libvlc_media_player_pause(m_media_player);
}

void Player::play(void)
{
    libvlc_media_player_play(m_media_player);
}

void Player::stop(void)
{
    this->pause();
    libvlc_media_player_stop(m_media_player);
}

bool Player::is_playing(void)
{
    return libvlc_media_player_is_playing(m_media_player);
}
