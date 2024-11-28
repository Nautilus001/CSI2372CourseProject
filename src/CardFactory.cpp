#include "../include/CardFactory.h"
#include <random>
#include <algorithm>
#include "CardFactory.h"

CardFactory* CardFactory::instance = nullptr;

CardFactory* CardFactory::getFactory() {
    if (!instance) {
        instance = new CardFactory();  // Create the singleton instance
    }
    return instance;
}

CardFactory::CardFactory() {
    //create cards
    for (int i = 0; i < 20; ++i) {
        deck.push_back(new Blue());
    }
    for (int i = 0; i < 18; ++i) {
        deck.push_back(new Chili());
    }
    for (int i = 0; i < 16; ++i) {
        deck.push_back(new Stink());
    }
    for (int i = 0; i < 14; ++i) {
        deck.push_back(new Green());
    }
    for (int i = 0; i < 12; ++i) {
        deck.push_back(new Soy());
    }
    for (int i = 0; i < 10; ++i) {
        deck.push_back(new Black());
    }
    for (int i = 0; i < 8; ++i) {
        deck.push_back(new Red());
    }
    for (int i = 0; i < 6; ++i) {
        deck.push_back(new Garden());
    }
}

Card* CardFactory::createCard(const std::string& beanType) {
    if (beanType == "Blue") {
        return new Blue(); 
    } else if (beanType == "Chili") {
        return new Chili(); 
    } else if (beanType == "Garden") {
        return new Garden();
    } else if (beanType == "Green") {
        return new Green();
    } else if (beanType == "Red") {
        return new Red(); 
    } else if (beanType == "Soy") {
        return new Soy(); 
    } else if (beanType == "Black") {
        return new Black(); 
    } else if (beanType == "Stink") {
        return new Stink(); 
    }

    // Add more cases for other card types
    else {
        throw std::invalid_argument("Unknown bean type: " + beanType);
    }
}

Deck& CardFactory::getDeck() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
    return deck;
}

