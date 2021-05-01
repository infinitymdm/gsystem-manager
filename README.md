# gsystem-manager
I often find myself unsatisfied with the built-in system management tools in linux distros. Frequently I want more information about what each service is doing on my system. This project aims to build a GTK+ 3.0 user interface for systemd to allow users to manage services, as well as provide more information about what each service is. This should include features such as allowing users to click on services to see a detailed description akin to the output of a systemctl status command.

External Libraries
------------------
This software uses the following external libraries:
* PFS: Copyright 2020-present Daniel Trugman. Licensed under Apache 2.0 license. See LICENSE.APACHE for details. Website: https://github.com/dtrugman/pfs