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
LIB_DIR = lib
BIN_DIR = bin
DEP_DIR = dep
ASM_DIR = asm
# All the files in the include directory
HEADERS = $(wildcard $(INC_DIR)/*.h)
# All the files in the src directory
SOURCES = $(wildcard $(SRC_DIR)/*.cc)
# All the object files
OBJECTS = $(patsubst $(SRC_DIR)/%.cc, $(OBJ_DIR)/%.o, $(SOURCES))
# All the dependencies
DEPENDENCIES = $(patsubst $(SRC_DIR)/%.cc, $(DEP_DIR)/%.d, $(SOURCES))
# All the assembly files
ASSEMBLY = $(patsubst $(SRC_DIR)/%.cc, $(ASM_DIR)/%.s, $(SOURCES))
# The name and directory of the executable
EXECUTABLE = minesweeper
TARGET = $(BIN_DIR)/$(EXECUTABLE)$(EXE)


# -- COMPILER OPTIONS --
# The compiler
# g++     is the GNU C++ compiler
# c++     is the C++ compiler
# clang++ is the Clang C++ compiler`
# g++-8   is the GNU C++ compiler version 8
CXX			= g++

# --- COMPILER FLAGS ---
# Standard C++ version
# -std=c++98 
# -std=c++03 
# -std=c++11 -std=c++0x
# -std=c++14 -std=c++1y
# -std=c++17 -std=c++1z
# -std=c++20 -std=c++2a
# -std=c++23
C_VERSION	= -std=c++17
# Warnings
# -Wall                      All warnings
# -Wextra                    Extra warnings
# -Wpedantic                 Pedantic warnings
# -Werror                    Treat warnings as errors
# -Weffc++                   Effective C++ warnings
# -Wfatal-errors             Treat all warnings as errors
# etc...
WARNINGS	= -Wall -Wextra -Werror -Wpedantic
# Warnings that are disabled
# -Wno-<warning>             Disable a specific warning
# -Wno-unused                        Don't warn about unused variables
# etc...
NO_WARNINGS	= 
# Optimization
# -O0     no optimization
# -O1     optimize
# -O2     optimize more
# -O3     optimize even more
# -Os     optimize for size
# -Ofast  optimize even more
# -Og     optimize debugging
# -O      optimize
OPTIMIZATION	= -O3
# Debugging
# -DNDEBUG remove debugging information
# -DDEBUG  add debugging information
# -g       add debugging information
# -ggdb    add debugging information
# -ggdb3   add debugging information
DEBUG_F		= -ggdb3 -DDEBUG
# Assembly output
# -S       output assembly
ASSEMBLY_F	= -S

# Compiler flags
C_FLAGS		= $(C_VERSION) $(WARNINGS)
# Include flag
CPP_FLAGS	= $(addprefix -I, $(INC_DIR))
# Linker flags / options
# -l<name>           link to library <name>
# -L<path>           search for libraries in <path>
# -Wl,<option>       pass <option> to the linker
# -static            link statically
# -lstdc++fs         link to stdc++fs library
# -lncurses          link to ncurses library
LD_FLAGS	= -lstdc++fs


# -- MAKE DIRECTORIES --
# Create lib directory if it doesn't exist
$(shell mkdir -p lib)
# Create obj directory if it doesn't exist
$(shell mkdir -p obj)
# Create bin directory if it doesn't exist
$(shell mkdir -p bin)
# Create dep directory if it doesn't exist
$(shell mkdir -p dep)
# Create asm directory if it doesn't exist
$(shell mkdir -p asm)


# -- MAKE IF(DEBUG) --
ifdef ENABLE_DEBUG
	C_FLAGS += $(DEBUG_F)
	C_FLAGS += -O0
endif


# -- TARGETS --
# .PHONY tells make that the target is not a file
.PHONY: all clean clear debug run valgrind gdb

# all is the default target
all: 			C_FLAGS += $(OPTIMIZATION)
all:			$(TARGET)

# debug is a target that compiles with debug flags
debug:			C_FLAGS += -g
debug:			$(TARGET)

# run is a target that runs the executable
run:			all
				./$(TARGET)

# valgrind is a target that runs the executable with valgrind
valgrind:		clean debug
				valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# gdb is a target that runs the executable with gdb
gdb:			clean debug
				gdb ./$(TARGET) -ex "run" -ex "bt" -ex "quit"

# sudo apt-get install cppcheck
# cppcheck is a target that runs cppcheck
cppcheck:		clean debug
				cppcheck --language=c++ --std=c++17 --enable=all\
				--library=posix --inconclusive --suppress=missingIncludeSystem .

# sudo apt-get install python3-pip
# pip install --upgrade cppclean
# cppclean is a target that runs cppclean
cppclean:		clean debug
				cppclean $(SOURCES) $(HEADERS)

# sudo apt-get install clang-tidy
# clang-tidy is a target that runs clang-tidy
clang-tidy:		clean debug
				clang-tidy -checks='*' -header-filter='.*' -fix -fix-errors\
				$(SOURCES)

# sudo apt-get install clang-format
# clang-format is a target that runs clang-format
clang-format:	clean debug
				clang-format -i $(SOURCES) $(HEADERS)

# sudo pip3 install cpplint
# cpplint is a target that runs cpplint
cpplint:		clean debug
				cpplint --filter=-legal,-build/c++11 $(SOURCES) $(HEADERS)

# sudo apt-get install vera++
# vera++ is a target that runs vera++
vera++:			clean debug
				vera++ --profile vera++ $(SOURCES) $(HEADERS)

# clean is a target that removes all the 
#  object files, dependencies, and the executable
clean:
				$(RM) $(OBJECTS) $(DEPENDENCIES) $(ASSEMBLY) $(TARGET) 

# clear is a target that removes all the directories of the compiled files
clear:			clean
				$(RMDIR) $(OBJ_DIR) 
				$(RMDIR) $(BIN_DIR)
				$(RMDIR) $(DEP_DIR)
				$(RMDIR) $(ASM_DIR)
				$(RMDIR) $(LIB_DIR)


# The executable depends on the object files
$(TARGET):		$(OBJECTS)
				$(CXX) $(C_FLAGS) $(CPP_FLAGS) -o $@ $(OBJECTS) $(LD_FLAGS)

# The object files depend on the source files and the header files
$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cc $(HEADERS)
				$(CXX) $(C_FLAGS) $(CPP_FLAGS) -S -o $(ASM_DIR)/$*.s $<
				$(CXX) $(C_FLAGS) $(CPP_FLAGS) -c $< -o $@
# FIXME: doesnt give make error


# Include the dependencies
-include $(DEPENDENCIES)

# The dependencies depend on the source files and the header files
$(DEP_DIR)/%.d:	$(SRC_DIR)/%.cc $(HEADERS)
				$(CXX) $(C_FLAGS) $(CPP_FLAGS) -MM -MT $(patsubst $(DEP_DIR)/%.d, $(OBJ_DIR)/%.o, $@) $< -MF $@


# FIXME: gives make error
# asm/main.s:1: *** recipe commences before first target.  Stop.

# Include the assembly files
# -include $(ASSEMBLY)

# The assembly files depend on the source files and the header files
# $(ASM_DIR)/%.s:	$(SRC_DIR)/%.cc $(HEADERS)
#				$(CXX) $(C_FLAGS) $(CPP_FLAGS) -S $< -o $@
#$(ASM_DIR)/%.s:	$(SRC_DIR)/%.cc $(HEADERS)
#				$(CXX) $(C_FLAGS) $(CPP_FLAGS) -S -o $@ $<

# End of makefile