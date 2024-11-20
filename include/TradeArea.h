#ifndef TRADEAREA_H
#define TRADEAREA_H

#include <vector>
#include "Card.h"
#include "Chain.h"

class TradeArea {
private:
    std::vector<Chain<Card*>> chains;
public:
    bool isEmpty();
    TradeArea();
    TradeArea& operator+=(Card* card);
    bool legal(Card* card) const;
    Card* trade(const std::string& beanName);
    int numCards() const;
    friend std::ostream& operator<<(std::ostream& out, const TradeArea& tradeArea);
};

#endif
