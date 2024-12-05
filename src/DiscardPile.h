#define DISCARDPILE_H

#include <vector>
#include "Card.h"
#include "Deck.h"

class DiscardPile {
private:
    std::vector<Card *> cards;
public:
    Card* pickUp();                         // Pick up the top card
    Card* top() const;                      // View the top card without removing
    void cleanCards();
    void print(std::ostream &out) const;    // Print all cards in the pile
    DiscardPile& operator+=(Card*);         // Add card

    friend std::ostream& operator<<(std::ostream& out, const DiscardPile& pile);
};