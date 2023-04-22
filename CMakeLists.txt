cmake_minimum_required(VERSION 3.10)
project(fire-tower)

set (CMAKE_CXX_STANDARD 20)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

include (FetchContent)
FetchContent_Declare(stackapi
    GIT_REPOSITORY https://github.com/LunarWatcher/stackapi.cpp)
FetchContent_Declare(stackchat
    GIT_REPOSITORY https://github.com/LunarWatcher/stackchat.cpp)
FetchContent_Declare(sqlite
    GIT_REPOSITORY https://github.com/SRombauts/SQLiteCpp
    GIT_TAG 3.2.1)

FetchContent_MakeAvailable(stackapi)
FetchContent_MakeAvailable(stackchat)
FetchContent_MakeAvailable(sqlite)

add_subdirectory(src)

add_custom_target(run
    COMMAND fire-tower
    DEPENDS fire-tower
    COMMENT "Run fire tower")

# vim:ft=cmake
