#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand {
private:
    std::vector<Card*> cards;
public:
    Hand() = default;
    Hand& operator+=(Card* card);
    Card* play();
    Card* top() const;
    Card* operator[](int index);
    friend std::ostream& operator<<(std::ostream& out, const Hand& hand);
    bool empty();
};

#endif
