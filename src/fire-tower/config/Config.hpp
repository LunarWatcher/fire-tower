#pragma once

#include "stackchat/chat/ChatEvent.hpp"
#include "stackchat/rooms/StackSite.hpp"
#include <vector>
#include <map>
#include <nlohmann/json.hpp>

namespace firetower {

struct SiteRoomList {
    stackchat::StackSite site;
    std::vector<unsigned int> rooms;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(SiteRoomList, site, rooms);
};
struct SiteSudoList {
    stackchat::StackSite site;
    std::vector<long long> users;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(SiteSudoList, site, users);
};

struct Config {
    std::string email;
    std::string password;
    std::string apiAuth;


    std::vector<SiteRoomList> rooms;
    std::vector<SiteSudoList> sudo;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(
        Config,
        email,
        apiAuth,
        password,
        rooms,
        sudo
    );

    bool isSuperUser(const stackchat::StackSite& site, const stackchat::ChatEvent& ev) {
        for (auto& [site_, users] : sudo) {
            if (site_ == site) {
                return std::find(users.begin(), users.end(), ev.user_id) != users.end();
            }
        }
        return false;
    }
};

}
