#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <gtkmm.h>
#include "../pfs/procfs.hpp"
#include "../gsm/app.hpp"

namespace gsm {

    namespace proctree {

        void update_tree_store(Glib::RefPtr<Gtk::TreeStore> treeModel) {

            std::string processName;

            for (auto &process : pfs::procfs().get_processes()) {
                processName = process.get_comm();
                std::cout << processName << std::endl;
            }
        }
    }
}