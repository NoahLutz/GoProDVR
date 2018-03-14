#include<gtkmm/application.h>
#include "mainWindow.h"

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv, "gtkmmSpike");
    
    MainWindow window;
    return app->run(window);
}
