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

bool Deck::isEmpty() {
    return empty();
}

Deck::~Deck() {
    for (auto card : *this) {
        delete card;
    }
}