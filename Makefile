# Set up useful directory macros
SRC_DIR = $(CURDIR)/src
BIN_DIR = $(CURDIR)/bin
LIB_DIR = $(CURDIR)/lib
GTK_FLAGS = `pkg-config gtkmm-3.0 --cflags --libs`
LDFLAGS = -Wl,-rpath=$(LIB_DIR) -L$(LIB_DIR)/

# Set main to the default build target
default: main

# Tell make that the below targets are not filenames
.PHONY: default directories clean

# Create bin directory if not present
directories:
	@mkdir -p $(BIN_DIR)

# Build main
main: $(SRC_DIR)/main.cpp directories
	$(CXX) -g $(SRC_DIR)/$@.cpp -o $(BIN_DIR)/$@ $(GTK_FLAGS) -lstdc++ $(LDFLAGS) -l:libpfs.a -fsanitize=address

clean:
	@rm -Rf $(BIN_DIR)