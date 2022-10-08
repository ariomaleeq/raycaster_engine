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
include CMakeFiles/rayrenderer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/rayrenderer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rayrenderer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rayrenderer.dir/flags.make

CMakeFiles/rayrenderer.dir/src/rayrenderer.cpp.o: CMakeFiles/rayrenderer.dir/flags.make
CMakeFiles/rayrenderer.dir/src/rayrenderer.cpp.o: ../src/rayrenderer.cpp
CMakeFiles/rayrenderer.dir/src/rayrenderer.cpp.o: CMakeFiles/rayrenderer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ario/cpp/raycaster_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rayrenderer.dir/src/rayrenderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rayrenderer.dir/src/rayrenderer.cpp.o -MF CMakeFiles/rayrenderer.dir/src/rayrenderer.cpp.o.d -o CMakeFiles/rayrenderer.dir/src/rayrenderer.cpp.o -c /home/ario/cpp/raycaster_engine/src/rayrenderer.cpp

CMakeFiles/rayrenderer.dir/src/rayrenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rayrenderer.dir/src/rayrenderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ario/cpp/raycaster_engine/src/rayrenderer.cpp > CMakeFiles/rayrenderer.dir/src/rayrenderer.cpp.i

CMakeFiles/rayrenderer.dir/src/rayrenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rayrenderer.dir/src/rayrenderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ario/cpp/raycaster_engine/src/rayrenderer.cpp -o CMakeFiles/rayrenderer.dir/src/rayrenderer.cpp.s

# Object files for target rayrenderer
rayrenderer_OBJECTS = \
"CMakeFiles/rayrenderer.dir/src/rayrenderer.cpp.o"

# External object files for target rayrenderer
rayrenderer_EXTERNAL_OBJECTS =

librayrenderer.a: CMakeFiles/rayrenderer.dir/src/rayrenderer.cpp.o
librayrenderer.a: CMakeFiles/rayrenderer.dir/build.make
librayrenderer.a: CMakeFiles/rayrenderer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ario/cpp/raycaster_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library librayrenderer.a"
	$(CMAKE_COMMAND) -P CMakeFiles/rayrenderer.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rayrenderer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rayrenderer.dir/build: librayrenderer.a
.PHONY : CMakeFiles/rayrenderer.dir/build

CMakeFiles/rayrenderer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rayrenderer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rayrenderer.dir/clean

CMakeFiles/rayrenderer.dir/depend:
	cd /home/ario/cpp/raycaster_engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ario/cpp/raycaster_engine /home/ario/cpp/raycaster_engine /home/ario/cpp/raycaster_engine/build /home/ario/cpp/raycaster_engine/build /home/ario/cpp/raycaster_engine/build/CMakeFiles/rayrenderer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rayrenderer.dir/depend

