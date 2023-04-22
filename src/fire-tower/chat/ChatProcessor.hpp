#pragma once

#include "fire-tower/config/Config.hpp"
#include "fire-tower/data/Database.hpp"
#include <stackchat/StackChat.hpp>

namespace firetower {

class ChatProcessor {
private:
    Config& conf;
    Database& db;

public:
    stackchat::StackChat chat;

    ChatProcessor(Config& conf, Database& db);

};

}
