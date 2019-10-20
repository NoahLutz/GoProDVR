#include "gui/WindowController.hpp"

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
WindowController::WindowController(Player *player)
{
    //Set the player
    m_player = player;

    //Create the builder from the glade file
    builder = Gtk::Builder::create_from_file(GLADE_FILE);
    
    //Get the play/pause button and set the signal handler
    Gtk::Button *playpause_button = nullptr;
    builder->get_widget("playpause_button", playpause_button);
    if(playpause_button)
    {
        m_playpause_button = playpause_button;
        m_playpause_button->signal_clicked().connect(sigc::mem_fun(*this, &WindowController::on_playpause));
    }
    else
    {
        //TODO: show error popup
        std::cerr << "Failed to find the play/pause button, please ensure glade file is correct" << std::endl;
    }

    //Get the stop button and set the signal handler
    Gtk::Button *stop_button = nullptr;
    builder->get_widget("stop_button", stop_button);
    if(stop_button)
    {
        m_stop_button = stop_button;
        m_stop_button->signal_clicked().connect(sigc::mem_fun(*this, &WindowController::on_stop));
    }
    else
    {
        //TODO: show error popup
        std::cerr << "Failed to find the stop button, please ensure the glade file is correct" << std::endl;
    }

    //Get the video player drawing area and set the on_realize signal handler
    Gtk::Widget *videoPlayer = nullptr;
    builder->get_widget("videoPlayer", videoPlayer);
    if(videoPlayer)
    {
        videoPlayer->signal_realize().connect(sigc::mem_fun(*this, &WindowController::player_widget_on_realize));
    }
    else
    {
        //TODO: show error popup
        std::cerr << "Failed to find the video player area, please ensure glade file is correct" << std::endl;
    }

    //Get the open dialog button and set the on_open signal handler
    Gtk::MenuItem *open_source;
    builder->get_widget("open_stream", open_source);
    if(open_source)
    {
        open_source->signal_activate().connect(sigc::mem_fun(*this, &WindowController::on_open));
    }
    else
    {
        std::cerr << "Failed to find the Open menu item, please ensure the glade file is in the correct location" << std::endl;
    }
    
    Gtk::Box *mainBox;
    builder->get_widget("mainBox", mainBox);
    if(mainBox)
    {
        mainBox->pack_start(m_seek_bar, Gtk::PACK_SHRINK);
        m_seek_bar.show();
    }
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
WindowController::~WindowController()
{
    delete(m_player);
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
Gtk::Window* WindowController::getMainWindow()
{
    Gtk::Window *mainWindow = nullptr;
    builder->get_widget("MainWindow", mainWindow);
    return mainWindow;
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
void WindowController::player_widget_on_realize()
{
    Gtk::Widget *playerWindow = nullptr;
    builder->get_widget("videoPlayer", playerWindow);

    m_player->set_media_player_window(playerWindow);
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
void WindowController::on_open()
{
    //TODO: show chooser for GoPro
    URLEntryDialog *dialogWindow = new URLEntryDialog(this, builder);
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
void WindowController::on_playpause()
{
    if(m_player->is_playing())
    {
        m_player->pause();
        m_playpause_button->set_label("gtk-media-play");
    }
    else
    {
        m_player->play();
        m_playpause_button->set_label("gtk-media-pause");
    }
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
void WindowController::on_stop()
{
    //pause the media
    m_player->pause();

    //Change button to play
    m_playpause_button->set_label("gtk-media-play");

    //Stop the media
    m_player->stop();
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
void WindowController::open_media(std::string uri)
{
    m_player->set_media_from_uri(uri.c_str());
    this->on_playpause();
}
