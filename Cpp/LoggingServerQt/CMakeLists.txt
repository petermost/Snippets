cmake_minimum_required( VERSION 3.0 )
set( CMAKE_WARN_DEPRECATED ON )
set( CMAKE_VERBOSE_MAKEFILE ON )

project( LoggingServerQt )
add_compile_options( -std=c++14 -w -Wall -Wextra -pedantic )

set( SOURCES
	src/main.cpp
	src/Controller.cpp
	src/ControllerWidget.cpp
	src/Icons.cpp
	src/LoggingServer.cpp
	src/MainWidget.cpp
	src/Settings.cpp
	src/SettingsWidget.cpp
	src/TcpIpEdit.cpp
	src/TcpIpEndPoint.cpp
	src/Utils.cpp
)


add_executable( LoggingServerQt
	src/main.cpp
	src/util.cpp
)

add_subdirectory( ../CppAidKit ./AidKit )
include_directories( ../CppAidKit/headers/ )
link_directories( ./AidKit )

# Qt5 Setup:

set( CMAKE_AUTOMOC ON )
set( CMAKE_INCLUDE_CURRENT_DIR ON )
find_package( Qt5Widgets )

target_link_libraries( LoggingServerQt AidKit Qt5::Widgets )
