# NOTE: This file must be run from the src directory.

# Set up useful directory macros
SRC_DIR = $(CURDIR)
BIN_DIR = $(dir $(CURDIR))bin
LIB_DIR = $(dir $(CURDIR))lib
GTK_FLAGS = `pkg-config gtkmm-3.0 --cflags --libs`
LDFLAGS = -Wl,-rpath=$(LIB_DIR) -L$(LIB_DIR)/

# Build main
main: main.cpp
	$(CXX) -g $(SRC_DIR)/$@.cpp -o $(BIN_DIR)/$@ $(GTK_FLAGS) -lstdc++ $(LDFLAGS) -l:libpfs.a -fsanitize=address