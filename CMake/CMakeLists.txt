project(TransferServer_googletest)
cmake_minimum_required(VERSION 3.10)

include(../CMakeModules/DownloadProject.cmake)

download_project(
	PROJ           googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG        master
	UPDATE_DISCONNECTED 1

	DOWNLOAD_DIR   ${CMAKE_CURRENT_BINARY_DIR}/download.dir
	SOURCE_DIR     ${CMAKE_CURRENT_BINARY_DIR}/source.dir
	BINARY_DIR     ${CMAKE_CURRENT_BINARY_DIR}/binary.dir
)

set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio:

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)
