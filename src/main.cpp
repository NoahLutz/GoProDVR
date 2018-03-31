#include <iostream>
#include <vlc/vlc.h>

#include "gui/WindowController.hpp"
#include "player/Player.hpp"

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv, "GoProDVR");
    
    libvlc_instance_t *inst;
    inst = libvlc_new(0, NULL);

    Player *player = new Player(inst);

    WindowController *windowController = new WindowController(player);
    

    return app->run(*(windowController->getMainWindow()));
}

