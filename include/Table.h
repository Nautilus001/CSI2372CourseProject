#ifndef TABLE_H
#define TABLE_H

#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"

class Table {
public:
    Table(Player* (players)[2], Deck* deck, TradeArea* tradeArea, DiscardPile* discardPile);
    bool win(std::string &playerName) const;
    void printHand(bool all) const;
    friend std::ostream& operator<<(std::ostream& out, const Table& table);
};

#endif
