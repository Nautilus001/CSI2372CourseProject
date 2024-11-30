#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include <memory>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Blue.h"
#include "Black.h"
#include "Chili.h"
#include "Garden.h"
#include "Green.h"
#include "Red.h"
#include "Soy.h"
#include "Stink.h"

class CardFactory
{
private:
    static CardFactory* instance;
    Deck deck;
public:
    static CardFactory* getFactory();
    CardFactory();
    Card *createCard(const std::string &beanType);
    Deck &getDeck();
    void shuffleDeck();
};

#endif