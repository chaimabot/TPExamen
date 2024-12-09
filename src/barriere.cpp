#include "Barriere.h"
#include <iostream>

namespace Parking {
    void open() {
        std::cout << "The barrier is now open." << std::endl;
    }

    void close() {
        std::cout << "The barrier is now closed." << std::endl;
    }
}
