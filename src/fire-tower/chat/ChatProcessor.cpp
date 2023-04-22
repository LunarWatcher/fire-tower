#include "ChatProcessor.hpp"

namespace firetower {

ChatProcessor::ChatProcessor(Config& conf) 
    : 
        chat {
            {
                .email{conf.email},
                .password{conf.password},
                .userAgent{"FireTower/git (+https://github.com/LunarWatcher/fire-tower)"}
            }
        },
        conf(conf) {
    

    for (auto& [site, rooms] : conf.rooms) {
        for (auto& room : rooms) {
            chat.join(site, room);
        }
    }
}

std::shared_ptr<ChatProcessor> createProcessor() {

}

}
