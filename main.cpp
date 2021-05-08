#include <gtkmm.h>

class MainWindow : public Gtk::Window {
    public:MainWindow();
};

MainWindow::MainWindow() {
    set_title("Simple GTK App");
    set_default_size(300,200);
}

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
    return app->run(argc, argv);
}

// Compile with: gcc main.cpp -o main `pkg-config gtkmm-3.0 --cflags --libs` -lstdc++