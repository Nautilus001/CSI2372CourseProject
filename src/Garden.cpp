#include "Garden.h"

// Override getCardsPerCoin
int Garden::getCardsPerCoin(int cards) const {
    if (cards >= 3) return 3;
    if (cards >= 2) return 2;
    return 0;
}

// Override getName
std::string Garden::getName() const {
    return "Garden";
}

// Override print
void Garden::print(std::ostream& out) const {
    out << "g";
}
