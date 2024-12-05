#include "DiscardPile.h"
#include <algorithm>

DiscardPile& DiscardPile::operator+=(Card* card) {
    if (card != nullptr) {
        std::cout << "Pushing";
        this->cards.push_back(card);
        std::cout << "pushed";
    } else {
        std::cout << "Nullptr";
    }
    
    return *this;
}

Card* DiscardPile::pickUp() {
    if (!cards.empty()) {
        Card* front = cards.front();
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
    if (cards.empty()) {
        out << "Empty";
    } else {
        for (auto& card : this->cards){
            out << this->cards[0];
        }
    }
    out << std::endl;
}

std::ostream& operator<<(std::ostream& out, const DiscardPile& pile) {
    if (pile.cards.empty()) {
        out << "Empty";
    } else {
        out << pile.cards[0]->getName();
    }
    out << std::endl;
    return out;
}
