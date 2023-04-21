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
FetchContent_MakeAvailable(stackapi)
FetchContent_Declare(stackchat
    GIT_REPOSITORY https://github.com/LunarWatcher/stackchat.cpp)
FetchContent_MakeAvailable(stackchat)

add_subdirectory(src)
#add_subdirectory(tests)

add_custom_target(run
    COMMAND fire-tower
    DEPENDS fire-tower
    COMMENT "Run fire-tower")
#add_custom_target(test
    #COMMAND tests
    #DEPENDS tests
    #COMMENT "Test fire-tower")
# vim:ft=cmake
