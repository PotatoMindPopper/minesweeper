# Start of makefile


# -- TERMINAL CONFIGURATION --
ifeq ($(OS),Windows_NT)
	RM = del /Q
	RMDIR = rmdir /S /Q
	EXE = .exe
else
	RM = rm -f
	RMDIR = rm -rf
	EXE =
endif


# -- NAMES AND LOCATIONS --
# File directories
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj
# All the files in the include directory
HEADERS = $(wildcard $(INC_DIR)/*.h)
# All the files in the src directory
SOURCES = $(wildcard $(SRC_DIR)/*.cc)
# All the object files
OBJECTS = $(patsubst $(SRC_DIR)/%.cc, $(OBJ_DIR)/%.o, $(SOURCES))
# The name and directory of the executable
EXECUTABLE = minesweeper
TARGET = $(EXECUTABLE)$(EXE)


# -- COMPILER OPTIONS --
CXX			= g++

# --- COMPILER FLAGS ---
C_VERSION			= -std=c++17
WARNINGS			= -Wall -Wextra -Werror -Wpedantic -Weffc++
DISABLE_WARNINGS	= 
OPTIMIZATION 		= -O0
DEBUG_F				= -ggdb3 -DDEBUG -g

# Compiler flags
C_FLAGS		= $(C_VERSION) $(WARNINGS) $(OPTIMIZATION) $(DEBUG_F)
# Include flags
CPP_FLAGS	= $(addprefix -I, $(INC_DIR))


# -- MAKE DIRECTORIES --
# Create directory if it doesn't exist
$(shell mkdir -p obj)


# -- TARGETS --
# .PHONY tells make that the target is not a file
.PHONY: all clean clear run debug valgrind gdb cppcheck cppclean

# all is the default target
all:			$(TARGET)

# run is a target that runs the executable
run:			all
				@./$(TARGET)

# The executable depends on the object files
$(TARGET):		$(OBJECTS)
				$(CXX) $(C_FLAGS) $(CPP_FLAGS) -o $@ $(OBJECTS)

# The object files depend on the source files and the header files
$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cc $(HEADERS)
				$(CXX) $(C_FLAGS) $(CPP_FLAGS) -c $< -o $@

# clean is a target that removes all the object files and the executable
clean:
				$(if $(wildcard $(OBJECTS)), $(RM) $(OBJECTS))
				$(if $(wildcard $(TARGET)), $(RM) $(TARGET))

# clear is a target that removes all the directories of the compiled files
# check if obj is still existing
clear:			clean
				$(if $(wildcard $(OBJ_DIR)), $(RMDIR) $(OBJ_DIR))

# debug
debug:			$(TARGET)

# valgrind is a target that runs the executable with valgrind
valgrind:		clean debug
				valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# gdb is a target that runs the executable with gdb
gdb:			clean debug
				gdb ./$(TARGET) -ex "run" -ex "bt" -ex "quit"

# sudo apt-get install cppcheck
# cppcheck is a target that runs cppcheck
cppcheck:		clean debug
				cppcheck --language=c++ -$(C_VERSION) --enable=all\
				--library=posix --inconclusive --suppress=missingIncludeSystem .

# sudo apt-get install python3-pip
# pip install --upgrade cppclean
# cppclean is a target that runs cppclean
cppclean:		clean debug
				cppclean $(SOURCES) $(HEADERS)


# End of makefile