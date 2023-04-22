#include "FunCommands.hpp"

namespace firetower {


void AliveCommand::onMessage(stackchat::Room& room, const stackchat::ChatEvent& receivedMessage, const std::vector<std::string> &vArgs) {
    room.reply(receivedMessage, "Nope. Completely dead."); 
}

}
