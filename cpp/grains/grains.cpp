#include "grains.h"

#include <cmath>

namespace grains {
    unsigned long long square(int n)
    {
        return std::pow(2, n - 1);
    }

    unsigned long long total() {
        // For an 8x8 board with N=64 squares: pow(2,N) - 1
        return 18446744073709551615ULL; // Cheeky! :P  

    }
}  // namespace grains
