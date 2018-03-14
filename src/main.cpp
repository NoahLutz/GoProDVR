#include <iostream>
#include <gui/WindowController.hpp>

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv, "GoProDVR");

    WindowController windowController;




    return app->run(*(windowController.getMainWindow()));
}

