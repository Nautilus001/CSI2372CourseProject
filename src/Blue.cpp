#include "Blue.h"

// Override getCardsPerCoin
int Blue::getCardsPerCoin(int cards) const {
    if (cards >= 10) return 4;
    if (cards >= 8) return 3;
    if (cards >= 6) return 2;
    if (cards >= 4) return 1;
    return 0;
}

// Override getName
std::string Blue::getName() const {
    return "Blue";
}

// Override print
void Blue::print(std::ostream& out) const {
    out << "B";
}
