#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();                                
    Card* draw();                          
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck);
};

#endif