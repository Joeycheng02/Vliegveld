# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/nightnarumi/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/nightnarumi/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nightnarumi/CLionProjects/Vliegveld

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Vliegveld.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Vliegveld.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Vliegveld.dir/flags.make

CMakeFiles/Vliegveld.dir/Airplane.cpp.o: CMakeFiles/Vliegveld.dir/flags.make
CMakeFiles/Vliegveld.dir/Airplane.cpp.o: ../Airplane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Vliegveld.dir/Airplane.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld.dir/Airplane.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/Airplane.cpp

CMakeFiles/Vliegveld.dir/Airplane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld.dir/Airplane.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/Airplane.cpp > CMakeFiles/Vliegveld.dir/Airplane.cpp.i

CMakeFiles/Vliegveld.dir/Airplane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld.dir/Airplane.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/Airplane.cpp -o CMakeFiles/Vliegveld.dir/Airplane.cpp.s

CMakeFiles/Vliegveld.dir/Airplane.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld.dir/Airplane.cpp.o.requires

CMakeFiles/Vliegveld.dir/Airplane.cpp.o.provides: CMakeFiles/Vliegveld.dir/Airplane.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld.dir/build.make CMakeFiles/Vliegveld.dir/Airplane.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld.dir/Airplane.cpp.o.provides

CMakeFiles/Vliegveld.dir/Airplane.cpp.o.provides.build: CMakeFiles/Vliegveld.dir/Airplane.cpp.o


CMakeFiles/Vliegveld.dir/Airport.cpp.o: CMakeFiles/Vliegveld.dir/flags.make
CMakeFiles/Vliegveld.dir/Airport.cpp.o: ../Airport.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Vliegveld.dir/Airport.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld.dir/Airport.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/Airport.cpp

CMakeFiles/Vliegveld.dir/Airport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld.dir/Airport.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/Airport.cpp > CMakeFiles/Vliegveld.dir/Airport.cpp.i

CMakeFiles/Vliegveld.dir/Airport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld.dir/Airport.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/Airport.cpp -o CMakeFiles/Vliegveld.dir/Airport.cpp.s

CMakeFiles/Vliegveld.dir/Airport.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld.dir/Airport.cpp.o.requires

CMakeFiles/Vliegveld.dir/Airport.cpp.o.provides: CMakeFiles/Vliegveld.dir/Airport.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld.dir/build.make CMakeFiles/Vliegveld.dir/Airport.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld.dir/Airport.cpp.o.provides

CMakeFiles/Vliegveld.dir/Airport.cpp.o.provides.build: CMakeFiles/Vliegveld.dir/Airport.cpp.o


CMakeFiles/Vliegveld.dir/main.cpp.o: CMakeFiles/Vliegveld.dir/flags.make
CMakeFiles/Vliegveld.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Vliegveld.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld.dir/main.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/main.cpp

CMakeFiles/Vliegveld.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/main.cpp > CMakeFiles/Vliegveld.dir/main.cpp.i

CMakeFiles/Vliegveld.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/main.cpp -o CMakeFiles/Vliegveld.dir/main.cpp.s

CMakeFiles/Vliegveld.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld.dir/main.cpp.o.requires

CMakeFiles/Vliegveld.dir/main.cpp.o.provides: CMakeFiles/Vliegveld.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld.dir/build.make CMakeFiles/Vliegveld.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld.dir/main.cpp.o.provides

CMakeFiles/Vliegveld.dir/main.cpp.o.provides.build: CMakeFiles/Vliegveld.dir/main.cpp.o


CMakeFiles/Vliegveld.dir/Runway.cpp.o: CMakeFiles/Vliegveld.dir/flags.make
CMakeFiles/Vliegveld.dir/Runway.cpp.o: ../Runway.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Vliegveld.dir/Runway.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld.dir/Runway.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/Runway.cpp

CMakeFiles/Vliegveld.dir/Runway.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld.dir/Runway.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/Runway.cpp > CMakeFiles/Vliegveld.dir/Runway.cpp.i

CMakeFiles/Vliegveld.dir/Runway.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld.dir/Runway.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/Runway.cpp -o CMakeFiles/Vliegveld.dir/Runway.cpp.s

CMakeFiles/Vliegveld.dir/Runway.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld.dir/Runway.cpp.o.requires

CMakeFiles/Vliegveld.dir/Runway.cpp.o.provides: CMakeFiles/Vliegveld.dir/Runway.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld.dir/build.make CMakeFiles/Vliegveld.dir/Runway.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld.dir/Runway.cpp.o.provides

CMakeFiles/Vliegveld.dir/Runway.cpp.o.provides.build: CMakeFiles/Vliegveld.dir/Runway.cpp.o


CMakeFiles/Vliegveld.dir/tinystr.cpp.o: CMakeFiles/Vliegveld.dir/flags.make
CMakeFiles/Vliegveld.dir/tinystr.cpp.o: ../tinystr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Vliegveld.dir/tinystr.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld.dir/tinystr.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/tinystr.cpp

CMakeFiles/Vliegveld.dir/tinystr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld.dir/tinystr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/tinystr.cpp > CMakeFiles/Vliegveld.dir/tinystr.cpp.i

CMakeFiles/Vliegveld.dir/tinystr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld.dir/tinystr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/tinystr.cpp -o CMakeFiles/Vliegveld.dir/tinystr.cpp.s

CMakeFiles/Vliegveld.dir/tinystr.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld.dir/tinystr.cpp.o.requires

CMakeFiles/Vliegveld.dir/tinystr.cpp.o.provides: CMakeFiles/Vliegveld.dir/tinystr.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld.dir/build.make CMakeFiles/Vliegveld.dir/tinystr.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld.dir/tinystr.cpp.o.provides

CMakeFiles/Vliegveld.dir/tinystr.cpp.o.provides.build: CMakeFiles/Vliegveld.dir/tinystr.cpp.o


CMakeFiles/Vliegveld.dir/tinyxml.cpp.o: CMakeFiles/Vliegveld.dir/flags.make
CMakeFiles/Vliegveld.dir/tinyxml.cpp.o: ../tinyxml.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Vliegveld.dir/tinyxml.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld.dir/tinyxml.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/tinyxml.cpp

CMakeFiles/Vliegveld.dir/tinyxml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld.dir/tinyxml.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/tinyxml.cpp > CMakeFiles/Vliegveld.dir/tinyxml.cpp.i

CMakeFiles/Vliegveld.dir/tinyxml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld.dir/tinyxml.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/tinyxml.cpp -o CMakeFiles/Vliegveld.dir/tinyxml.cpp.s

CMakeFiles/Vliegveld.dir/tinyxml.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld.dir/tinyxml.cpp.o.requires

CMakeFiles/Vliegveld.dir/tinyxml.cpp.o.provides: CMakeFiles/Vliegveld.dir/tinyxml.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld.dir/build.make CMakeFiles/Vliegveld.dir/tinyxml.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld.dir/tinyxml.cpp.o.provides

CMakeFiles/Vliegveld.dir/tinyxml.cpp.o.provides.build: CMakeFiles/Vliegveld.dir/tinyxml.cpp.o


CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.o: CMakeFiles/Vliegveld.dir/flags.make
CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.o: ../tinyxmlerror.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/tinyxmlerror.cpp

CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/tinyxmlerror.cpp > CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.i

CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/tinyxmlerror.cpp -o CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.s

CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.o.requires

CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.o.provides: CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld.dir/build.make CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.o.provides

CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.o.provides.build: CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.o


CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.o: CMakeFiles/Vliegveld.dir/flags.make
CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.o: ../tinyxmlparser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/tinyxmlparser.cpp

CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/tinyxmlparser.cpp > CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.i

CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/tinyxmlparser.cpp -o CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.s

CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.o.requires

CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.o.provides: CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld.dir/build.make CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.o.provides

CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.o.provides.build: CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.o


CMakeFiles/Vliegveld.dir/Gate.cpp.o: CMakeFiles/Vliegveld.dir/flags.make
CMakeFiles/Vliegveld.dir/Gate.cpp.o: ../Gate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Vliegveld.dir/Gate.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld.dir/Gate.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/Gate.cpp

CMakeFiles/Vliegveld.dir/Gate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld.dir/Gate.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/Gate.cpp > CMakeFiles/Vliegveld.dir/Gate.cpp.i

CMakeFiles/Vliegveld.dir/Gate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld.dir/Gate.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/Gate.cpp -o CMakeFiles/Vliegveld.dir/Gate.cpp.s

CMakeFiles/Vliegveld.dir/Gate.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld.dir/Gate.cpp.o.requires

CMakeFiles/Vliegveld.dir/Gate.cpp.o.provides: CMakeFiles/Vliegveld.dir/Gate.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld.dir/build.make CMakeFiles/Vliegveld.dir/Gate.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld.dir/Gate.cpp.o.provides

CMakeFiles/Vliegveld.dir/Gate.cpp.o.provides.build: CMakeFiles/Vliegveld.dir/Gate.cpp.o


CMakeFiles/Vliegveld.dir/Simulation.cpp.o: CMakeFiles/Vliegveld.dir/flags.make
CMakeFiles/Vliegveld.dir/Simulation.cpp.o: ../Simulation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Vliegveld.dir/Simulation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld.dir/Simulation.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/Simulation.cpp

CMakeFiles/Vliegveld.dir/Simulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld.dir/Simulation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/Simulation.cpp > CMakeFiles/Vliegveld.dir/Simulation.cpp.i

CMakeFiles/Vliegveld.dir/Simulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld.dir/Simulation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/Simulation.cpp -o CMakeFiles/Vliegveld.dir/Simulation.cpp.s

CMakeFiles/Vliegveld.dir/Simulation.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld.dir/Simulation.cpp.o.requires

CMakeFiles/Vliegveld.dir/Simulation.cpp.o.provides: CMakeFiles/Vliegveld.dir/Simulation.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld.dir/build.make CMakeFiles/Vliegveld.dir/Simulation.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld.dir/Simulation.cpp.o.provides

CMakeFiles/Vliegveld.dir/Simulation.cpp.o.provides.build: CMakeFiles/Vliegveld.dir/Simulation.cpp.o


# Object files for target Vliegveld
Vliegveld_OBJECTS = \
"CMakeFiles/Vliegveld.dir/Airplane.cpp.o" \
"CMakeFiles/Vliegveld.dir/Airport.cpp.o" \
"CMakeFiles/Vliegveld.dir/main.cpp.o" \
"CMakeFiles/Vliegveld.dir/Runway.cpp.o" \
"CMakeFiles/Vliegveld.dir/tinystr.cpp.o" \
"CMakeFiles/Vliegveld.dir/tinyxml.cpp.o" \
"CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.o" \
"CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.o" \
"CMakeFiles/Vliegveld.dir/Gate.cpp.o" \
"CMakeFiles/Vliegveld.dir/Simulation.cpp.o"

# External object files for target Vliegveld
Vliegveld_EXTERNAL_OBJECTS =

Vliegveld: CMakeFiles/Vliegveld.dir/Airplane.cpp.o
Vliegveld: CMakeFiles/Vliegveld.dir/Airport.cpp.o
Vliegveld: CMakeFiles/Vliegveld.dir/main.cpp.o
Vliegveld: CMakeFiles/Vliegveld.dir/Runway.cpp.o
Vliegveld: CMakeFiles/Vliegveld.dir/tinystr.cpp.o
Vliegveld: CMakeFiles/Vliegveld.dir/tinyxml.cpp.o
Vliegveld: CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.o
Vliegveld: CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.o
Vliegveld: CMakeFiles/Vliegveld.dir/Gate.cpp.o
Vliegveld: CMakeFiles/Vliegveld.dir/Simulation.cpp.o
Vliegveld: CMakeFiles/Vliegveld.dir/build.make
Vliegveld: CMakeFiles/Vliegveld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable Vliegveld"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Vliegveld.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Vliegveld.dir/build: Vliegveld

.PHONY : CMakeFiles/Vliegveld.dir/build

CMakeFiles/Vliegveld.dir/requires: CMakeFiles/Vliegveld.dir/Airplane.cpp.o.requires
CMakeFiles/Vliegveld.dir/requires: CMakeFiles/Vliegveld.dir/Airport.cpp.o.requires
CMakeFiles/Vliegveld.dir/requires: CMakeFiles/Vliegveld.dir/main.cpp.o.requires
CMakeFiles/Vliegveld.dir/requires: CMakeFiles/Vliegveld.dir/Runway.cpp.o.requires
CMakeFiles/Vliegveld.dir/requires: CMakeFiles/Vliegveld.dir/tinystr.cpp.o.requires
CMakeFiles/Vliegveld.dir/requires: CMakeFiles/Vliegveld.dir/tinyxml.cpp.o.requires
CMakeFiles/Vliegveld.dir/requires: CMakeFiles/Vliegveld.dir/tinyxmlerror.cpp.o.requires
CMakeFiles/Vliegveld.dir/requires: CMakeFiles/Vliegveld.dir/tinyxmlparser.cpp.o.requires
CMakeFiles/Vliegveld.dir/requires: CMakeFiles/Vliegveld.dir/Gate.cpp.o.requires
CMakeFiles/Vliegveld.dir/requires: CMakeFiles/Vliegveld.dir/Simulation.cpp.o.requires

.PHONY : CMakeFiles/Vliegveld.dir/requires

CMakeFiles/Vliegveld.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Vliegveld.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Vliegveld.dir/clean

CMakeFiles/Vliegveld.dir/depend:
	cd /home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nightnarumi/CLionProjects/Vliegveld /home/nightnarumi/CLionProjects/Vliegveld /home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug /home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug /home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles/Vliegveld.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Vliegveld.dir/depend

