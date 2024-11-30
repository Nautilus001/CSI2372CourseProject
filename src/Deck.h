#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck : public std::vector<Card*> {
public:
   Deck() = default;
   Card* draw();
   bool isEmpty() const;
   friend std::ostream &operator<<(std::ostream &out, const Deck &deck);
};

#endif