# Start of makefile

# -- TERMINAL --
RM = rm -f
RMDIR = rm -rf

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
# The name of the executable
EXECUTABLE = minesweeper
# The destination of the executable
TARGET = $(EXECUTABLE)

# -- COMPILER OPTIONS --
CXX					= g++
C_VERSION			= -std=c++17
WARNINGS			= -Wall -Wextra -Werror -Wpedantic -Weffc++
DISABLE_WARNINGS	= 
OPTIMIZATION 		= -O0
DEBUG_F				= -ggdb3 -DDEBUG -g
CXXFLAGS			= $(C_VERSION) $(WARNINGS) $(OPTIMIZATION) $(DEBUG_F)
INCLUDE_FLAGS		= $(addprefix -I, $(INC_DIR))

# -- MAKE DIRECTORIES --
# Create directory if it doesn't exist
$(shell mkdir -p obj)

# -- TARGETS --
# .PHONY tells make that the target is not a file
.PHONY: all clean clear run valgrind gdb cppcheck cppclean

# all is the default target
all:			$(TARGET)

# run is a target that runs the executable
run:			all
				@./$(TARGET)

# The executable depends on the object files
$(TARGET):		$(OBJECTS)
				$(CXX) $(CXXFLAGS) $(INCLUDE_FLAGS) -o $@ $(OBJECTS)

# The object files depend on the source files and the header files
$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cc $(HEADERS)
				$(CXX) $(CXXFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

# clean is a target that removes all the object files and the executable
clean:
				$(if $(wildcard $(OBJECTS)), $(RM) $(OBJECTS))
				$(if $(wildcard $(TARGET)), $(RM) $(TARGET))

# clear is a target that removes all the directories of the compiled files
clear:			clean
				$(if $(wildcard $(OBJ_DIR)), $(RMDIR) $(OBJ_DIR))

# valgrind is a target that runs the executable with valgrind
valgrind:		clean all
				valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# gdb is a target that runs the executable with gdb
gdb:			clean all
				gdb ./$(TARGET) -ex "run" -ex "bt" -ex "quit"

# sudo apt-get install cppcheck
# cppcheck is a target that runs cppcheck
cppcheck:		clean all
				cppcheck --language=c++ -$(C_VERSION) --enable=all\
				--library=posix --inconclusive --suppress=missingIncludeSystem .

# sudo apt-get install python3-pip
# pip install --upgrade cppclean
# cppclean is a target that runs cppclean
cppclean:		clean all
				cppclean $(SOURCES) $(HEADERS)

# End of makefile