#ifndef RED_H
#define RED_H

#include "../Card.h"

class Red : public Card {
public:
    Red() = default; 
    ~Red() override = default;

    // Override pure virtual methods
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
};

#endif
