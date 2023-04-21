set (SOURCE_FILES

)

#add_library(fire-towersrc STATIC ${SOURCE_FILES})
add_executable(fire-tower fire-tower/Main.cpp)

target_include_directories(fire-tower PUBLIC ./)
target_link_libraries(fire-tower PUBLIC stackchat stackapi)

# vim:ft=cmake
