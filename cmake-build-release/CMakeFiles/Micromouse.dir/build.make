# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\nolo7\Desktop\IEEE\Mouse Code\Micromouse"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\nolo7\Desktop\IEEE\Mouse Code\Micromouse\cmake-build-release"

# Include any dependencies generated for this target.
include CMakeFiles/Micromouse.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Micromouse.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Micromouse.dir/flags.make

Micromouse_micromouse.ino.cpp: ../micromouse.ino
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="C:\Users\nolo7\Desktop\IEEE\Mouse Code\Micromouse\cmake-build-release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Regnerating micromouse.ino Sketch"
	"C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" "C:/Users/nolo7/Desktop/IEEE/Mouse Code/Micromouse"

CMakeFiles/Micromouse.dir/Micromouse_micromouse.ino.cpp.obj: CMakeFiles/Micromouse.dir/flags.make
CMakeFiles/Micromouse.dir/Micromouse_micromouse.ino.cpp.obj: Micromouse_micromouse.ino.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\nolo7\Desktop\IEEE\Mouse Code\Micromouse\cmake-build-release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Micromouse.dir/Micromouse_micromouse.ino.cpp.obj"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\AVR-G_~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Micromouse.dir\Micromouse_micromouse.ino.cpp.obj -c "C:\Users\nolo7\Desktop\IEEE\Mouse Code\Micromouse\cmake-build-release\Micromouse_micromouse.ino.cpp"

CMakeFiles/Micromouse.dir/Micromouse_micromouse.ino.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Micromouse.dir/Micromouse_micromouse.ino.cpp.i"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\AVR-G_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\nolo7\Desktop\IEEE\Mouse Code\Micromouse\cmake-build-release\Micromouse_micromouse.ino.cpp" > CMakeFiles\Micromouse.dir\Micromouse_micromouse.ino.cpp.i

CMakeFiles/Micromouse.dir/Micromouse_micromouse.ino.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Micromouse.dir/Micromouse_micromouse.ino.cpp.s"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\AVR-G_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\nolo7\Desktop\IEEE\Mouse Code\Micromouse\cmake-build-release\Micromouse_micromouse.ino.cpp" -o CMakeFiles\Micromouse.dir\Micromouse_micromouse.ino.cpp.s

# Object files for target Micromouse
Micromouse_OBJECTS = \
"CMakeFiles/Micromouse.dir/Micromouse_micromouse.ino.cpp.obj"

# External object files for target Micromouse
Micromouse_EXTERNAL_OBJECTS =

Micromouse.elf: CMakeFiles/Micromouse.dir/Micromouse_micromouse.ino.cpp.obj
Micromouse.elf: CMakeFiles/Micromouse.dir/build.make
Micromouse.elf: libnano_Drive2Goal.a
Micromouse.elf: libnano_NewPing.a
Micromouse.elf: libnano_Motor.a
Micromouse.elf: libnano_Maze.a
Micromouse.elf: libnano_Sensors.a
Micromouse.elf: libnano_Thinking.a
Micromouse.elf: libnano_FunctionLibrary.a
Micromouse.elf: libnano_CORE.a
Micromouse.elf: CMakeFiles/Micromouse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\nolo7\Desktop\IEEE\Mouse Code\Micromouse\cmake-build-release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Micromouse.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Micromouse.dir\link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating EEP image"
	"C:\Program Files (x86)\Arduino\hardware\tools\avr\bin\avr-objcopy.exe" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 "C:/Users/nolo7/Desktop/IEEE/Mouse Code/Micromouse/cmake-build-release/Micromouse.elf" "C:/Users/nolo7/Desktop/IEEE/Mouse Code/Micromouse/cmake-build-release/Micromouse.eep"
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating HEX image"
	"C:\Program Files (x86)\Arduino\hardware\tools\avr\bin\avr-objcopy.exe" -O ihex -R .eeprom "C:/Users/nolo7/Desktop/IEEE/Mouse Code/Micromouse/cmake-build-release/Micromouse.elf" "C:/Users/nolo7/Desktop/IEEE/Mouse Code/Micromouse/cmake-build-release/Micromouse.hex"
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Calculating image size"
	"C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" "-DFIRMWARE_IMAGE=C:/Users/nolo7/Desktop/IEEE/Mouse Code/Micromouse/cmake-build-release/Micromouse.elf" -DMCU=atmega328p "-DEEPROM_IMAGE=C:/Users/nolo7/Desktop/IEEE/Mouse Code/Micromouse/cmake-build-release/Micromouse.eep" -P "C:/Users/nolo7/Desktop/IEEE/Mouse Code/Micromouse/cmake-build-release/CMakeFiles/FirmwareSize.cmake"

# Rule to build all files generated by this target.
CMakeFiles/Micromouse.dir/build: Micromouse.elf

.PHONY : CMakeFiles/Micromouse.dir/build

CMakeFiles/Micromouse.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Micromouse.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Micromouse.dir/clean

CMakeFiles/Micromouse.dir/depend: Micromouse_micromouse.ino.cpp
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\nolo7\Desktop\IEEE\Mouse Code\Micromouse" "C:\Users\nolo7\Desktop\IEEE\Mouse Code\Micromouse" "C:\Users\nolo7\Desktop\IEEE\Mouse Code\Micromouse\cmake-build-release" "C:\Users\nolo7\Desktop\IEEE\Mouse Code\Micromouse\cmake-build-release" "C:\Users\nolo7\Desktop\IEEE\Mouse Code\Micromouse\cmake-build-release\CMakeFiles\Micromouse.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Micromouse.dir/depend

