#include "Table.h"

Table::Table(Player* (&players)[2], Deck* deck, TradeArea* tradeArea, DiscardPile* discardPile) {
    // init the table with its components
}

bool Table::win(std::string& playerName) const {
    // Determine if a player has won and set winner name
    return false;
}

void Table::printHand(bool all) const {
    // Print the top card or the entire hand (all triggewr)
}

std::ostream& operator<<(std::ostream& out, const Table& table) {
    // Print out the table state
    return out;
}
