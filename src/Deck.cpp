#include "../include/Deck.h"

Deck::Deck() {
    // Constructor logic (initializing the deck, etc)
}

bool Deck::isEmpty(){
    return cards.empty();
}

Card* Deck::draw() {
    // draw a card from the deck
    return nullptr;
}

std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    // Logic to print deck
    return out;
}
