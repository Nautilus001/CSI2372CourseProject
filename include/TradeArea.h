#ifndef TRADEAREA_H
#define TRADEAREA_H

#include <list>
#include "Card.h"

class TradeArea {
public:
    TradeArea();
    TradeArea& operator+=(Card* card);
    bool legal(Card* card) const;
    Card* trade(const std::string& beanName);
    int numCards() const;
    friend std::ostream& operator<<(std::ostream& out, const TradeArea& tradeArea);
};

#endif
