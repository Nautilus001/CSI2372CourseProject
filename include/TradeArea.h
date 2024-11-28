#ifndef TRADEAREA_H
#define TRADEAREA_H

#include <list>
#include "Card.h"
#include "Chain.h"

class TradeArea {
private:
    std::list<Card*> cards;
public:
    TradeArea();
    bool isEmpty();
    TradeArea& operator+=(Card* card);
    bool legal(Card* card) const;
    template <typename T>
    Card* trade(const std::string& beanName);
    int numCards() const;
    friend std::ostream& operator<<(std::ostream& out, const TradeArea& tradeArea);
};

#endif
