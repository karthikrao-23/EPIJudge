# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.10.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.10.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp"

# Include any dependencies generated for this target.
include CMakeFiles/is_valid_sudoku.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/is_valid_sudoku.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/is_valid_sudoku.dir/flags.make

CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.o: CMakeFiles/is_valid_sudoku.dir/flags.make
CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.o: is_valid_sudoku.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.o -c "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/is_valid_sudoku.cc"

CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/is_valid_sudoku.cc" > CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.i

CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/is_valid_sudoku.cc" -o CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.s

CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.o.requires:

.PHONY : CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.o.requires

CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.o.provides: CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.o.requires
	$(MAKE) -f CMakeFiles/is_valid_sudoku.dir/build.make CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.o.provides.build
.PHONY : CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.o.provides

CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.o.provides.build: CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.o


# Object files for target is_valid_sudoku
is_valid_sudoku_OBJECTS = \
"CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.o"

# External object files for target is_valid_sudoku
is_valid_sudoku_EXTERNAL_OBJECTS =

is_valid_sudoku: CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.o
is_valid_sudoku: CMakeFiles/is_valid_sudoku.dir/build.make
is_valid_sudoku: CMakeFiles/is_valid_sudoku.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable is_valid_sudoku"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/is_valid_sudoku.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/is_valid_sudoku.dir/build: is_valid_sudoku

.PHONY : CMakeFiles/is_valid_sudoku.dir/build

CMakeFiles/is_valid_sudoku.dir/requires: CMakeFiles/is_valid_sudoku.dir/is_valid_sudoku.cc.o.requires

.PHONY : CMakeFiles/is_valid_sudoku.dir/requires

CMakeFiles/is_valid_sudoku.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/is_valid_sudoku.dir/cmake_clean.cmake
.PHONY : CMakeFiles/is_valid_sudoku.dir/clean

CMakeFiles/is_valid_sudoku.dir/depend:
	cd "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles/is_valid_sudoku.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/is_valid_sudoku.dir/depend
