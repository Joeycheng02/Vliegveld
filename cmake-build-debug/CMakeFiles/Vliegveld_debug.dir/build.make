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
include CMakeFiles/Vliegveld_debug.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Vliegveld_debug.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Vliegveld_debug.dir/flags.make

CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.o: CMakeFiles/Vliegveld_debug.dir/flags.make
CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.o: ../Airplane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/Airplane.cpp

CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/Airplane.cpp > CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.i

CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/Airplane.cpp -o CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.s

CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.o.requires

CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.o.provides: CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld_debug.dir/build.make CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.o.provides

CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.o.provides.build: CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.o


CMakeFiles/Vliegveld_debug.dir/Airport.cpp.o: CMakeFiles/Vliegveld_debug.dir/flags.make
CMakeFiles/Vliegveld_debug.dir/Airport.cpp.o: ../Airport.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Vliegveld_debug.dir/Airport.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld_debug.dir/Airport.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/Airport.cpp

CMakeFiles/Vliegveld_debug.dir/Airport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld_debug.dir/Airport.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/Airport.cpp > CMakeFiles/Vliegveld_debug.dir/Airport.cpp.i

CMakeFiles/Vliegveld_debug.dir/Airport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld_debug.dir/Airport.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/Airport.cpp -o CMakeFiles/Vliegveld_debug.dir/Airport.cpp.s

CMakeFiles/Vliegveld_debug.dir/Airport.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld_debug.dir/Airport.cpp.o.requires

CMakeFiles/Vliegveld_debug.dir/Airport.cpp.o.provides: CMakeFiles/Vliegveld_debug.dir/Airport.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld_debug.dir/build.make CMakeFiles/Vliegveld_debug.dir/Airport.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld_debug.dir/Airport.cpp.o.provides

CMakeFiles/Vliegveld_debug.dir/Airport.cpp.o.provides.build: CMakeFiles/Vliegveld_debug.dir/Airport.cpp.o


CMakeFiles/Vliegveld_debug.dir/Runway.cpp.o: CMakeFiles/Vliegveld_debug.dir/flags.make
CMakeFiles/Vliegveld_debug.dir/Runway.cpp.o: ../Runway.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Vliegveld_debug.dir/Runway.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld_debug.dir/Runway.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/Runway.cpp

CMakeFiles/Vliegveld_debug.dir/Runway.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld_debug.dir/Runway.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/Runway.cpp > CMakeFiles/Vliegveld_debug.dir/Runway.cpp.i

CMakeFiles/Vliegveld_debug.dir/Runway.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld_debug.dir/Runway.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/Runway.cpp -o CMakeFiles/Vliegveld_debug.dir/Runway.cpp.s

CMakeFiles/Vliegveld_debug.dir/Runway.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld_debug.dir/Runway.cpp.o.requires

CMakeFiles/Vliegveld_debug.dir/Runway.cpp.o.provides: CMakeFiles/Vliegveld_debug.dir/Runway.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld_debug.dir/build.make CMakeFiles/Vliegveld_debug.dir/Runway.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld_debug.dir/Runway.cpp.o.provides

CMakeFiles/Vliegveld_debug.dir/Runway.cpp.o.provides.build: CMakeFiles/Vliegveld_debug.dir/Runway.cpp.o


CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.o: CMakeFiles/Vliegveld_debug.dir/flags.make
CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.o: ../tinystr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/tinystr.cpp

CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/tinystr.cpp > CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.i

CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/tinystr.cpp -o CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.s

CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.o.requires

CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.o.provides: CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld_debug.dir/build.make CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.o.provides

CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.o.provides.build: CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.o


CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.o: CMakeFiles/Vliegveld_debug.dir/flags.make
CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.o: ../tinyxml.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/tinyxml.cpp

CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/tinyxml.cpp > CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.i

CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/tinyxml.cpp -o CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.s

CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.o.requires

CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.o.provides: CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld_debug.dir/build.make CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.o.provides

CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.o.provides.build: CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.o


CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.o: CMakeFiles/Vliegveld_debug.dir/flags.make
CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.o: ../tinyxmlerror.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/tinyxmlerror.cpp

CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/tinyxmlerror.cpp > CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.i

CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/tinyxmlerror.cpp -o CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.s

CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.o.requires

CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.o.provides: CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld_debug.dir/build.make CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.o.provides

CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.o.provides.build: CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.o


CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.o: CMakeFiles/Vliegveld_debug.dir/flags.make
CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.o: ../tinyxmlparser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/tinyxmlparser.cpp

CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/tinyxmlparser.cpp > CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.i

CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/tinyxmlparser.cpp -o CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.s

CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.o.requires

CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.o.provides: CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld_debug.dir/build.make CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.o.provides

CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.o.provides.build: CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.o


CMakeFiles/Vliegveld_debug.dir/Gate.cpp.o: CMakeFiles/Vliegveld_debug.dir/flags.make
CMakeFiles/Vliegveld_debug.dir/Gate.cpp.o: ../Gate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Vliegveld_debug.dir/Gate.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld_debug.dir/Gate.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/Gate.cpp

CMakeFiles/Vliegveld_debug.dir/Gate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld_debug.dir/Gate.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/Gate.cpp > CMakeFiles/Vliegveld_debug.dir/Gate.cpp.i

CMakeFiles/Vliegveld_debug.dir/Gate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld_debug.dir/Gate.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/Gate.cpp -o CMakeFiles/Vliegveld_debug.dir/Gate.cpp.s

CMakeFiles/Vliegveld_debug.dir/Gate.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld_debug.dir/Gate.cpp.o.requires

CMakeFiles/Vliegveld_debug.dir/Gate.cpp.o.provides: CMakeFiles/Vliegveld_debug.dir/Gate.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld_debug.dir/build.make CMakeFiles/Vliegveld_debug.dir/Gate.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld_debug.dir/Gate.cpp.o.provides

CMakeFiles/Vliegveld_debug.dir/Gate.cpp.o.provides.build: CMakeFiles/Vliegveld_debug.dir/Gate.cpp.o


CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.o: CMakeFiles/Vliegveld_debug.dir/flags.make
CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.o: ../mainTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/mainTest.cpp

CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/mainTest.cpp > CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.i

CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/mainTest.cpp -o CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.s

CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.o.requires

CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.o.provides: CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld_debug.dir/build.make CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.o.provides

CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.o.provides.build: CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.o


CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.o: CMakeFiles/Vliegveld_debug.dir/flags.make
CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.o: ../Simulation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/Simulation.cpp

CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/Simulation.cpp > CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.i

CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/Simulation.cpp -o CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.s

CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.o.requires

CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.o.provides: CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld_debug.dir/build.make CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.o.provides

CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.o.provides.build: CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.o


CMakeFiles/Vliegveld_debug.dir/parser.cpp.o: CMakeFiles/Vliegveld_debug.dir/flags.make
CMakeFiles/Vliegveld_debug.dir/parser.cpp.o: ../parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Vliegveld_debug.dir/parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld_debug.dir/parser.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/parser.cpp

CMakeFiles/Vliegveld_debug.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld_debug.dir/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/parser.cpp > CMakeFiles/Vliegveld_debug.dir/parser.cpp.i

CMakeFiles/Vliegveld_debug.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld_debug.dir/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/parser.cpp -o CMakeFiles/Vliegveld_debug.dir/parser.cpp.s

CMakeFiles/Vliegveld_debug.dir/parser.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld_debug.dir/parser.cpp.o.requires

CMakeFiles/Vliegveld_debug.dir/parser.cpp.o.provides: CMakeFiles/Vliegveld_debug.dir/parser.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld_debug.dir/build.make CMakeFiles/Vliegveld_debug.dir/parser.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld_debug.dir/parser.cpp.o.provides

CMakeFiles/Vliegveld_debug.dir/parser.cpp.o.provides.build: CMakeFiles/Vliegveld_debug.dir/parser.cpp.o


CMakeFiles/Vliegveld_debug.dir/output.cpp.o: CMakeFiles/Vliegveld_debug.dir/flags.make
CMakeFiles/Vliegveld_debug.dir/output.cpp.o: ../output.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Vliegveld_debug.dir/output.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vliegveld_debug.dir/output.cpp.o -c /home/nightnarumi/CLionProjects/Vliegveld/output.cpp

CMakeFiles/Vliegveld_debug.dir/output.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vliegveld_debug.dir/output.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nightnarumi/CLionProjects/Vliegveld/output.cpp > CMakeFiles/Vliegveld_debug.dir/output.cpp.i

CMakeFiles/Vliegveld_debug.dir/output.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vliegveld_debug.dir/output.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nightnarumi/CLionProjects/Vliegveld/output.cpp -o CMakeFiles/Vliegveld_debug.dir/output.cpp.s

CMakeFiles/Vliegveld_debug.dir/output.cpp.o.requires:

.PHONY : CMakeFiles/Vliegveld_debug.dir/output.cpp.o.requires

CMakeFiles/Vliegveld_debug.dir/output.cpp.o.provides: CMakeFiles/Vliegveld_debug.dir/output.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vliegveld_debug.dir/build.make CMakeFiles/Vliegveld_debug.dir/output.cpp.o.provides.build
.PHONY : CMakeFiles/Vliegveld_debug.dir/output.cpp.o.provides

CMakeFiles/Vliegveld_debug.dir/output.cpp.o.provides.build: CMakeFiles/Vliegveld_debug.dir/output.cpp.o


# Object files for target Vliegveld_debug
Vliegveld_debug_OBJECTS = \
"CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.o" \
"CMakeFiles/Vliegveld_debug.dir/Airport.cpp.o" \
"CMakeFiles/Vliegveld_debug.dir/Runway.cpp.o" \
"CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.o" \
"CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.o" \
"CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.o" \
"CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.o" \
"CMakeFiles/Vliegveld_debug.dir/Gate.cpp.o" \
"CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.o" \
"CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.o" \
"CMakeFiles/Vliegveld_debug.dir/parser.cpp.o" \
"CMakeFiles/Vliegveld_debug.dir/output.cpp.o"

# External object files for target Vliegveld_debug
Vliegveld_debug_EXTERNAL_OBJECTS =

Vliegveld_debug: CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.o
Vliegveld_debug: CMakeFiles/Vliegveld_debug.dir/Airport.cpp.o
Vliegveld_debug: CMakeFiles/Vliegveld_debug.dir/Runway.cpp.o
Vliegveld_debug: CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.o
Vliegveld_debug: CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.o
Vliegveld_debug: CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.o
Vliegveld_debug: CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.o
Vliegveld_debug: CMakeFiles/Vliegveld_debug.dir/Gate.cpp.o
Vliegveld_debug: CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.o
Vliegveld_debug: CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.o
Vliegveld_debug: CMakeFiles/Vliegveld_debug.dir/parser.cpp.o
Vliegveld_debug: CMakeFiles/Vliegveld_debug.dir/output.cpp.o
Vliegveld_debug: CMakeFiles/Vliegveld_debug.dir/build.make
Vliegveld_debug: CMakeFiles/Vliegveld_debug.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable Vliegveld_debug"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Vliegveld_debug.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Vliegveld_debug.dir/build: Vliegveld_debug

.PHONY : CMakeFiles/Vliegveld_debug.dir/build

CMakeFiles/Vliegveld_debug.dir/requires: CMakeFiles/Vliegveld_debug.dir/Airplane.cpp.o.requires
CMakeFiles/Vliegveld_debug.dir/requires: CMakeFiles/Vliegveld_debug.dir/Airport.cpp.o.requires
CMakeFiles/Vliegveld_debug.dir/requires: CMakeFiles/Vliegveld_debug.dir/Runway.cpp.o.requires
CMakeFiles/Vliegveld_debug.dir/requires: CMakeFiles/Vliegveld_debug.dir/tinystr.cpp.o.requires
CMakeFiles/Vliegveld_debug.dir/requires: CMakeFiles/Vliegveld_debug.dir/tinyxml.cpp.o.requires
CMakeFiles/Vliegveld_debug.dir/requires: CMakeFiles/Vliegveld_debug.dir/tinyxmlerror.cpp.o.requires
CMakeFiles/Vliegveld_debug.dir/requires: CMakeFiles/Vliegveld_debug.dir/tinyxmlparser.cpp.o.requires
CMakeFiles/Vliegveld_debug.dir/requires: CMakeFiles/Vliegveld_debug.dir/Gate.cpp.o.requires
CMakeFiles/Vliegveld_debug.dir/requires: CMakeFiles/Vliegveld_debug.dir/mainTest.cpp.o.requires
CMakeFiles/Vliegveld_debug.dir/requires: CMakeFiles/Vliegveld_debug.dir/Simulation.cpp.o.requires
CMakeFiles/Vliegveld_debug.dir/requires: CMakeFiles/Vliegveld_debug.dir/parser.cpp.o.requires
CMakeFiles/Vliegveld_debug.dir/requires: CMakeFiles/Vliegveld_debug.dir/output.cpp.o.requires

.PHONY : CMakeFiles/Vliegveld_debug.dir/requires

CMakeFiles/Vliegveld_debug.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Vliegveld_debug.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Vliegveld_debug.dir/clean

CMakeFiles/Vliegveld_debug.dir/depend:
	cd /home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nightnarumi/CLionProjects/Vliegveld /home/nightnarumi/CLionProjects/Vliegveld /home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug /home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug /home/nightnarumi/CLionProjects/Vliegveld/cmake-build-debug/CMakeFiles/Vliegveld_debug.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Vliegveld_debug.dir/depend

