# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /nix/store/0s8gvg6nh3d3cbby1hjf69jfb2xdvbvp-cmake-3.25.3/bin/cmake

# The command to remove a file.
RM = /nix/store/0s8gvg6nh3d3cbby1hjf69jfb2xdvbvp-cmake-3.25.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aki/Projects/cpe211

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aki/Projects/cpe211/bin

# Include any dependencies generated for this target.
include CMakeFiles/act11.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/act11.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/act11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/act11.dir/flags.make

CMakeFiles/act11.dir/src/act11.cpp.o: CMakeFiles/act11.dir/flags.make
CMakeFiles/act11.dir/src/act11.cpp.o: /home/aki/Projects/cpe211/src/act11.cpp
CMakeFiles/act11.dir/src/act11.cpp.o: CMakeFiles/act11.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aki/Projects/cpe211/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/act11.dir/src/act11.cpp.o"
	/nix/store/lcf37pgp3rgww67v9x2990hbfwx96c1w-gcc-wrapper-12.2.0/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/act11.dir/src/act11.cpp.o -MF CMakeFiles/act11.dir/src/act11.cpp.o.d -o CMakeFiles/act11.dir/src/act11.cpp.o -c /home/aki/Projects/cpe211/src/act11.cpp

CMakeFiles/act11.dir/src/act11.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/act11.dir/src/act11.cpp.i"
	/nix/store/lcf37pgp3rgww67v9x2990hbfwx96c1w-gcc-wrapper-12.2.0/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aki/Projects/cpe211/src/act11.cpp > CMakeFiles/act11.dir/src/act11.cpp.i

CMakeFiles/act11.dir/src/act11.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/act11.dir/src/act11.cpp.s"
	/nix/store/lcf37pgp3rgww67v9x2990hbfwx96c1w-gcc-wrapper-12.2.0/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aki/Projects/cpe211/src/act11.cpp -o CMakeFiles/act11.dir/src/act11.cpp.s

# Object files for target act11
act11_OBJECTS = \
"CMakeFiles/act11.dir/src/act11.cpp.o"

# External object files for target act11
act11_EXTERNAL_OBJECTS =

act11: CMakeFiles/act11.dir/src/act11.cpp.o
act11: CMakeFiles/act11.dir/build.make
act11: /nix/store/i6y3vfw18aygsivl29fk7y0pb153j571-ncurses-6.4/lib/libncurses.so
act11: /nix/store/i6y3vfw18aygsivl29fk7y0pb153j571-ncurses-6.4/lib/libform.so
act11: CMakeFiles/act11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aki/Projects/cpe211/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable act11"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/act11.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/act11.dir/build: act11
.PHONY : CMakeFiles/act11.dir/build

CMakeFiles/act11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/act11.dir/cmake_clean.cmake
.PHONY : CMakeFiles/act11.dir/clean

CMakeFiles/act11.dir/depend:
	cd /home/aki/Projects/cpe211/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aki/Projects/cpe211 /home/aki/Projects/cpe211 /home/aki/Projects/cpe211/bin /home/aki/Projects/cpe211/bin /home/aki/Projects/cpe211/bin/CMakeFiles/act11.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/act11.dir/depend

