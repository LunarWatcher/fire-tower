#include "StartBurnCommand.hpp"


namespace firetower {

void StartBurnCommand::onMessage(
    stackchat::Room& room,
    const stackchat::ChatEvent& ev,
    const std::vector<std::string>& vArgs
) {
    if (!conf.isSuperUser(room.site, ev)) {
        room.reply(ev, "Start yourself.");
        return;
    } else if (vArgs.size() == 0) {
        room.reply(ev, "Specify which tags to track.");
        return;
    }
    // TODO: make the statement not a blatant lie

    room.reply(ev, "Burn started.");
}

}
