# CHEATSHEET for C++ project

Frequently used commands for C++ projects.

## Index

1. [MAKEFILE](#makefile)
    1. [Compiler options](#compiler-options)
        1. [Compiler](#compiler)
    2. [Compiler flags](#compiler-flags)
        1. [C++ version](#c-version)
        2. [Warnings](#warnings)
        3. [No warnings](#no-warnings)
        4. [Optimization](#optimization)
        5. [Debugging](#debugging)
        6. [Output](#output)
        7. [Profiling](#profiling)
        8. [Preprocessor](#preprocessor)
            1. [Extra preprocessor flags](#extra-preprocessor-options)
        9. [Linker](#linker)
    3. [Other options](#other-options)
        1. [Automatic variables](#automatic-variables)
        2. [Variables](#variables)
        3. [Functions](#functions)
        4. [Conditionals](#conditionals)
        5. [Loops](#loops)
        6. [Rules](#rules)
        7. [Phony targets](#phony-targets)
        8. [Include](#include)
        9. [Pattern rules](#pattern-rules)
            1. [Pattern rules with multiple prerequisites](#pattern-rules-with-multiple-prerequisites)
            2. [Pattern rules with multiple targets](#pattern-rules-with-multiple-targets)
        10. [Pattern-specific variables](#pattern-specific-variables)
        11. [Other](#other)
2. [C++](#c)
3. [C++11](#c11)
4. [C++14](#c14)
5. [C++17](#c17)
6. [C++20](#c20)
7. [C++23](#c23)

## MAKEFILE

### Compiler options

#### Compiler

- `g++`     - GNU C++ compiler
- `g++-8`   - GNU C++ compiler version 8
- `c++`     - C++ compiler
- `clang++` - LLVM C++ compiler
- `icc`     - Intel C++ compiler
- `icpc`    - Intel C++ compiler
- `pgc++`   - Portland Group C++ compiler
- `xlc++`   - IBM XL C++ compiler
- etc... - See [GNU Make](https://www.gnu.org/software/make/manual/make.html#Choosing-the-Compiler), [C++ compilers](https://en.wikipedia.org/wiki/List_of_C%2B%2B_compilers) and [GCC](https://gcc.gnu.org/onlinedocs/gcc/Invoking-GCC.html#Invoking-GCC) for more information.

### Compiler flags

#### C version

All the C++ versions.

- C++98
  - `-std=c++98`
- C++03
  - `-std=c++03`
- C++11
  - `-std=c++11`
  - `-std=c++0x`
- C++14
  - `-std=c++14`
  - `-std=c++1y`
- C++17
  - `-std=c++17`
  - `-std=c++1z`
- C++20
  - `-std=c++20`
  - `-std=c++2a`
- C++23
  - `-std=c++23`
- See [C++ version](https://en.wikipedia.org/wiki/C%2B%2B#Standardization) and [C++ version](https://en.cppreference.com/w/cpp/compiler_support#cpp) for more information.

#### Warnings

- `-Wall` - All warnings
- `-Wextra` - Extra warnings
- `-Wpedantic` - Pedantic warnings
- `-Werror` - Treat warnings as errors
- `-Wfatal-errors` - Treat all errors as fatal
- `-Weffc++` - Effective C++ warnings
- `-Wshadow` - Warn about shadowing
- etc... - See [GCC](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html) and [Clang](https://clang.llvm.org/docs/DiagnosticsReference.html) documentation for more options.

#### No warnings

- `-w` - Disable warnings
- `-Wno-<warning>` - Disable specific warning
- `-Wno-all` - Disable all warnings
- `-Wno-unused` - Disable unused variables warnings
- etc... - See [GCC](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html) and [Clang](https://clang.llvm.org/docs/DiagnosticsReference.html) documentation for more options.

#### Optimization

- `-O0` - No optimization
- `-O1` - Optimize
- `-O2` - Optimize more
- `-O3` - Optimize even more
- `-Ofast` - Optimize even more
- `-Os` - Optimize for size
- `-Og` - Optimize for debugging
- `-O` - Optimize
- etc... - See [GCC](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html) and [Clang](https://clang.llvm.org/docs/CommandGuide/clang.html#optimization-options) documentation for more options.

#### Debugging

- `-g` - Debug
- `-g3` - Debug
- `-g2` - Debug
- `-g1` - Debug
- `-gdb` - Debug
- `-gdb3` - Debug
- `-gdb2` - Debug
- `-gdb1` - Debug
- `-ggdb` - Debug
- `-ggdb3` - Debug
- `-ggdb2` - Debug
- `-ggdb1` - Debug
- `-ggdb0` - Debug
- `-DDEBUG` - Debug
- etc... - See [GCC](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html) and [Clang](https://clang.llvm.org/docs/CommandGuide/clang.html#debugging-options) documentation for more options.

#### Output

- `-o <file>` - Output file
- `-o <dir>/<file>` - Output file in directory
- `-o <dir>/<file>.<ext>` - Output file in directory with extension
- `-o <file>.<ext>` - Output file with extension
- `-o <dir>/` - Output directory
- `-o <dir>` - Output directory
- `-o <file> <file>` - Output multiple files
- `-o <variable>` - Output to variable (holding a file name)
- `-c` - Compile only (no linking)
- `-S` - Compile only and output assembly
- `-E` - Preprocess only
- etc... - See [GCC](https://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html) and [Clang](https://clang.llvm.org/docs/CommandGuide/clang.html#overall-options) documentation for more options.

#### Profiling

- See [GCC](https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html) and [Clang](https://clang.llvm.org/docs/UsersManual.html#profiling-with-instrumentation) documentation for more options.

#### Preprocessor

- `-D<name>` - Define preprocessor macro
- `-D<name>=<value>` - Define preprocessor macro with value
- `-U<name>` - Undefine preprocessor macro
- `-I<dir>` - Add directory to include path
- `-I<dir1>:<dir2>` - Add directories to include path
- `-I<dir1> -I<dir2>` - Add directories to include path
- `-include <file>` - Include file before compilation
- `-include <file1> -include <file2>` - Include files before compilation
- `-M` - Generate dependencies
- `-MM` - Generate dependencies
- `-MF <file>` - Generate dependencies to file
- `-MT <target>` - Generate dependencies with target
- `-MQ <target>` - Generate dependencies with target
- `-MP` - Generate dependencies with phony targets
- `-MD` - Generate dependencies and compile
- `-MMD` - Generate dependencies and compile
- `-MG` - Generate dependencies with missing files
- `-Xpreprocessor` - Pass options to preprocessor
- `-Xpreprocessor <option>` - Pass option to preprocessor
- etc... - See [GCC](https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html) and [Clang](https://clang.llvm.org/docs/UsersManual.html#controlling-diagnostics-preprocessor-and-language-options) documentation for more options.

##### Extra preprocessor options

- `-I <path>` - Include path
- `-I<path>` - Include path
- `-include <file>` - Include file
- `-include <variable>` - Include variable (holding file names)
- `-include <path>` - Include path
- `-include <path/file>` - Include file
- `-include <path/file1> -include <path/file2>` - Include files
- etc... - See [GCC](https://gcc.gnu.org/onlinedocs/gcc/Directory-Options.html) and [Clang](https://clang.llvm.org/docs/CommandGuide/clang.html#preprocessor-options) documentation for more options.

#### Linker

- `-l<library>` - Link library
- `-L<path>` - Link path
- `-l<name>` - Link library
- `-Wl,-rpath=<path>` - Link path
- `-Wl,-rpath-link=<path>` - Link path
- `-Wl,<option>` - Link option
- `-static` - Link statically
- `-lstdc++fs` - Link filesystem library
- `-lstdc++` - Link C++ library
- `-lm` - Link math library
- `-lpthread` - Link pthread library
- `-lncurses` - Link ncurses library
- etc... - See [GCC](https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html) and [Clang](https://clang.llvm.org/docs/CommandGuide/clang.html#linker-options) documentation for more options.

### Other options

#### Automatic variables

- `$@` - Target
- `$<` - First dependency
- `$^` - All dependencies
- `$*` - Target without extension
- etc... - See [GNU Make](https://www.gnu.org/software/make/manual/make.html#Automatic-Variables) documentation for more options.

#### Variables

- `$(VAR)` - Variable
- `$(VAR:pattern=replacement)` - Variable pattern replacement
- `$(VAR:pattern1=replacement1:pattern2=replacement2:...)` - Variable pattern replacement
- etc... - See [GNU Make](https://www.gnu.org/software/make/manual/make.html#Text-Functions) documentation for more options.

#### Functions

- `$(wildcard <pattern>)` - Wildcard pattern
- `$(patsubst <pattern>,<replacement>,<text>)` - Pattern substitution
- `$(dir <names>)` - Directory part of file name
- `$(notdir <names>)` - Non-directory part of file name
- `$(suffix <names>)` - Suffix of file name
- `$(basename <names>)` - Base name of file name
- `$(addsuffix <suffix>,<names>)` - Add suffix to file names
- `$(addprefix <prefix>,<names>)` - Add prefix to file names
- `$(join <list1>,<list2>)` - Join two lists
- `$(sort <list>)` - Sort list
- `$(word <n>,<text>)` - Extract word from text
- `$(words <text>)` - Number of words in text
- `$(wordlist <s>,<e>,<text>)` - Extract words from text
- `$(firstword <names>)` - First word in names
- `$(filter <pattern...>,<text>)` - Filter text
- `$(filter-out <pattern...>,<text>)` - Filter out text
- `$(foreach <var>,<list>,<text>)` - For each in list
- `$(if <condition>,<then-part>,<else-part>)` - If condition
- `$(origin <variable>)` - Origin of variable
- `$(value <variable>)` - Value of variable
- `$(eval <text>)` - Evaluate text
- `$(call <function>,<arg1>,<arg2>,...)` - Call function
- `$(shell <command>)` - Shell command
- `$(warning <text>)` - Warning print
- `$(error <text>)` - Error print
- `$(info <text>)` - Info print
- `$(strip <text>)` - Strip text
- `$(findstring <find>,<in>)` - Find string
- `$(subst <from>,<to>,<text>)` - Substitute string
- `$(abspath <names>)` - Absolute path
- `$(realpath <names>)` - Real path
- etc... - See [GNU Make](https://www.gnu.org/software/make/manual/make.html#Text-Functions) documentation for more options.

#### Conditionals

- `ifeq (<arg1>,<arg2>)` - If equal
- `ifneq (<arg1>,<arg2>)` - If not equal
- `ifdef (<variable>)` - If defined
- `ifndef (<variable>)` - If not defined
- `else` - Else
- `endif` - End if
- `if <condition>` - If condition
- `elif <condition>` - Else if condition
- `else` - Else
- `endif` - End if
- etc... - See [GNU Make](https://www.gnu.org/software/make/manual/make.html#Conditional-Syntax) documentation for more options.

#### Loops

- `foreach <var>,<list>,<text>` - For each in list
- `endef` - End foreach
- `while <condition>` - While condition
- `endef` - End while
- etc... - See [GNU Make](https://www.gnu.org/software/make/manual/make.html#Looping) documentation for more options.

#### Rules

- `define <name>` - Define rule
- `endef` - End define
- `include <file>` - Include file
- `override <variable>` - Override variable
- `export <variable>` - Export variable
- `unexport <variable>` - Unexport variable
- `vpath <pattern> <directories>` - Vpath pattern
- `vpath <pattern>` - Vpath pattern
- `vpath` - Vpath
- etc... - See [GNU Make](https://www.gnu.org/software/make/manual/make.html#Rules) documentation for more options.

#### Phony targets

- `.PHONY: <target>` - Phony target
- `.PHONY: <target1> <target2> <target3>` - Phony targets
- etc... - See [GNU Make](https://www.gnu.org/software/make/manual/make.html#Phony-Targets) documentation for more options.

#### Include

- `include <file>` - Include file
- `include <file1> <file2> <file3>` - Include files
- etc... - See [GNU Make](https://www.gnu.org/software/make/manual/make.html#Include) documentation for more options.

#### Pattern rules

- `<target>: <prerequisites>` - Pattern rule
- etc... - See [GNU Make](https://www.gnu.org/software/make/manual/make.html#Pattern-Rules) documentation for more options.

##### Pattern rules with multiple prerequisites

- `<target>: <prerequisite1> <prerequisite2> <prerequisite3>` - Pattern rule with multiple prerequisites
- etc... - See [GNU Make](https://www.gnu.org/software/make/manual/make.html#Multiple-Prerequisites) documentation for more options.

##### Pattern rules with multiple targets

- `<target1> <target2> <target3>: <prerequisite>` - Pattern rule with multiple targets
- etc... - See [GNU Make](https://www.gnu.org/software/make/manual/make.html#Multiple-Targets) documentation for more options.

#### Pattern-specific variables

- `<pattern>: <variable-assignment>` - Pattern-specific variable
- etc... - See [GNU Make](https://www.gnu.org/software/make/manual/make.html#Pattern_002dspecific) documentation for more options.

#### Other

- See [GCC](https://gcc.gnu.org/onlinedocs/gcc/) documentation for more options.
- See [Clang](https://clang.llvm.org/docs/ClangTools.html) documentation for more options (Clang tools).
- See [Clang](https://clang.llvm.org/docs/ClangCommandLineReference.html) documentation for more options (command line reference).
- See [GNU Make](https://www.gnu.org/software/make/manual/make.html) documentation for more options.
- See [GNU Make](https://www.gnu.org/software/make/manual/make.html#Options-Summary) documentation for more options (summary).
- See [CMake](https://cmake.org/cmake/help/latest/manual/cmake-language.7.html) documentation for more options (language).
- See [LLVM](https://llvm.org/docs/CommandGuide/llvm.html) documentation for more options (command line reference).

## C

## C11

## C14

## C17

## C20

## C23
