# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/adam/workspace/openGL/games/engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adam/workspace/openGL/games/engine

# Include any dependencies generated for this target.
include bin2/CMakeFiles/glew_s.dir/depend.make

# Include the progress variables for this target.
include bin2/CMakeFiles/glew_s.dir/progress.make

# Include the compile flags for this target's objects.
include bin2/CMakeFiles/glew_s.dir/flags.make

bin2/CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.o: bin2/CMakeFiles/glew_s.dir/flags.make
bin2/CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.o: /usr/include/glew/src/glew.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/workspace/openGL/games/engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object bin2/CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.o"
	cd /home/adam/workspace/openGL/games/engine/bin2 && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.o   -c /usr/include/glew/src/glew.c

bin2/CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.i"
	cd /home/adam/workspace/openGL/games/engine/bin2 && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /usr/include/glew/src/glew.c > CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.i

bin2/CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.s"
	cd /home/adam/workspace/openGL/games/engine/bin2 && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /usr/include/glew/src/glew.c -o CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.s

bin2/CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.o.requires:

.PHONY : bin2/CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.o.requires

bin2/CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.o.provides: bin2/CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.o.requires
	$(MAKE) -f bin2/CMakeFiles/glew_s.dir/build.make bin2/CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.o.provides.build
.PHONY : bin2/CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.o.provides

bin2/CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.o.provides.build: bin2/CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.o


# Object files for target glew_s
glew_s_OBJECTS = \
"CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.o"

# External object files for target glew_s
glew_s_EXTERNAL_OBJECTS =

lib/libGLEW.a: bin2/CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.o
lib/libGLEW.a: bin2/CMakeFiles/glew_s.dir/build.make
lib/libGLEW.a: bin2/CMakeFiles/glew_s.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adam/workspace/openGL/games/engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library ../lib/libGLEW.a"
	cd /home/adam/workspace/openGL/games/engine/bin2 && $(CMAKE_COMMAND) -P CMakeFiles/glew_s.dir/cmake_clean_target.cmake
	cd /home/adam/workspace/openGL/games/engine/bin2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glew_s.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin2/CMakeFiles/glew_s.dir/build: lib/libGLEW.a

.PHONY : bin2/CMakeFiles/glew_s.dir/build

bin2/CMakeFiles/glew_s.dir/requires: bin2/CMakeFiles/glew_s.dir/usr/include/glew/src/glew.c.o.requires

.PHONY : bin2/CMakeFiles/glew_s.dir/requires

bin2/CMakeFiles/glew_s.dir/clean:
	cd /home/adam/workspace/openGL/games/engine/bin2 && $(CMAKE_COMMAND) -P CMakeFiles/glew_s.dir/cmake_clean.cmake
.PHONY : bin2/CMakeFiles/glew_s.dir/clean

bin2/CMakeFiles/glew_s.dir/depend:
	cd /home/adam/workspace/openGL/games/engine && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adam/workspace/openGL/games/engine /usr/include/glew/build/cmake /home/adam/workspace/openGL/games/engine /home/adam/workspace/openGL/games/engine/bin2 /home/adam/workspace/openGL/games/engine/bin2/CMakeFiles/glew_s.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin2/CMakeFiles/glew_s.dir/depend

