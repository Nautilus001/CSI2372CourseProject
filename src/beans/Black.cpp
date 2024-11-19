#include "beans/Black.h"

// Override getCardsPerCoin
int Black::getCardsPerCoin(int cards) const {
    if (cards >= 6) return 4;
    if (cards >= 5) return 3;
    if (cards >= 4) return 2;
    if (cards >= 2) return 1;
    return 0;
}

// Override getName
std::string Black::getName() const {
    return "Black";
}

// Override print
void Black::print(std::ostream& out) const {
    out << "b";
}
