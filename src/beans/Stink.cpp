#include "beans/Stink.h"

// Override getCardsPerCoin
int Stink::getCardsPerCoin(int cards) const {
    if (cards >= 8) return 4;
    if (cards >= 7) return 3;
    if (cards >= 5) return 2;
    if (cards >= 3) return 1;
    return 0;
}

// Override getName
std::string Stink::getName() const {
    return "Stink";
}

// Override print
void Stink::print(std::ostream& out) const {
    out << "S";
}
