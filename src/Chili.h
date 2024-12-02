#ifndef CHILI_H
#define CHILI_H

#include "Card.h"

class Chili : public Card {
public:
    Chili() = default; 
    ~Chili() override = default;

    // Override pure virtual methods
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
};

#endif
