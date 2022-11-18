# Start of makefile

# File directories
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib

# All the files in the include directory
HEADERS = $(wildcard $(INC_DIR)/*.h)
# HEADERS = $(sort $(shell find $(INC_DIR) -name '*.h'))

# All the files in the src directory
SOURCES = $(wildcard $(SRC_DIR)/*.cc)
# SOURCES = $(sort $(shell find $(SRC_DIR) -name '*.cc'))

# All the object files
# OBJECTS = $(patsubst $(SRC_DIR)/%.cc, $(SRC_DIR)/%.o, $(SOURCES))
# OBJECTS = $(SOURCES:.cc=.o)
OBJECTS = $(patsubst $(SRC_DIR)/%.cc, $(OBJ_DIR)/%.o, $(SOURCES))

# The name of the executable
TARGET = minesweeper

# Compiler options
CXX			= g++ # c++ g++-8
C_VERSION	= -std=c++17 # -std=c++0x -std=c++14 -std=c++11 -std=c++2a -std=c++1z -std=c++1y -std=c++1x -std=c++03 -std=c++98
WARNINGS	= -Wall -Wextra -Werror -Wpedantic # -Weffc++
NO_WARNINGS	= -Wno-unused-parameter -Wno-unused-variable -Wno-deprecated-copy
C_FLAGS		= $(C_VERSION) $(WARNINGS)
CPP_FLAGS	= $(addprefix -I, $(INC_DIR))
LD_FLAGS	= -lstdc++fs # -lncurses

# Create lib directory if it doesn't exist
$(shell mkdir -p lib)

# Create obj directory if it doesn't exist
$(shell mkdir -p obj)

# .PHONY tells make that the target is not a file
.PHONY: all clean debug run valgrind gdb

# all is the default target
all:			C_FLAGS += -O3 -DNDEBUG
all:			$(TARGET)

$(TARGET):		$(OBJECTS)
				$(CXX) $(C_FLAGS) $(CPP_FLAGS) -o $@ $(OBJECTS) $(LD_FLAGS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cc $(HEADERS)
				$(CXX) $(C_FLAGS) $(CPP_FLAGS) -c $< -o $@

clean:
				rm -f $(OBJECTS) $(TARGET)

clear:			clean
				rm -rf $(OBJ_DIR)
				rm -rf $(LIB_DIR)

debug:			C_FLAGS += -g -DDEBUG -O0
debug:			$(TARGET)

run:			all
				./$(TARGET)

valgrind:		debug
				valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

gdb:			debug
				gdb ./$(TARGET) -ex "run" -ex "bt" -ex "quit"

# End of makefile