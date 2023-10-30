#include <iostream>
#include <tuple>

#include "MoveAndCopyCounter.hpp"

int main() {
    MoveAndCopyCounter c;
    auto t = std::make_tuple(c);

    auto t2 = t;

    std::cout << MoveAndCopyCounter::getStats() << '\n';

    return 0;
}
