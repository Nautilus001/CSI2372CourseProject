#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include <vector>
#include "Card.h"
#include "Deck.h"

class CardFactory {
private:
    static CardFactory instance;
    CardFactory();
public:
    static CardFactory& getFactory();
    Deck getDeck() const;
};

#endif