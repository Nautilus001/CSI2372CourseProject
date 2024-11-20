#ifndef CHAIN_H
#define CHAIN_H

#include <stddef.h>
#include <vector>
#include "Card.h"

template <typename T>
class Chain {   
private:
    std::vector<Card*> beans;
public:
    Chain();                                // Constructor
    Chain<T>& operator+=(Card* card);          // Add a card to the chain
    int sell() const;                       // Calculate coins earned from chain
    friend std::ostream& operator<<(std::ostream& out, const Chain<Card*>& chain);
};

#endif
