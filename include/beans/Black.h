#ifndef BLACK_H
#define BLACK_H

#include "../Card.h"

class Black : public Card {
public:
    Black() = default; 
    ~Black() override = default;

    // Override pure virtual methods
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
};

#endif
