#pragma once
#include <gtkmm.h>
#include <iostream>
#include "../pfs/procfs.hpp"
#include "proctree.hpp"

namespace gsm {

    Glib::RefPtr<Gtk::Application> currentApplication;

    /**
     * \fn load_ui()
     * \brief Uses Gtk::Builder to load the ui layout.
     */
    void load_ui() {
        auto builder = Gtk::Builder::create_from_file("./glade/glade.ui");
        Gtk::Window *window;
        builder->get_widget("main_window", window);
        currentApplication->add_window(*window);
        
        Glib::RefPtr<Gtk::TreeStore> treeModel;
        gsm::proctree::update_tree_store(treeModel);

        window->show();
    }

    /**
     * \fn int start_app(int argc, char* argv[])
     * \brief Starts the gsystem-manager application.
     * \param argc The command called.
     * \param argv A list of options passed after \a argc. 
     * \return The exit status.
     * \see start_app()
     * 
     * Creates and runs a new instance of the application. 
     * 
     * This implementation only differs from start_app() in that it
     * passes \a argc and \a argv to the run() call. 
     * 
     * As far as I can tell, this appears to be intended for use from
     * the command line (as it includes the \a argc and \a argv 
     * parameters).
     * 
     */
    int start_app(int argc, char* argv[]) {
        currentApplication = Gtk::Application::create("com.github.mdmellor.gsystem-manager");
        currentApplication->signal_activate().connect(sigc::ptr_fun(&load_ui));
        return currentApplication->run(argc, argv);
    }

    /**
     * \fn int start_app()
     * \brief Starts the gsystem-manager application.
     * \return The exit status.
     * \see start_app(int argc, char* argv[])
     * 
     * Creates and runs a new instance of the application. 
     */
    int start_app() {
        currentApplication = Gtk::Application::create("com.github.mdmellor.gsystem-manager");
        currentApplication->signal_activate().connect(sigc::ptr_fun(&load_ui));
        return currentApplication->run();
    }
}