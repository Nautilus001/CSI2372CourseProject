#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include <memory>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "beans/Black.h"
#include "beans/Blue.h"
#include "beans/Chili.h"
#include "beans/Garden.h"
#include "beans/Green.h"
#include "beans/Red.h"
#include "beans/Soy.h"
#include "beans/Stink.h"


class CardFactory
{
private:
    static CardFactory* instance;
    Deck deck;
public:
    static CardFactory* getFactory();
    CardFactory();
    Deck &getDeck();
    void shuffleDeck();
};

#endif