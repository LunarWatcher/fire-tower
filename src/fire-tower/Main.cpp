#include "fire-tower/FireTower.hpp"
#include <iostream>

int main(int argc, const char* argv[]) {
    if (argc > 1) {
        // I can't remember what I did this for
        //if (argv[1] == "")
    } else {
        firetower::FireTower{}.run();
    }
}
