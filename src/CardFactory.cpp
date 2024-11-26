#include "../include/CardFactory.h"

CardFactory::instance = nullptr;

CardFactory::CardFactory() {
    // Initialize necessary members here
}

CardFactory& CardFactory::getFactory() {
    // Return the instance of CardFactory
    if (instance == nullptr) {
        instance = new CardFactory();
    }
    return instance;
}

Deck CardFactory::getDeck() const {
    // Create and return a NEW Deck object
    return Deck();
}
