#include "../include/TradeArea.h"

TradeArea::TradeArea() {
    std::list<Card*> cards;
}

bool TradeArea::isEmpty(){
    return this->cards.empty();
}

TradeArea& TradeArea::operator+=(Card* card) {
    if(legal(card)) {
        cards.push_back(card);
    }
    return *this;
}


bool TradeArea::legal(Card* card) const {
    for(const auto& elem : this->cards){
        if(elem->getName() == card->getName()){
            return true;
        }
    }
    return false;
}

Card* TradeArea::trade(const std::string& beanName) {
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        if ((*it)->getName() == beanName) {
            Card* card = *it;
            cards.erase(it);
            return card;
        }
    }
    throw std::runtime_error("No matching card found for the given bean name");
}

int TradeArea::numCards() const {
    return this->cards.size();
}

std::ostream& operator<<(std::ostream& out, const TradeArea& tradeArea) {
    for (const auto& card : tradeArea.cards) {
        out << *card << " ";
    }
    return out;
}
