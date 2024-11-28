#include "../include/TradeArea.h"

TradeArea::TradeArea() {
    std::list<Chain<Card*>*> chains;
}

bool TradeArea::isEmpty(){
    return chains.empty();
}

TradeArea& TradeArea::operator+=(Card* card) {
    if(legal(card)) {
        for (auto& chain : chains) {
            if(chain->getName() == card->getName()){
                chain->addCard(card);
                break;
            }
        }
    return *this;
    }
}

bool TradeArea::legal(Card* card) const {
    for (const auto& chain : chains) {
        if(chain->getName() == card->getName()){
            return true;
        }
    }
    return false;
}

template <typename T>
Chain<T> TradeArea::trade(const std::string& beanName) {
     for (auto it = chains.begin(); it != chains.end(); ++it) {
        auto chain = *it;
        if (chain->getName() == beanName) {
            Chain<T> returnChain = dynamic_cast<Chain<T>*>(chain);
            if (returnChain) {
                chains.erase(it);
                return returnChain;
            }
            else {
                throw IllegalTypeException();
            }
        }
    }
    throw std::runtime_error("No matching chain found for the given bean name");
}

int TradeArea::numCards() const {
    int count = 0;
    for (const auto& chain : chains) {
        count += chain->numCards();
    }
    return count;
}

std::ostream& operator<<(std::ostream& out, const TradeArea& tradeArea) {
    for (const auto& chain : tradeArea.chains) {
        out << *chain << " ";  // Assuming operator<< is overloaded for Chain
    }
    return out;
}
