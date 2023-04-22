set (SOURCE_FILES
    fire-tower/Main.cpp

    fire-tower/FireTower.cpp
    fire-tower/data/Database.cpp
    
    fire-tower/chat/ChatProcessor.cpp
    fire-tower/chat/commands/StartBurnCommand.cpp
    fire-tower/chat/commands/FunCommands.cpp

    fire-tower/api/APIProcessor.cpp

)

add_executable(fire-tower ${SOURCE_FILES})

target_include_directories(fire-tower PUBLIC ./)
target_link_libraries(fire-tower PUBLIC stackchat stackapi SQLiteCpp sqlite3)

# vim:ft=cmake
