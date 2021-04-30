#include <gtkmm.h>

class MainWindow : public Gtk::Window {
    public:MainWindow();
};

MainWindow::MainWindow() {
    set_title("Simple GTK App");
    set_default_size(300,200);
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("com.github.mdmellor.gsystem-manager");
    auto window = MainWindow();
    app->run(window);
    return 0;
}

// Compile with: gcc main.cpp -o main `pkg-config gtkmm-3.0 --cflags --libs` -lstdc++