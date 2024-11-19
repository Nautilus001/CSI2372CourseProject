#ifndef GARDEN_H
#define GARDEN_H

#include "Card.h"

class Garden : public Card {
public:
    Garden() = default; 
    ~Garden() override = default;

    // Override pure virtual methods
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
};

#endif
