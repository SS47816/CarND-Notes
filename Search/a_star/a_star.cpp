#include <math.h>
#include <vector>
#include "a_star.h"

namespace a_star {

// Initializes A_STAR
A_STAR::A_STAR() {}

A_STAR::~A_STAR() {}

inline int huristic_cost(int x, int y, vector<int, int> goal) {
    return std::abs(x - goal[0]) + std::abs(y - goal[1]);
}

int search() {

}

int expand() {
    
}

} // namespace a_star