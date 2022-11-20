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
BIN_DIR = bin
# All the files in the include directory
HEADERS = $(wildcard $(INC_DIR)/*.h)
# All the files in the src directory
SOURCES = $(wildcard $(SRC_DIR)/*.cc)
# All the object files
OBJECTS = $(patsubst $(SRC_DIR)/%.cc, $(OBJ_DIR)/%.o, $(SOURCES))
# The name and directory of the executable
EXECUTABLE = minesweeper
TARGET = $(BIN_DIR)/$(EXECUTABLE)$(EXE)


# -- MAKE IF(DEBUG) --
ifeq ($(ENABLE_DEBUG),1)
# File directories
LIB_DIR = lib
DEP_DIR = dep
ASM_DIR = asm
# All the files in the lib directory
LIBRARIES = $(wildcard $(LIB_DIR)/*.a)
# All the dependencies
DEPENDENCIES = $(patsubst $(SRC_DIR)/%.cc, $(DEP_DIR)/%.d, $(SOURCES))
# All the assembly files
ASSEMBLY = $(patsubst $(SRC_DIR)/%.cc, $(ASM_DIR)/%.s, $(SOURCES))
endif


# -- COMPILER OPTIONS --
CXX			= g++

# --- COMPILER FLAGS ---
C_VERSION			= -std=c++17
WARNINGS			= -Wall -Wextra -Werror -Wpedantic
DISABLE_WARNINGS	= 

# Compiler flags
C_FLAGS		= $(C_VERSION) $(WARNINGS)
# Include flags
CPP_FLAGS	= $(addprefix -I, $(INC_DIR))
# Linker flags
LD_FLAGS	= -lstdc++fs


# -- MAKE DIRECTORIES --
# Create directory if it doesn't exist
$(shell mkdir -p obj)
$(shell mkdir -p bin)


# -- MAKE IF(DEBUG) --
ifneq ($(ENABLE_DEBUG),1)

OPTIMIZATION	= -O3
DEBUG_F			= -DNDEBUG
C_FLAGS += $(OPTIMIZATION) $(DEBUG_F)

else ifeq ($(ENABLE_DEBUG),1)

# Create directory if it doesn't exist
$(shell mkdir -p lib)
$(shell mkdir -p dep)
$(shell mkdir -p asm)

OPTIMIZATION = -O0
DEBUG_F	= -ggdb3 -DDEBUG -g
ASSEMBLY_F = -S
C_FLAGS += $(OPTIMIZATION) $(DEBUG_F)

endif


# -- TARGETS --
# .PHONY tells make that the target is not a file
.PHONY: all clean clear run debug valgrind gdb cppcheck cppclean


# Start of normal targets

ifneq ($(ENABLE_DEBUG),1)

# all is the default target
all:			$(TARGET)

# run is a target that runs the executable
run:			all
				./$(TARGET)

# clean is a target that removes all the 
#  object files, dependencies, and the executable
clean:
				$(RM) $(OBJECTS) $(TARGET) 

# clear is a target that removes all the directories of the compiled files
clear:			clean
				$(RMDIR) $(OBJ_DIR) 
				$(RMDIR) $(BIN_DIR)

# The executable depends on the object files
$(TARGET):		$(OBJECTS)
				$(CXX) $(C_FLAGS) $(CPP_FLAGS) -o $@ $(OBJECTS) $(LD_FLAGS)

# The object files depend on the source files and the header files
$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cc $(HEADERS)
				$(CXX) $(C_FLAGS) $(CPP_FLAGS) -c $< -o $@

# End of normal targets





# Start of debug targets

else ifeq ($(ENABLE_DEBUG),1)
# debug is a target that compiles with debug flags
debug:			$(TARGET)

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
				$(CXX) $(C_FLAGS) $(CPP_FLAGS) -MM -MT\
				$(patsubst $(DEP_DIR)/%.d, $(OBJ_DIR)/%.o, $@) $< -MF $@


# FIXME: gives make error
# asm/main.s:1: *** recipe commences before first target.  Stop.

# Include the assembly files
# -include $(ASSEMBLY)

# The assembly files depend on the source files and the header files
# $(ASM_DIR)/%.s:	$(SRC_DIR)/%.cc $(HEADERS)
#				$(CXX) $(C_FLAGS) $(CPP_FLAGS) -S $< -o $@
#$(ASM_DIR)/%.s:	$(SRC_DIR)/%.cc $(HEADERS)
#				$(CXX) $(C_FLAGS) $(CPP_FLAGS) -S -o $@ $<

endif

# End of debug targets

# End of makefile