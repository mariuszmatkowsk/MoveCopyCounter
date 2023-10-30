#pragma once

#include <iostream>

struct Stats {
    explicit Stats()
        : defaultCtorCount(0)
        , copyCount(0)
        , moveCount(0) {}

    unsigned defaultCtorCount;
    unsigned copyCount;
    unsigned moveCount;

    friend std::ostream& operator<<(std::ostream& os, const Stats& stats) {
        os << "defaultCtorCount: " << stats.defaultCtorCount
            << ", copyCount: " << stats.copyCount
            << ", moveCount: " << stats.moveCount << '\n';
        return os;
    }
};

class MoveAndCopyCounter {
public:
    inline static Stats stats{};

    MoveAndCopyCounter() {
        ++stats.defaultCtorCount;
    }

    MoveAndCopyCounter(MoveAndCopyCounter const&) {
        ++stats.copyCount;
    }

    MoveAndCopyCounter& operator=(MoveAndCopyCounter const&) {
        ++stats.copyCount;
        return *this;
    }

    MoveAndCopyCounter(MoveAndCopyCounter&&) noexcept {
        ++stats.moveCount;
    }

    MoveAndCopyCounter& operator=(MoveAndCopyCounter&&) noexcept {
        ++stats.moveCount;
        return *this;
    }

    static Stats getStats() {
        return stats;
    }
};
