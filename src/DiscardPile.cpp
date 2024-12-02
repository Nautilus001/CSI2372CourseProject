#include "DiscardPile.h"

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
    return nullptr; // This will print as a 0 when there are no cards in the pile
}

void DiscardPile::print(std::ostream& out) const {
    for (auto& card : this->cards) {
        card->print(out);
    }
    out << std::endl;
}

std::ostream& operator<<(std::ostream& out, const DiscardPile& pile) {
    out << pile.top();
    return out;
}
