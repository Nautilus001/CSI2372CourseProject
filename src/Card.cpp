#include "Card.h"

// Stream insertion impl
std::ostream& operator<<(std::ostream& out, const Card& card) {
    card.print(out);
    return out;
}
