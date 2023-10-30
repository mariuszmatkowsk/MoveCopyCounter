#include <iostream>

#include "MoveAndCopyCounter.hpp"

int main() {
    MoveAndCopyCounter c;

    std::cout << c.getStats() << '\n';

    return 0;
}
