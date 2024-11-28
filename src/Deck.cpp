#include "../include/Deck.h"
#include <memory>
#include <random>
#include <algorithm>
#include "Deck.h"

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

Deck::~Deck() {
    for (auto card : *this) {
        delete card;
    }
}

std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    out << "Deck contents: \n";
    for (const auto& card : deck) {
        out << *card << "\n";
    }
    return out;
}