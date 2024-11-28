#ifndef CHAIN_H
#define CHAIN_H

#include <stddef.h>
#include <vector>
#include "Card.h"
#include "ChainBase.h"

class IllegalTypeException: public std::exception{
    virtual const char* what() const throw(){
        return "IllegalTypeException";
    }
};

template <typename T>
class Chain : public ChainBase {   
private:
    std::vector<T> cards; //holds pointers to cards in chain
public:
    Chain<T>& operator+=(Card* card) {
        if(typeid(*card) != typeid(T)) {
            throw IllegalTypeException();
        } 
        this->cards.push_back(static_cast<T>(card));
    }

    int sell() {
        if (this->cards.empty()) return 0;
        int numCards = this->cards.size();
        return this->cards.front()->getCardsPerCoin(numCards);
    }
    
    friend std::ostream &operator<<(std::ostream &out, const Chain<T> &chain) {
        out << chain.getName() << ": ";
        for (Card* card : chain.cards) {
            out << *card << " ";
        }
        return out;
    }

    std::string getName() {
        return this->cards[0]->getName();
    }
};

#endif
