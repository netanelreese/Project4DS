# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\reese\CLionProjects\project4_2413

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\reese\CLionProjects\project4_2413\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\project4_2413.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\project4_2413.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\project4_2413.dir\flags.make

CMakeFiles\project4_2413.dir\main.cpp.obj: CMakeFiles\project4_2413.dir\flags.make
CMakeFiles\project4_2413.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\reese\CLionProjects\project4_2413\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project4_2413.dir/main.cpp.obj"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\project4_2413.dir\main.cpp.obj /FdCMakeFiles\project4_2413.dir\ /FS -c C:\Users\reese\CLionProjects\project4_2413\main.cpp
<<

CMakeFiles\project4_2413.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project4_2413.dir/main.cpp.i"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\project4_2413.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\reese\CLionProjects\project4_2413\main.cpp
<<

CMakeFiles\project4_2413.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project4_2413.dir/main.cpp.s"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\project4_2413.dir\main.cpp.s /c C:\Users\reese\CLionProjects\project4_2413\main.cpp
<<

# Object files for target project4_2413
project4_2413_OBJECTS = \
"CMakeFiles\project4_2413.dir\main.cpp.obj"

# External object files for target project4_2413
project4_2413_EXTERNAL_OBJECTS =

project4_2413.exe: CMakeFiles\project4_2413.dir\main.cpp.obj
project4_2413.exe: CMakeFiles\project4_2413.dir\build.make
project4_2413.exe: CMakeFiles\project4_2413.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\reese\CLionProjects\project4_2413\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable project4_2413.exe"
	"C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\project4_2413.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\project4_2413.dir\objects1.rsp @<<
 /out:project4_2413.exe /implib:project4_2413.lib /pdb:C:\Users\reese\CLionProjects\project4_2413\cmake-build-debug\project4_2413.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\project4_2413.dir\build: project4_2413.exe

.PHONY : CMakeFiles\project4_2413.dir\build

CMakeFiles\project4_2413.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\project4_2413.dir\cmake_clean.cmake
.PHONY : CMakeFiles\project4_2413.dir\clean

CMakeFiles\project4_2413.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\reese\CLionProjects\project4_2413 C:\Users\reese\CLionProjects\project4_2413 C:\Users\reese\CLionProjects\project4_2413\cmake-build-debug C:\Users\reese\CLionProjects\project4_2413\cmake-build-debug C:\Users\reese\CLionProjects\project4_2413\cmake-build-debug\CMakeFiles\project4_2413.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\project4_2413.dir\depend

