#include <gtkmm.h>
#include "../include/pfs/procfs.hpp"
#include <iostream>

class MainWindow : public Gtk::Window {
    public:MainWindow();
};

MainWindow::MainWindow() {
    set_title("Simple GTK App");
    set_default_size(300,200);
}

int main(int argc, char* argv[]) {
    
    auto pfs = pfs::procfs();
    auto modules = pfs.get_modules();

    std::cout << "Test";

    for (const auto& module : modules) {
        std::cout << module.name << "\n";
    }

    // Create the application window
    auto app = Gtk::Application::create("com.github.mdmellor.gsystem-manager");
    auto window = MainWindow();
    app->run(window);

    return 0;
}

// Compile with: g++ src/main.cpp -o bin/main `pkg-config gtkmm-3.0 --cflags --libs` -lstdc++ -L/home/marcus/Documents/gsystem-manager/lib/ -l:libpfs.so -L/usr/lib -l:libasan.so