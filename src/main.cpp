#include <gtkmm.h>
#include "../include/gsm/app.hpp"

using namespace gsm;

int main(int argc, char* argv[]) {

    // Initialize UI toolkit libs
    Glib::init();

    // Start the app and hand off to user
    return start_app(argc, argv);
}

// Compile by executing "make" from root project directory
