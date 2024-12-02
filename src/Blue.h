#ifndef BLUE_H
#define BLUE_H

#include "Card.h"

class Blue : public Card {
public:
    Blue() = default; 
    ~Blue() override = default;

    // Override pure virtual methods
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
};

#endif
