# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/maneal/Projects/CPP/stegfil

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maneal/Projects/CPP/stegfil

# Include any dependencies generated for this target.
include CMakeFiles/stegfil.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stegfil.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stegfil.dir/flags.make

CMakeFiles/stegfil.dir/src/bin_op.cpp.o: CMakeFiles/stegfil.dir/flags.make
CMakeFiles/stegfil.dir/src/bin_op.cpp.o: src/bin_op.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maneal/Projects/CPP/stegfil/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stegfil.dir/src/bin_op.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stegfil.dir/src/bin_op.cpp.o -c /home/maneal/Projects/CPP/stegfil/src/bin_op.cpp

CMakeFiles/stegfil.dir/src/bin_op.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stegfil.dir/src/bin_op.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maneal/Projects/CPP/stegfil/src/bin_op.cpp > CMakeFiles/stegfil.dir/src/bin_op.cpp.i

CMakeFiles/stegfil.dir/src/bin_op.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stegfil.dir/src/bin_op.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maneal/Projects/CPP/stegfil/src/bin_op.cpp -o CMakeFiles/stegfil.dir/src/bin_op.cpp.s

# Object files for target stegfil
stegfil_OBJECTS = \
"CMakeFiles/stegfil.dir/src/bin_op.cpp.o"

# External object files for target stegfil
stegfil_EXTERNAL_OBJECTS =

bin/stegfil: CMakeFiles/stegfil.dir/src/bin_op.cpp.o
bin/stegfil: CMakeFiles/stegfil.dir/build.make
bin/stegfil: CMakeFiles/stegfil.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maneal/Projects/CPP/stegfil/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/stegfil"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stegfil.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stegfil.dir/build: bin/stegfil

.PHONY : CMakeFiles/stegfil.dir/build

CMakeFiles/stegfil.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stegfil.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stegfil.dir/clean

CMakeFiles/stegfil.dir/depend:
	cd /home/maneal/Projects/CPP/stegfil && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maneal/Projects/CPP/stegfil /home/maneal/Projects/CPP/stegfil /home/maneal/Projects/CPP/stegfil /home/maneal/Projects/CPP/stegfil /home/maneal/Projects/CPP/stegfil/CMakeFiles/stegfil.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stegfil.dir/depend
