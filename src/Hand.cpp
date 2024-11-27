#include "../include/Hand.h"

Hand::Hand() {
    // Initialize the hand
}

Hand& Hand::operator+=(Card* card) {
    // Add given card to the back of the hand
    return *this;
}

Card* Hand::play() {
    // Remove and returnr the top card from the hand
    return nullptr; // Placeholder return value
}

Card* Hand::top() const {
    // Return the top card without removing it
    return nullptr; // Placeholder return value
}

Card* Hand::operator[](int index) {
    // POP the card at the given index
    return nullptr; // Placeholder return value
}

std::ostream& operator<<(std::ostream& out, const Hand& hand) {
    // Print all cards
    return out;
}
