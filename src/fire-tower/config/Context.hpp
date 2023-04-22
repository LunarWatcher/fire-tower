#pragma once

#include <vector>
#include <string>

namespace firetower {

struct Burnination {
    long long id;
    std::vector<std::string> tags;
};

struct Context {
    std::vector<Burnination> ongoing;
};

}
