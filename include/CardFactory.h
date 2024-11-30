#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include <memory>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "../include/beans/Blue.h"
#include "../include/beans/Black.h"
#include "../include/beans/Chili.h"
#include "../include/beans/Garden.h"
#include "../include/beans/Green.h"
#include "../include/beans/Red.h"
#include "../include/beans/Soy.h"
#include "../include/beans/Stink.h"

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