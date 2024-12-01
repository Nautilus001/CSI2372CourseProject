#include "Deck.h"
#include <memory>
#include <random>
#include <algorithm>

Card* Deck::draw() {
    if (!empty()) {
        Card* front =  this->front();
        erase(begin());
        return front;
    }
    return nullptr;
}

bool Deck::isEmpty() const {
    return empty();
}

std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    for (const auto& card : deck) {
        out << *card;
    }
    return out;
}