#include "DiscardPile.h"

DiscardPile::DiscardPile() {
    // init the discard pile
}

DiscardPile& DiscardPile::operator+=(Card* card) {
    // Add the given card to the top of the discard pile
}

Card* DiscardPile::pickUp() {
    // Remove and return the top card from discard pile
    return nullptr;
}

Card* DiscardPile::top() const {
    // Return the top card without removing it
    return nullptr;
}

void DiscardPile::print(std::ostream& out) const {
    // Print cards in the discard pile to the output stream
}

std::ostream& operator<<(std::ostream& out, const DiscardPile& pile) {
    // Print only the top card of the discard pile
    return out;
}
