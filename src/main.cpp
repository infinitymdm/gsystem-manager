#include <gtkmm.h>
#include "../include/pfs/procfs.hpp"
#include <iostream>

using namespace pfs;
using namespace std;

Glib::RefPtr<Gtk::Application> app;

void load_ui() {
    auto builder = Gtk::Builder::create_from_file("./glade/glade.ui");
    Gtk::Window *window;
    builder->get_widget("main_window", window);
    app->add_window(*window);
    window->show();
}

int main(int argc, char* argv[]) {

    Glib::init();
    app = Gtk::Application::create("com.github.mdmellor.gsystem-manager");
    app->signal_activate().connect(sigc::ptr_fun(&load_ui));
    procfs p = procfs();
    for (auto &x : p.get_processes()) {
        cout << x.get_comm() << endl;
    }
    return app->run(argc, argv);
}

// Compile with: gcc main.cpp -o main `pkg-config gtkmm-3.0 --cflags --libs` -lstdc++
