#pragma once

#include "fire-tower/config/Config.hpp"
#include <stackchat/StackChat.hpp>

namespace firetower {

class ChatProcessor {
private:
    Config& conf;

public:
    stackchat::StackChat chat;

    ChatProcessor(Config& conf);

};

}
