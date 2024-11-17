#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include "Card.h"

template <typename T>
class Chain {
public:
    Chain();                                // Constructor
    Chain& operator+=(Card* card);          // Add a card to the chain
    int sell() const;                       // Calculate coins earned from chain
    friend std::ostream& operator<<(std::ostream& out, const Chain<T>& chain);
};

#endif
