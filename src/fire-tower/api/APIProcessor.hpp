#pragma once

#include "fire-tower/config/Config.hpp"
#include "stackchat/StackChat.hpp"
#define API_KEY "*39b0zMWlwvur57zPqTb*w(("
#define CLIENT_ID 26052

#include "stackapi/StackAPI.hpp"

namespace firetower {

class APIProcessor {
private:
    static std::shared_ptr<spdlog::logger> logger;
    
    stackapi::StackAPI api {
        {
            .apiKey{API_KEY},
            .site{"stackoverflow"},
            .userAgent{"FireTower/git (+https://github.com/LunarWatcher/fire-tower)"}
        }
    };

    Config& conf;
    stackchat::StackChat& chat;

public:
    APIProcessor(stackchat::StackChat& chat, Config& conf);

    void run();
};

}

