#pragma once

#include "fire-tower/config/Config.hpp"

#include "stackchat/chat/Command.hpp"

namespace firetower {

class StartBurnCommand : public stackchat::Command {
public:
    Config& conf;
    StartBurnCommand(Config& conf) : conf(conf) {}

    void onMessage(stackchat::Room& room,
                   const stackchat::ChatEvent& receivedMessage,
                   const std::vector<std::string> &vArgs) override;
};

}
