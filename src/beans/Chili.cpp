#include "beans/Chili.h"

// Override getCardsPerCoin
int Chili::getCardsPerCoin(int cards) const {
    if (cards >= 9) return 4;
    if (cards >= 8) return 3;
    if (cards >= 6) return 2;
    if (cards >= 3) return 1;
    return 0;
}

// Override getName
std::string Chili::getName() const {
    return "Chili";
}

// Override print
void Chili::print(std::ostream& out) const {
    out << "C";
}
