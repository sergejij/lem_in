# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Users/ubartemi/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Users/ubartemi/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ubartemi/Desktop/lem_in

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ubartemi/Desktop/lem_in/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lem_debag.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lem_debag.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lem_debag.dir/flags.make

CMakeFiles/lem_debag.dir/main.c.o: CMakeFiles/lem_debag.dir/flags.make
CMakeFiles/lem_debag.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ubartemi/Desktop/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lem_debag.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_debag.dir/main.c.o   -c /Users/ubartemi/Desktop/lem_in/main.c

CMakeFiles/lem_debag.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_debag.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ubartemi/Desktop/lem_in/main.c > CMakeFiles/lem_debag.dir/main.c.i

CMakeFiles/lem_debag.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_debag.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ubartemi/Desktop/lem_in/main.c -o CMakeFiles/lem_debag.dir/main.c.s

CMakeFiles/lem_debag.dir/validation/read_and_save.c.o: CMakeFiles/lem_debag.dir/flags.make
CMakeFiles/lem_debag.dir/validation/read_and_save.c.o: ../validation/read_and_save.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ubartemi/Desktop/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lem_debag.dir/validation/read_and_save.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_debag.dir/validation/read_and_save.c.o   -c /Users/ubartemi/Desktop/lem_in/validation/read_and_save.c

CMakeFiles/lem_debag.dir/validation/read_and_save.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_debag.dir/validation/read_and_save.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ubartemi/Desktop/lem_in/validation/read_and_save.c > CMakeFiles/lem_debag.dir/validation/read_and_save.c.i

CMakeFiles/lem_debag.dir/validation/read_and_save.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_debag.dir/validation/read_and_save.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ubartemi/Desktop/lem_in/validation/read_and_save.c -o CMakeFiles/lem_debag.dir/validation/read_and_save.c.s

CMakeFiles/lem_debag.dir/validation/validation.c.o: CMakeFiles/lem_debag.dir/flags.make
CMakeFiles/lem_debag.dir/validation/validation.c.o: ../validation/validation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ubartemi/Desktop/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lem_debag.dir/validation/validation.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_debag.dir/validation/validation.c.o   -c /Users/ubartemi/Desktop/lem_in/validation/validation.c

CMakeFiles/lem_debag.dir/validation/validation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_debag.dir/validation/validation.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ubartemi/Desktop/lem_in/validation/validation.c > CMakeFiles/lem_debag.dir/validation/validation.c.i

CMakeFiles/lem_debag.dir/validation/validation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_debag.dir/validation/validation.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ubartemi/Desktop/lem_in/validation/validation.c -o CMakeFiles/lem_debag.dir/validation/validation.c.s

CMakeFiles/lem_debag.dir/validation/find.c.o: CMakeFiles/lem_debag.dir/flags.make
CMakeFiles/lem_debag.dir/validation/find.c.o: ../validation/find.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ubartemi/Desktop/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/lem_debag.dir/validation/find.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_debag.dir/validation/find.c.o   -c /Users/ubartemi/Desktop/lem_in/validation/find.c

CMakeFiles/lem_debag.dir/validation/find.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_debag.dir/validation/find.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ubartemi/Desktop/lem_in/validation/find.c > CMakeFiles/lem_debag.dir/validation/find.c.i

CMakeFiles/lem_debag.dir/validation/find.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_debag.dir/validation/find.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ubartemi/Desktop/lem_in/validation/find.c -o CMakeFiles/lem_debag.dir/validation/find.c.s

CMakeFiles/lem_debag.dir/validation/define.c.o: CMakeFiles/lem_debag.dir/flags.make
CMakeFiles/lem_debag.dir/validation/define.c.o: ../validation/define.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ubartemi/Desktop/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/lem_debag.dir/validation/define.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_debag.dir/validation/define.c.o   -c /Users/ubartemi/Desktop/lem_in/validation/define.c

CMakeFiles/lem_debag.dir/validation/define.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_debag.dir/validation/define.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ubartemi/Desktop/lem_in/validation/define.c > CMakeFiles/lem_debag.dir/validation/define.c.i

CMakeFiles/lem_debag.dir/validation/define.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_debag.dir/validation/define.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ubartemi/Desktop/lem_in/validation/define.c -o CMakeFiles/lem_debag.dir/validation/define.c.s

CMakeFiles/lem_debag.dir/validation/check_parts.c.o: CMakeFiles/lem_debag.dir/flags.make
CMakeFiles/lem_debag.dir/validation/check_parts.c.o: ../validation/check_parts.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ubartemi/Desktop/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/lem_debag.dir/validation/check_parts.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_debag.dir/validation/check_parts.c.o   -c /Users/ubartemi/Desktop/lem_in/validation/check_parts.c

CMakeFiles/lem_debag.dir/validation/check_parts.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_debag.dir/validation/check_parts.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ubartemi/Desktop/lem_in/validation/check_parts.c > CMakeFiles/lem_debag.dir/validation/check_parts.c.i

CMakeFiles/lem_debag.dir/validation/check_parts.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_debag.dir/validation/check_parts.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ubartemi/Desktop/lem_in/validation/check_parts.c -o CMakeFiles/lem_debag.dir/validation/check_parts.c.s

CMakeFiles/lem_debag.dir/validation/free.c.o: CMakeFiles/lem_debag.dir/flags.make
CMakeFiles/lem_debag.dir/validation/free.c.o: ../validation/free.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ubartemi/Desktop/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/lem_debag.dir/validation/free.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_debag.dir/validation/free.c.o   -c /Users/ubartemi/Desktop/lem_in/validation/free.c

CMakeFiles/lem_debag.dir/validation/free.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_debag.dir/validation/free.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ubartemi/Desktop/lem_in/validation/free.c > CMakeFiles/lem_debag.dir/validation/free.c.i

CMakeFiles/lem_debag.dir/validation/free.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_debag.dir/validation/free.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ubartemi/Desktop/lem_in/validation/free.c -o CMakeFiles/lem_debag.dir/validation/free.c.s

CMakeFiles/lem_debag.dir/validation/make_map.c.o: CMakeFiles/lem_debag.dir/flags.make
CMakeFiles/lem_debag.dir/validation/make_map.c.o: ../validation/make_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ubartemi/Desktop/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/lem_debag.dir/validation/make_map.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_debag.dir/validation/make_map.c.o   -c /Users/ubartemi/Desktop/lem_in/validation/make_map.c

CMakeFiles/lem_debag.dir/validation/make_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_debag.dir/validation/make_map.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ubartemi/Desktop/lem_in/validation/make_map.c > CMakeFiles/lem_debag.dir/validation/make_map.c.i

CMakeFiles/lem_debag.dir/validation/make_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_debag.dir/validation/make_map.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ubartemi/Desktop/lem_in/validation/make_map.c -o CMakeFiles/lem_debag.dir/validation/make_map.c.s

CMakeFiles/lem_debag.dir/validation/make_links.c.o: CMakeFiles/lem_debag.dir/flags.make
CMakeFiles/lem_debag.dir/validation/make_links.c.o: ../validation/make_links.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ubartemi/Desktop/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/lem_debag.dir/validation/make_links.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_debag.dir/validation/make_links.c.o   -c /Users/ubartemi/Desktop/lem_in/validation/make_links.c

CMakeFiles/lem_debag.dir/validation/make_links.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_debag.dir/validation/make_links.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ubartemi/Desktop/lem_in/validation/make_links.c > CMakeFiles/lem_debag.dir/validation/make_links.c.i

CMakeFiles/lem_debag.dir/validation/make_links.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_debag.dir/validation/make_links.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ubartemi/Desktop/lem_in/validation/make_links.c -o CMakeFiles/lem_debag.dir/validation/make_links.c.s

CMakeFiles/lem_debag.dir/solution/solution.c.o: CMakeFiles/lem_debag.dir/flags.make
CMakeFiles/lem_debag.dir/solution/solution.c.o: ../solution/solution.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ubartemi/Desktop/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/lem_debag.dir/solution/solution.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_debag.dir/solution/solution.c.o   -c /Users/ubartemi/Desktop/lem_in/solution/solution.c

CMakeFiles/lem_debag.dir/solution/solution.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_debag.dir/solution/solution.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ubartemi/Desktop/lem_in/solution/solution.c > CMakeFiles/lem_debag.dir/solution/solution.c.i

CMakeFiles/lem_debag.dir/solution/solution.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_debag.dir/solution/solution.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ubartemi/Desktop/lem_in/solution/solution.c -o CMakeFiles/lem_debag.dir/solution/solution.c.s

CMakeFiles/lem_debag.dir/solution/ways.c.o: CMakeFiles/lem_debag.dir/flags.make
CMakeFiles/lem_debag.dir/solution/ways.c.o: ../solution/ways.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ubartemi/Desktop/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/lem_debag.dir/solution/ways.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_debag.dir/solution/ways.c.o   -c /Users/ubartemi/Desktop/lem_in/solution/ways.c

CMakeFiles/lem_debag.dir/solution/ways.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_debag.dir/solution/ways.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ubartemi/Desktop/lem_in/solution/ways.c > CMakeFiles/lem_debag.dir/solution/ways.c.i

CMakeFiles/lem_debag.dir/solution/ways.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_debag.dir/solution/ways.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ubartemi/Desktop/lem_in/solution/ways.c -o CMakeFiles/lem_debag.dir/solution/ways.c.s

CMakeFiles/lem_debag.dir/solution/auxiliary.c.o: CMakeFiles/lem_debag.dir/flags.make
CMakeFiles/lem_debag.dir/solution/auxiliary.c.o: ../solution/auxiliary.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ubartemi/Desktop/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/lem_debag.dir/solution/auxiliary.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_debag.dir/solution/auxiliary.c.o   -c /Users/ubartemi/Desktop/lem_in/solution/auxiliary.c

CMakeFiles/lem_debag.dir/solution/auxiliary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_debag.dir/solution/auxiliary.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ubartemi/Desktop/lem_in/solution/auxiliary.c > CMakeFiles/lem_debag.dir/solution/auxiliary.c.i

CMakeFiles/lem_debag.dir/solution/auxiliary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_debag.dir/solution/auxiliary.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ubartemi/Desktop/lem_in/solution/auxiliary.c -o CMakeFiles/lem_debag.dir/solution/auxiliary.c.s

CMakeFiles/lem_debag.dir/solution/shortest_way.c.o: CMakeFiles/lem_debag.dir/flags.make
CMakeFiles/lem_debag.dir/solution/shortest_way.c.o: ../solution/shortest_way.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ubartemi/Desktop/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/lem_debag.dir/solution/shortest_way.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_debag.dir/solution/shortest_way.c.o   -c /Users/ubartemi/Desktop/lem_in/solution/shortest_way.c

CMakeFiles/lem_debag.dir/solution/shortest_way.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_debag.dir/solution/shortest_way.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ubartemi/Desktop/lem_in/solution/shortest_way.c > CMakeFiles/lem_debag.dir/solution/shortest_way.c.i

CMakeFiles/lem_debag.dir/solution/shortest_way.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_debag.dir/solution/shortest_way.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ubartemi/Desktop/lem_in/solution/shortest_way.c -o CMakeFiles/lem_debag.dir/solution/shortest_way.c.s

CMakeFiles/lem_debag.dir/solution/find_new_paths.c.o: CMakeFiles/lem_debag.dir/flags.make
CMakeFiles/lem_debag.dir/solution/find_new_paths.c.o: ../solution/find_new_paths.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ubartemi/Desktop/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/lem_debag.dir/solution/find_new_paths.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_debag.dir/solution/find_new_paths.c.o   -c /Users/ubartemi/Desktop/lem_in/solution/find_new_paths.c

CMakeFiles/lem_debag.dir/solution/find_new_paths.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_debag.dir/solution/find_new_paths.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ubartemi/Desktop/lem_in/solution/find_new_paths.c > CMakeFiles/lem_debag.dir/solution/find_new_paths.c.i

CMakeFiles/lem_debag.dir/solution/find_new_paths.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_debag.dir/solution/find_new_paths.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ubartemi/Desktop/lem_in/solution/find_new_paths.c -o CMakeFiles/lem_debag.dir/solution/find_new_paths.c.s

# Object files for target lem_debag
lem_debag_OBJECTS = \
"CMakeFiles/lem_debag.dir/main.c.o" \
"CMakeFiles/lem_debag.dir/validation/read_and_save.c.o" \
"CMakeFiles/lem_debag.dir/validation/validation.c.o" \
"CMakeFiles/lem_debag.dir/validation/find.c.o" \
"CMakeFiles/lem_debag.dir/validation/define.c.o" \
"CMakeFiles/lem_debag.dir/validation/check_parts.c.o" \
"CMakeFiles/lem_debag.dir/validation/free.c.o" \
"CMakeFiles/lem_debag.dir/validation/make_map.c.o" \
"CMakeFiles/lem_debag.dir/validation/make_links.c.o" \
"CMakeFiles/lem_debag.dir/solution/solution.c.o" \
"CMakeFiles/lem_debag.dir/solution/ways.c.o" \
"CMakeFiles/lem_debag.dir/solution/auxiliary.c.o" \
"CMakeFiles/lem_debag.dir/solution/shortest_way.c.o" \
"CMakeFiles/lem_debag.dir/solution/find_new_paths.c.o"

# External object files for target lem_debag
lem_debag_EXTERNAL_OBJECTS =

lem_debag: CMakeFiles/lem_debag.dir/main.c.o
lem_debag: CMakeFiles/lem_debag.dir/validation/read_and_save.c.o
lem_debag: CMakeFiles/lem_debag.dir/validation/validation.c.o
lem_debag: CMakeFiles/lem_debag.dir/validation/find.c.o
lem_debag: CMakeFiles/lem_debag.dir/validation/define.c.o
lem_debag: CMakeFiles/lem_debag.dir/validation/check_parts.c.o
lem_debag: CMakeFiles/lem_debag.dir/validation/free.c.o
lem_debag: CMakeFiles/lem_debag.dir/validation/make_map.c.o
lem_debag: CMakeFiles/lem_debag.dir/validation/make_links.c.o
lem_debag: CMakeFiles/lem_debag.dir/solution/solution.c.o
lem_debag: CMakeFiles/lem_debag.dir/solution/ways.c.o
lem_debag: CMakeFiles/lem_debag.dir/solution/auxiliary.c.o
lem_debag: CMakeFiles/lem_debag.dir/solution/shortest_way.c.o
lem_debag: CMakeFiles/lem_debag.dir/solution/find_new_paths.c.o
lem_debag: CMakeFiles/lem_debag.dir/build.make
lem_debag: ../libft/libft.a
lem_debag: CMakeFiles/lem_debag.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ubartemi/Desktop/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking C executable lem_debag"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lem_debag.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lem_debag.dir/build: lem_debag

.PHONY : CMakeFiles/lem_debag.dir/build

CMakeFiles/lem_debag.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lem_debag.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lem_debag.dir/clean

CMakeFiles/lem_debag.dir/depend:
	cd /Users/ubartemi/Desktop/lem_in/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ubartemi/Desktop/lem_in /Users/ubartemi/Desktop/lem_in /Users/ubartemi/Desktop/lem_in/cmake-build-debug /Users/ubartemi/Desktop/lem_in/cmake-build-debug /Users/ubartemi/Desktop/lem_in/cmake-build-debug/CMakeFiles/lem_debag.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lem_debag.dir/depend

