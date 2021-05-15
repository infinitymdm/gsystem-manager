#pragma once
#include <gtkmm.h>
#include "../pfs/procfs.hpp"
#include <iostream>

namespace gsm {

    Glib::RefPtr<Gtk::Application> CurrentApplication;

    void load_ui() {
        auto builder = Gtk::Builder::create_from_file("./glade/glade.ui");
        Gtk::Window *window;
        builder->get_widget("main_window", window);
        CurrentApplication->add_window(*window);
        window->show();
    }

    int start_app(int argc, char* argv[]) {
        CurrentApplication = Gtk::Application::create("com.github.mdmellor.gsystem-manager");
        CurrentApplication->signal_activate().connect(sigc::ptr_fun(&load_ui));
        return CurrentApplication->run(argc, argv);
    }

    int start_app() {
        CurrentApplication = Gtk::Application::create("com.github.mdmellor.gsystem-manager");
        CurrentApplication->signal_activate().connect(sigc::ptr_fun(&load_ui));
        return CurrentApplication->run(0, nullptr);
    }
}