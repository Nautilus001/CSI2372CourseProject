#include "beans/Green.h"

// Override getCardsPerCoin
int Green::getCardsPerCoin(int cards) const {
    if (cards >= 7) return 4;
    if (cards >= 6) return 3;
    if (cards >= 5) return 2;
    if (cards >= 3) return 1;
    return 0;
}

// Override getName
std::string Green::getName() const {
    return "Green";
}

// Override print
void Green::print(std::ostream& out) const {
    out << "G";
}
