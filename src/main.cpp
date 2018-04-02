#include <iostream>
#include <vlc/vlc.h>

#include "gui/WindowController.hpp"
#include "player/Player.hpp"

#include <X11/Xlib.h>
int main(int argc, char* argv[])
{
    XInitThreads();
    auto app = Gtk::Application::create(argc, argv, "GoProDVR");
    
    libvlc_instance_t *inst;
    inst = libvlc_new(0, NULL);

    Player *player = new Player(inst);

    WindowController *windowController = new WindowController(player);
    

    int returnCode = app->run(*(windowController->getMainWindow()));

    delete(player);

    libvlc_release(inst);

    return returnCode;
}

