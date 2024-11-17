#ifndef HAND_H
#define HAND_H

#include <list>
#include "Card.h"

class Hand {
public:
    Hand();
    Hand& operator+=(Card* card);
    Card* play();
    Card* top() const;
    Card* operator[](int index);
    friend std::ostream& operator<<(std::ostream& out, const Hand& hand);
};

#endif
