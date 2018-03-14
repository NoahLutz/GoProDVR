#include "gui/WindowController.hpp"

WindowController::WindowController()
{
    builder = Gtk::Builder::create_from_file(GLADE_FILE);

    Gtk::Button *playpause_button = nullptr;
    builder->get_widget("playpause_button", playpause_button);
    if(playpause_button)
    {
        playpause_button->signal_clicked().connect(sigc::mem_fun(*this, &WindowController::on_playpause));
    }

}

WindowController::~WindowController()
{
}

Gtk::Window* WindowController::getMainWindow()
{
    Gtk::Window *mainWindow = nullptr;
    builder->get_widget("MainWindow", mainWindow);
    return mainWindow;
}

void WindowController::player_widget_on_realize(Gtk::Widget widget)
{
    //TODO: set libvlc media player window
}

void WindowController::on_open()
{
    //TODO: show chooser for GoPro
}

void WindowController::on_playpause()
{
    //TODO: pause/play media
    std::cout << "on_playpause" << std::endl;
}

void WindowController::on_stop()
{
    //TODO: stop media
}

void WindowController::destroy()
{
    gtk_main_quit();
}
