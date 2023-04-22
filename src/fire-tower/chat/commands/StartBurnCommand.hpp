#pragma once

#include "stackchat/chat/Command.hpp"
namespace firetower {

class StartBurnCommand : public stackchat::Command {
public:
    void onMessage(stackchat::Room& room,
                   const stackchat::ChatEvent& receivedMessage,
                   const std::vector<std::string> &vArgs) override;
};

}
