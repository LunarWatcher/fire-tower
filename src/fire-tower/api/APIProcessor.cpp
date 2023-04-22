#include "APIProcessor.hpp"
#include "fire-tower/data/Database.hpp"

namespace firetower {
std::shared_ptr<spdlog::logger> APIProcessor::logger = spdlog::stdout_color_mt("APIProcessor");

APIProcessor::APIProcessor(stackchat::StackChat& chat, Config& conf, Database& db) : chat(chat), conf(conf), db(db) {
    if (!conf.apiAuth.empty()) {
        api.conf.auth = conf.apiAuth;
    }
    logger->info("API ready.");
}

void APIProcessor::run() {
    logger->info("APIProcessor taking main thread...");
    using namespace std::literals;

    while (true) {
        logger->info("It's that time again. I don't get paid enough for this");
        logger->info("Performing checks...");

        logger->info("Checks done. Cya in an hour.");
        std::this_thread::sleep_for(1h);
    }

}

}
