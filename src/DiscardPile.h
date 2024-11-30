#define DISCARDPILE_H

#include <vector>
#include "Card.h"
#include "Deck.h"

class DiscardPile {
private:
    std::vector<Card*> cards;
public:
    DiscardPile();                          // Constructor
    Card* pickUp();                         // Pick up the top card
    Card* top() const;                      // View the top card without removing
    void print(std::ostream& out) const;    // Print all cards in the pile
    DiscardPile& operator+=(Card*);         // Add card

    friend std::ostream& operator<<(std::ostream& out, const DiscardPile& pile);
};