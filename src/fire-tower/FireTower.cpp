#include "FireTower.hpp"
#include "fire-tower/api/APIProcessor.hpp"
#include "fire-tower/chat/ChatProcessor.hpp"
#include "fire-tower/data/Database.hpp"

#include <fstream>
#include <iostream>
#include <stc/FS.hpp>

namespace firetower {

std::shared_ptr<spdlog::logger> FireTower::logger = spdlog::stdout_color_mt("FireTower");

FireTower::FireTower() {
    if (!fs::exists("fire-tower.json")) {
        logger->error("failed to find fire-tower.json. Please set up the bot correctly.");
        throw std::runtime_error("Failed to find fire-tower.json");
    }

    std::ifstream in("fire-tower.json");

    nlohmann::json j = nlohmann::json::parse(in);
    j.get_to(conf);
    logger->info("Config loaded.");
}

void FireTower::run() {
    logger->info("Loading database...");
    Database db;
    logger->info("Starting fire tower...");
    ChatProcessor chatProcessor(conf, db);
    APIProcessor apiProcessor(chatProcessor.chat, conf, db);

    apiProcessor.run();
}

}
