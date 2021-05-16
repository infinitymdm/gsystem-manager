#include <gtkmm.h>
#include "../include/gsm/app.hpp"

using namespace gsm;

int main(int argc, char* argv[]) {

    Glib::init();
    return start_app(argc, argv);
}

// Compile by executing "make" from root project directory
