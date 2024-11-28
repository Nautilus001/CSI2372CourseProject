#include "../include/DiscardPile.h"

DiscardPile::DiscardPile() {
    std::vector<Card*> cards;
}

DiscardPile& DiscardPile::operator+=(Card* card) {
    cards.push_back(card);
    return *this;
}

Card* DiscardPile::pickUp() {
    if (!cards.empty()) {
        Card* front =  cards.front();
        cards.erase(cards.begin());
        return front;
    }
    return nullptr;
}

Card* DiscardPile::top() const {
    if (!cards.empty()) {
        return cards.front();
    }
    return nullptr;
}

void DiscardPile::print(std::ostream& out) const {
    Card* topCard = top();
    topCard->print(out);
}

std::ostream& operator<<(std::ostream& out, const DiscardPile& pile) {
    pile.print(out);
    return out;
}
