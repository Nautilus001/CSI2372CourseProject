#include "../include/TradeArea.h"

TradeArea::TradeArea() {
    // init the trade area
}

bool TradeArea::isEmpty(){
    return chains.empty();
}

TradeArea& TradeArea::operator+=(Card* card) {
    // Add the card to the trade area
    return *this;
}

bool TradeArea::legal(Card* card) const {
    // Check if the given card can be added based oin rules
    return false;
}

Card* TradeArea::trade(const std::string& beanName) {
    // Remove and return a card matching the given bean name
    return nullptr;
}

int TradeArea::numCards() const {
    // Return the num of cards in the trade area
    return 0;
}

std::ostream& operator<<(std::ostream& out, const TradeArea& tradeArea) {
    // Print all cards in trade aresa
    return out;
}
