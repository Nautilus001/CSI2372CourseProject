#ifndef GREEN_H
#define GREEN_H

#include "Card.h"

class Green : public Card {
public:
    Green() = default; 
    ~Green() override = default;

    // Override pure virtual methods
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
};

#endif
