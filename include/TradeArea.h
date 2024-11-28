#ifndef TRADEAREA_H
#define TRADEAREA_H

#include <list>
#include "Card.h"
#include "Chain.h"

class TradeArea {
private:
    std::list<Chain<Card*>*> chains;
public:
    bool isEmpty();
    TradeArea();
    TradeArea& operator+=(Card* card);
    bool legal(Card* card) const;
    template <typename T>
    Chain<T> trade(const std::string& beanName);
    int numCards() const;
    friend std::ostream& operator<<(std::ostream& out, const TradeArea& tradeArea);
};

#endif
