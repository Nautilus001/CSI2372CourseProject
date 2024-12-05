#ifndef TRADEAREA_H
#define TRADEAREA_H

#include <list>
#include "Card.h"
#include "Chain.h"

class TradeArea {
public:
    std::list<Card*> cards;
public:
    bool isEmpty() const;
    std::vector<Card *> getCards() const;
    TradeArea& operator+=(Card* card);
    bool legal(Card* card) const;
    Card* trade(const std::string& beanName);
    int numCards() const;
    Card* pop();
    friend std::ostream &operator<<(std::ostream &out, const TradeArea &tradeArea);
};

#endif
