#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include <vector>
#include "Card.h"

class DiscardPile {
public:
    DiscardPile();                          // Constructor
    void addCard(Card* card);               // Add a card to the pile
    Card* pickUp();                         // Pick up the top card
    Card* top() const;                      // View the top card without removing
    void print(std::ostream& out) const;    // Print all cards in the pile
    
    friend std::ostream& operator<<(std::ostream& out, const DiscardPile& pile);
};

#endif