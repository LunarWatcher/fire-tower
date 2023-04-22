#include "ChatProcessor.hpp"
#include "fire-tower/chat/commands/FunCommands.hpp"
#include "fire-tower/chat/commands/StartBurnCommand.hpp"
#include "fire-tower/data/Database.hpp"
#include "stackchat/chat/Command.hpp"
#include "stackchat/chat/MultiLevelCommand.hpp"

#include <map>

namespace firetower {

ChatProcessor::ChatProcessor(Config& conf, Database& db) 
    : 
        chat {
            {
                .email{conf.email},
                .password{conf.password},
                .prefix {"ft!"},
                .userAgent{"FireTower/git (+https://github.com/LunarWatcher/fire-tower)"},
            }
        },
        conf(conf), db(db) {
    
    chat.registerCommand("alive", std::make_shared<AliveCommand>());
    chat.registerCommand("burn", std::make_shared<stackchat::MultiLevelCommand>(
        std::map<std::string, std::shared_ptr<stackchat::Command>> {
            {"start", std::make_shared<StartBurnCommand>(conf)}
        }
    ));
    for (auto& [site, rooms] : conf.rooms) {
        for (auto& room : rooms) {
            chat.join(site, room);
        }
    }
}


}
