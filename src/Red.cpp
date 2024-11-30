#include "Red.h"

// Override getCardsPerCoin
int Red::getCardsPerCoin(int cards) const {
    if (cards >= 5) return 4;
    if (cards >= 4) return 3;
    if (cards >= 3) return 2;
    if (cards >= 2) return 1;
    return 0;
}

// Override getName
std::string Red::getName() const {
    return "Red";
}

// Override print
void Red::print(std::ostream& out) const {
    out << "R";
}
