#ifndef STINK_H
#define STINK_H

#include "../Card.h"

class Stink : public Card {
public:
    Stink() = default; 
    ~Stink() override = default;

    // Override pure virtual methods
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
};

#endif
