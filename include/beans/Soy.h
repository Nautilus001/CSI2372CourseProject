#ifndef SOY_H
#define SOY_H

#include "../Card.h"

class Soy : public Card {
public:
    Soy() = default; 
    ~Soy() override = default;

    // Override pure virtual methods
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
};

#endif
