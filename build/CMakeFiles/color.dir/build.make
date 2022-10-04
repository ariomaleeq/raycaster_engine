# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /home/ario/.local/lib/python2.7/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/ario/.local/lib/python2.7/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ario/cpp/raycaster_engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ario/cpp/raycaster_engine/build

# Include any dependencies generated for this target.
include CMakeFiles/color.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/color.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/color.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/color.dir/flags.make

CMakeFiles/color.dir/src/colorsettings.cpp.o: CMakeFiles/color.dir/flags.make
CMakeFiles/color.dir/src/colorsettings.cpp.o: ../src/colorsettings.cpp
CMakeFiles/color.dir/src/colorsettings.cpp.o: CMakeFiles/color.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ario/cpp/raycaster_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/color.dir/src/colorsettings.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/color.dir/src/colorsettings.cpp.o -MF CMakeFiles/color.dir/src/colorsettings.cpp.o.d -o CMakeFiles/color.dir/src/colorsettings.cpp.o -c /home/ario/cpp/raycaster_engine/src/colorsettings.cpp

CMakeFiles/color.dir/src/colorsettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/color.dir/src/colorsettings.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ario/cpp/raycaster_engine/src/colorsettings.cpp > CMakeFiles/color.dir/src/colorsettings.cpp.i

CMakeFiles/color.dir/src/colorsettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/color.dir/src/colorsettings.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ario/cpp/raycaster_engine/src/colorsettings.cpp -o CMakeFiles/color.dir/src/colorsettings.cpp.s

# Object files for target color
color_OBJECTS = \
"CMakeFiles/color.dir/src/colorsettings.cpp.o"

# External object files for target color
color_EXTERNAL_OBJECTS =

libcolor.a: CMakeFiles/color.dir/src/colorsettings.cpp.o
libcolor.a: CMakeFiles/color.dir/build.make
libcolor.a: CMakeFiles/color.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ario/cpp/raycaster_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcolor.a"
	$(CMAKE_COMMAND) -P CMakeFiles/color.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/color.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/color.dir/build: libcolor.a
.PHONY : CMakeFiles/color.dir/build

CMakeFiles/color.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/color.dir/cmake_clean.cmake
.PHONY : CMakeFiles/color.dir/clean

CMakeFiles/color.dir/depend:
	cd /home/ario/cpp/raycaster_engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ario/cpp/raycaster_engine /home/ario/cpp/raycaster_engine /home/ario/cpp/raycaster_engine/build /home/ario/cpp/raycaster_engine/build /home/ario/cpp/raycaster_engine/build/CMakeFiles/color.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/color.dir/depend

