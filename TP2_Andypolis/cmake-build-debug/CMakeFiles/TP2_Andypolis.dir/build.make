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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/h/My Drive/1 Anio/Algo y Programacion 2/TP2_Andypolis"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/h/My Drive/1 Anio/Algo y Programacion 2/TP2_Andypolis/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/TP2_Andypolis.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/TP2_Andypolis.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP2_Andypolis.dir/flags.make

CMakeFiles/TP2_Andypolis.dir/juego.cpp.o: CMakeFiles/TP2_Andypolis.dir/flags.make
CMakeFiles/TP2_Andypolis.dir/juego.cpp.o: ../juego.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/h/My Drive/1 Anio/Algo y Programacion 2/TP2_Andypolis/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TP2_Andypolis.dir/juego.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP2_Andypolis.dir/juego.cpp.o -c "/mnt/h/My Drive/1 Anio/Algo y Programacion 2/TP2_Andypolis/juego.cpp"

CMakeFiles/TP2_Andypolis.dir/juego.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP2_Andypolis.dir/juego.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/h/My Drive/1 Anio/Algo y Programacion 2/TP2_Andypolis/juego.cpp" > CMakeFiles/TP2_Andypolis.dir/juego.cpp.i

CMakeFiles/TP2_Andypolis.dir/juego.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP2_Andypolis.dir/juego.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/h/My Drive/1 Anio/Algo y Programacion 2/TP2_Andypolis/juego.cpp" -o CMakeFiles/TP2_Andypolis.dir/juego.cpp.s

CMakeFiles/TP2_Andypolis.dir/main.cpp.o: CMakeFiles/TP2_Andypolis.dir/flags.make
CMakeFiles/TP2_Andypolis.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/h/My Drive/1 Anio/Algo y Programacion 2/TP2_Andypolis/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TP2_Andypolis.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP2_Andypolis.dir/main.cpp.o -c "/mnt/h/My Drive/1 Anio/Algo y Programacion 2/TP2_Andypolis/main.cpp"

CMakeFiles/TP2_Andypolis.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP2_Andypolis.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/h/My Drive/1 Anio/Algo y Programacion 2/TP2_Andypolis/main.cpp" > CMakeFiles/TP2_Andypolis.dir/main.cpp.i

CMakeFiles/TP2_Andypolis.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP2_Andypolis.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/h/My Drive/1 Anio/Algo y Programacion 2/TP2_Andypolis/main.cpp" -o CMakeFiles/TP2_Andypolis.dir/main.cpp.s

# Object files for target TP2_Andypolis
TP2_Andypolis_OBJECTS = \
"CMakeFiles/TP2_Andypolis.dir/juego.cpp.o" \
"CMakeFiles/TP2_Andypolis.dir/main.cpp.o"

# External object files for target TP2_Andypolis
TP2_Andypolis_EXTERNAL_OBJECTS =

TP2_Andypolis: CMakeFiles/TP2_Andypolis.dir/juego.cpp.o
TP2_Andypolis: CMakeFiles/TP2_Andypolis.dir/main.cpp.o
TP2_Andypolis: CMakeFiles/TP2_Andypolis.dir/build.make
TP2_Andypolis: CMakeFiles/TP2_Andypolis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/h/My Drive/1 Anio/Algo y Programacion 2/TP2_Andypolis/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TP2_Andypolis"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP2_Andypolis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TP2_Andypolis.dir/build: TP2_Andypolis
.PHONY : CMakeFiles/TP2_Andypolis.dir/build

CMakeFiles/TP2_Andypolis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TP2_Andypolis.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TP2_Andypolis.dir/clean

CMakeFiles/TP2_Andypolis.dir/depend:
	cd "/mnt/h/My Drive/1 Anio/Algo y Programacion 2/TP2_Andypolis/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/h/My Drive/1 Anio/Algo y Programacion 2/TP2_Andypolis" "/mnt/h/My Drive/1 Anio/Algo y Programacion 2/TP2_Andypolis" "/mnt/h/My Drive/1 Anio/Algo y Programacion 2/TP2_Andypolis/cmake-build-debug" "/mnt/h/My Drive/1 Anio/Algo y Programacion 2/TP2_Andypolis/cmake-build-debug" "/mnt/h/My Drive/1 Anio/Algo y Programacion 2/TP2_Andypolis/cmake-build-debug/CMakeFiles/TP2_Andypolis.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TP2_Andypolis.dir/depend
