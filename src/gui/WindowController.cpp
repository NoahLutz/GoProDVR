#include "gui/WindowController.hpp"
#include "player/Player.hpp"

WindowController::WindowController(Player *player)
{
    //Set the player
    m_player = player;
    //Create the builder from the glade file
    builder = Gtk::Builder::create_from_file(GLADE_FILE);
    
    //Set the main window destroy signal
    //this->getMainWindow()->signal_delete_event().connect(sigc::mem_fun(*this, &WindowController::destroy));

    //Get the play/pause button and set the signal handler
    Gtk::Button *playpause_button = nullptr;
    builder->get_widget("playpause_button", playpause_button);
    if(playpause_button)
    {
        playpause_button->signal_clicked().connect(sigc::mem_fun(*this, &WindowController::on_playpause));
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
        stop_button->signal_clicked().connect(sigc::mem_fun(*this, &WindowController::on_stop));
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


}

WindowController::~WindowController()
{
    delete(m_player);
}

Gtk::Window* WindowController::getMainWindow()
{
    Gtk::Window *mainWindow = nullptr;
    builder->get_widget("MainWindow", mainWindow);
    return mainWindow;
}

void WindowController::player_widget_on_realize()
{
    std::cout << "In player widget realize" << std::endl;
    Gtk::Widget *playerWindow = nullptr;
    builder->get_widget("videoPlayer", playerWindow);

    m_player->set_media_player_window(playerWindow);
    std::cout << "after set_window called" << std::endl;
}

void WindowController::on_open()
{
    //TODO: show chooser for GoPro
    
}


void WindowController::on_playpause()
{
    //TODO: pause/play media
    std::cout << "on_playpause" << std::endl;
    if(m_player->is_playing())
    {
        m_player->pause();
        //TODO: change button to play
    }
    else
    {
        m_player->play();
        //TODO: change button to pause
    }
}

void WindowController::on_stop()
{
    std::cout << "on_stop()" << std::endl;
    m_player->pause();
    //Change button to play
    m_player->stop();
}

void WindowController::destroy()
{
    std::cout << "destroy" << std::endl;
    gtk_main_quit();
}
