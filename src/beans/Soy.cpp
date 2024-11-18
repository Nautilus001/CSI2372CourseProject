#include "beans/Soy.h"

// Override getCardsPerCoin
int Soy::getCardsPerCoin(int cards) const {
    if (cards >= 7) return 4;
    if (cards >= 6) return 3;
    if (cards >= 4) return 2;
    if (cards >= 2) return 1;
    return 0;
}

// Override getName
std::string Soy::getName() const {
    return "Soy";
}

// Override print
void Soy::print(std::ostream& out) const {
    out << "s";
}
