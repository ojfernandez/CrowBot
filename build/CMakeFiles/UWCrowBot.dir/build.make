# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /root/CrowBot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/CrowBot/build

# Include any dependencies generated for this target.
include CMakeFiles/UWCrowBot.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UWCrowBot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UWCrowBot.dir/flags.make

CMakeFiles/UWCrowBot.dir/src/main.cpp.o: CMakeFiles/UWCrowBot.dir/flags.make
CMakeFiles/UWCrowBot.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/CrowBot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UWCrowBot.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UWCrowBot.dir/src/main.cpp.o -c /root/CrowBot/src/main.cpp

CMakeFiles/UWCrowBot.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UWCrowBot.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/CrowBot/src/main.cpp > CMakeFiles/UWCrowBot.dir/src/main.cpp.i

CMakeFiles/UWCrowBot.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UWCrowBot.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/CrowBot/src/main.cpp -o CMakeFiles/UWCrowBot.dir/src/main.cpp.s

# Object files for target UWCrowBot
UWCrowBot_OBJECTS = \
"CMakeFiles/UWCrowBot.dir/src/main.cpp.o"

# External object files for target UWCrowBot
UWCrowBot_EXTERNAL_OBJECTS =

UWCrowBot: CMakeFiles/UWCrowBot.dir/src/main.cpp.o
UWCrowBot: CMakeFiles/UWCrowBot.dir/build.make
UWCrowBot: /usr/lib/x86_64-linux-gnu/libcrypto.so
UWCrowBot: /usr/lib/x86_64-linux-gnu/libssl.so
UWCrowBot: /usr/lib/libdpp.so
UWCrowBot: CMakeFiles/UWCrowBot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/CrowBot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable UWCrowBot"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UWCrowBot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UWCrowBot.dir/build: UWCrowBot

.PHONY : CMakeFiles/UWCrowBot.dir/build

CMakeFiles/UWCrowBot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UWCrowBot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UWCrowBot.dir/clean

CMakeFiles/UWCrowBot.dir/depend:
	cd /root/CrowBot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/CrowBot /root/CrowBot /root/CrowBot/build /root/CrowBot/build /root/CrowBot/build/CMakeFiles/UWCrowBot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UWCrowBot.dir/depend

