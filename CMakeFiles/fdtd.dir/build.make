# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hanz/Downloads/fdtd-New

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hanz/Downloads/fdtd-New

# Include any dependencies generated for this target.
include CMakeFiles/fdtd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fdtd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fdtd.dir/flags.make

CMakeFiles/fdtd.dir/src/chunk.cpp.o: CMakeFiles/fdtd.dir/flags.make
CMakeFiles/fdtd.dir/src/chunk.cpp.o: src/chunk.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanz/Downloads/fdtd-New/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fdtd.dir/src/chunk.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fdtd.dir/src/chunk.cpp.o -c /Users/hanz/Downloads/fdtd-New/src/chunk.cpp

CMakeFiles/fdtd.dir/src/chunk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fdtd.dir/src/chunk.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hanz/Downloads/fdtd-New/src/chunk.cpp > CMakeFiles/fdtd.dir/src/chunk.cpp.i

CMakeFiles/fdtd.dir/src/chunk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fdtd.dir/src/chunk.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hanz/Downloads/fdtd-New/src/chunk.cpp -o CMakeFiles/fdtd.dir/src/chunk.cpp.s

CMakeFiles/fdtd.dir/src/grid.cpp.o: CMakeFiles/fdtd.dir/flags.make
CMakeFiles/fdtd.dir/src/grid.cpp.o: src/grid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanz/Downloads/fdtd-New/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/fdtd.dir/src/grid.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fdtd.dir/src/grid.cpp.o -c /Users/hanz/Downloads/fdtd-New/src/grid.cpp

CMakeFiles/fdtd.dir/src/grid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fdtd.dir/src/grid.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hanz/Downloads/fdtd-New/src/grid.cpp > CMakeFiles/fdtd.dir/src/grid.cpp.i

CMakeFiles/fdtd.dir/src/grid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fdtd.dir/src/grid.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hanz/Downloads/fdtd-New/src/grid.cpp -o CMakeFiles/fdtd.dir/src/grid.cpp.s

CMakeFiles/fdtd.dir/src/main.cpp.o: CMakeFiles/fdtd.dir/flags.make
CMakeFiles/fdtd.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanz/Downloads/fdtd-New/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/fdtd.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fdtd.dir/src/main.cpp.o -c /Users/hanz/Downloads/fdtd-New/src/main.cpp

CMakeFiles/fdtd.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fdtd.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hanz/Downloads/fdtd-New/src/main.cpp > CMakeFiles/fdtd.dir/src/main.cpp.i

CMakeFiles/fdtd.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fdtd.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hanz/Downloads/fdtd-New/src/main.cpp -o CMakeFiles/fdtd.dir/src/main.cpp.s

CMakeFiles/fdtd.dir/src/params.cpp.o: CMakeFiles/fdtd.dir/flags.make
CMakeFiles/fdtd.dir/src/params.cpp.o: src/params.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanz/Downloads/fdtd-New/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/fdtd.dir/src/params.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fdtd.dir/src/params.cpp.o -c /Users/hanz/Downloads/fdtd-New/src/params.cpp

CMakeFiles/fdtd.dir/src/params.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fdtd.dir/src/params.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hanz/Downloads/fdtd-New/src/params.cpp > CMakeFiles/fdtd.dir/src/params.cpp.i

CMakeFiles/fdtd.dir/src/params.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fdtd.dir/src/params.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hanz/Downloads/fdtd-New/src/params.cpp -o CMakeFiles/fdtd.dir/src/params.cpp.s

CMakeFiles/fdtd.dir/extern/config.cpp.o: CMakeFiles/fdtd.dir/flags.make
CMakeFiles/fdtd.dir/extern/config.cpp.o: extern/config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanz/Downloads/fdtd-New/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/fdtd.dir/extern/config.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fdtd.dir/extern/config.cpp.o -c /Users/hanz/Downloads/fdtd-New/extern/config.cpp

CMakeFiles/fdtd.dir/extern/config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fdtd.dir/extern/config.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hanz/Downloads/fdtd-New/extern/config.cpp > CMakeFiles/fdtd.dir/extern/config.cpp.i

CMakeFiles/fdtd.dir/extern/config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fdtd.dir/extern/config.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hanz/Downloads/fdtd-New/extern/config.cpp -o CMakeFiles/fdtd.dir/extern/config.cpp.s

CMakeFiles/fdtd.dir/extern/config_map.cpp.o: CMakeFiles/fdtd.dir/flags.make
CMakeFiles/fdtd.dir/extern/config_map.cpp.o: extern/config_map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanz/Downloads/fdtd-New/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/fdtd.dir/extern/config_map.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fdtd.dir/extern/config_map.cpp.o -c /Users/hanz/Downloads/fdtd-New/extern/config_map.cpp

CMakeFiles/fdtd.dir/extern/config_map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fdtd.dir/extern/config_map.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hanz/Downloads/fdtd-New/extern/config_map.cpp > CMakeFiles/fdtd.dir/extern/config_map.cpp.i

CMakeFiles/fdtd.dir/extern/config_map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fdtd.dir/extern/config_map.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hanz/Downloads/fdtd-New/extern/config_map.cpp -o CMakeFiles/fdtd.dir/extern/config_map.cpp.s

CMakeFiles/fdtd.dir/extern/lcfg_static.cpp.o: CMakeFiles/fdtd.dir/flags.make
CMakeFiles/fdtd.dir/extern/lcfg_static.cpp.o: extern/lcfg_static.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanz/Downloads/fdtd-New/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/fdtd.dir/extern/lcfg_static.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fdtd.dir/extern/lcfg_static.cpp.o -c /Users/hanz/Downloads/fdtd-New/extern/lcfg_static.cpp

CMakeFiles/fdtd.dir/extern/lcfg_static.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fdtd.dir/extern/lcfg_static.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hanz/Downloads/fdtd-New/extern/lcfg_static.cpp > CMakeFiles/fdtd.dir/extern/lcfg_static.cpp.i

CMakeFiles/fdtd.dir/extern/lcfg_static.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fdtd.dir/extern/lcfg_static.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hanz/Downloads/fdtd-New/extern/lcfg_static.cpp -o CMakeFiles/fdtd.dir/extern/lcfg_static.cpp.s

# Object files for target fdtd
fdtd_OBJECTS = \
"CMakeFiles/fdtd.dir/src/chunk.cpp.o" \
"CMakeFiles/fdtd.dir/src/grid.cpp.o" \
"CMakeFiles/fdtd.dir/src/main.cpp.o" \
"CMakeFiles/fdtd.dir/src/params.cpp.o" \
"CMakeFiles/fdtd.dir/extern/config.cpp.o" \
"CMakeFiles/fdtd.dir/extern/config_map.cpp.o" \
"CMakeFiles/fdtd.dir/extern/lcfg_static.cpp.o"

# External object files for target fdtd
fdtd_EXTERNAL_OBJECTS =

fdtd: CMakeFiles/fdtd.dir/src/chunk.cpp.o
fdtd: CMakeFiles/fdtd.dir/src/grid.cpp.o
fdtd: CMakeFiles/fdtd.dir/src/main.cpp.o
fdtd: CMakeFiles/fdtd.dir/src/params.cpp.o
fdtd: CMakeFiles/fdtd.dir/extern/config.cpp.o
fdtd: CMakeFiles/fdtd.dir/extern/config_map.cpp.o
fdtd: CMakeFiles/fdtd.dir/extern/lcfg_static.cpp.o
fdtd: CMakeFiles/fdtd.dir/build.make
fdtd: CMakeFiles/fdtd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hanz/Downloads/fdtd-New/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable fdtd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fdtd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fdtd.dir/build: fdtd

.PHONY : CMakeFiles/fdtd.dir/build

CMakeFiles/fdtd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fdtd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fdtd.dir/clean

CMakeFiles/fdtd.dir/depend:
	cd /Users/hanz/Downloads/fdtd-New && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hanz/Downloads/fdtd-New /Users/hanz/Downloads/fdtd-New /Users/hanz/Downloads/fdtd-New /Users/hanz/Downloads/fdtd-New /Users/hanz/Downloads/fdtd-New/CMakeFiles/fdtd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fdtd.dir/depend

