#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"

class Table
{
private:
    std::vector<Player*> players;
    Deck deck;
    DiscardPile discardPile;
    TradeArea tradeArea;
public:
    Table(std::vector<Player *> players, Deck *deck, TradeArea *tradeArea, DiscardPile *discardPile);
    bool win(std::string &playerName) const;
    void printHand(bool all) const;
    std::vector<std::string> getPlayerNames() const;    
    friend std::ostream &operator<<(std::ostream &out, const Table &table);
};

#endif
