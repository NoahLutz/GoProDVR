#include "player/Player.hpp"

/**********************************************************
 * Function: 	
 *
 * Description: 
 *
 * Arguments:	
 * 				
 * 
 * Returns:		
 *
**********************************************************/
Player::Player(libvlc_instance_t *vlc_inst)
{
    m_vlc_inst = vlc_inst;
    m_media_player = libvlc_media_player_new(m_vlc_inst);
}

/**********************************************************
 * Function: 	
 *
 * Description: 
 *
 * Arguments:	
 * 				
 * 
 * Returns:		
 *
**********************************************************/
Player::~Player()
{
    libvlc_media_player_release(m_media_player);
}

/**********************************************************
 * Function: 	
 *
 * Description: 
 *
 * Arguments:	
 * 				
 * 
 * Returns:		
 *
**********************************************************/
void Player::set_media_player_window(Gtk::Widget *widget)
{
    libvlc_media_player_set_xwindow(m_media_player, GDK_WINDOW_XID(gtk_widget_get_window(widget->gobj())));
}

/**********************************************************
 * Function: 	
 *
 * Description: 
 *
 * Arguments:	
 * 				
 * 
 * Returns:		
 *
**********************************************************/
void Player::set_media(libvlc_media_t *media)
{
    m_media = media;
    libvlc_media_player_set_media(m_media_player, m_media);
}

/**********************************************************
 * Function: 	
 *
 * Description: 
 *
 * Arguments:	
 * 				
 * 
 * Returns:		
 *
**********************************************************/
void Player::set_media_from_uri(const char *uri)
{
    libvlc_media_t *media = libvlc_media_new_location(m_vlc_inst, uri);
    if(m_media != nullptr)
    {
        libvlc_media_release(m_media);
    }
    this->set_media(media);
}

/**********************************************************
 * Function: 	
 *
 * Description: 
 *
 * Arguments:	
 * 				
 * 
 * Returns:		
 *
**********************************************************/
libvlc_media_t* Player::get_media(void)
{
    return m_media;
}

/**********************************************************
 * Function: 	
 *
 * Description: 
 *
 * Arguments:	
 * 				
 * 
 * Returns:		
 *
**********************************************************/
void Player::release_media(void)
{
    libvlc_media_release(m_media);
}

/**********************************************************
 * Function: 	
 *
 * Description: 
 *
 * Arguments:	
 * 				
 * 
 * Returns:		
 *
**********************************************************/
void Player::pause(void)
{
    libvlc_media_player_pause(m_media_player);
}

/**********************************************************
 * Function: 	
 *
 * Description: 
 *
 * Arguments:	
 * 				
 * 
 * Returns:		
 *
**********************************************************/
void Player::play(void)
{
    libvlc_media_player_play(m_media_player);
}

/**********************************************************
 * Function: 	
 *
 * Description: 
 *
 * Arguments:	
 * 				
 * 
 * Returns:		
 *
**********************************************************/
void Player::stop(void)
{
    this->pause();
    libvlc_media_player_stop(m_media_player);
}

/**********************************************************
 * Function: 	
 *
 * Description: 
 *
 * Arguments:	
 * 				
 * 
 * Returns:		
 *
**********************************************************/
bool Player::is_playing(void)
{
    return libvlc_media_player_is_playing(m_media_player);
}
