#pragma once

#include "fire-tower/config/Config.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace firetower {

class FireTower {
private:
    static std::shared_ptr<spdlog::logger> logger;
    Config conf;
public:
    FireTower();
    void run();
};

}
