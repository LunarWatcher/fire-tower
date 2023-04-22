#include "ChatProcessor.hpp"
#include "fire-tower/chat/commands/FunCommands.hpp"

namespace firetower {

ChatProcessor::ChatProcessor(Config& conf) 
    : 
        chat {
            {
                .email{conf.email},
                .password{conf.password},
                .prefix {"ft!"},
                .userAgent{"FireTower/git (+https://github.com/LunarWatcher/fire-tower)"},
            }
        },
        conf(conf) {
    
    chat.registerCommand("alive", std::make_shared<AliveCommand>());
    for (auto& [site, rooms] : conf.rooms) {
        for (auto& room : rooms) {
            chat.join(site, room);
        }
    }
}


}
