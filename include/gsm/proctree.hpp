#pragma once
#include <gtkmm.h>
#include "../pfs/procfs.hpp"
#include "../gsm/app.hpp"
#include <iostream>

namespace gsm {

    namespace proctree {

        pfs::procfs pfs_obj();

        void update_tree_store() {
            for (auto &x : pfs_obj.get_processes()) {
                std::cout << x.get_comm() << std::endl;
            }
        }
    }
}