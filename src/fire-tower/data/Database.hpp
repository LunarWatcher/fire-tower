#pragma once

#include <mutex>
#include <string>
#include <vector>
#include <map>
#include "SQLiteCpp/Database.h"
#include "fire-tower/config/Context.hpp"

namespace firetower {

class Database {
private:
    SQLite::Database db{"fire-tower.db", SQLite::OPEN_CREATE | SQLite::OPEN_READWRITE};
public:
    std::mutex lock;

    Database();
    void createBurnination(const std::vector<std::string>& tags);

};

}
