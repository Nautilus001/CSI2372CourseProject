#include <iostream>
#include "Table.h"
#include <vector>

Table::Table(std::vector<Player *> players, Deck *deck, TradeArea *tradeArea, DiscardPile *discardPile) {
    // Initialize players
    this->players.push_back(players[0]); // Player 1
    this->players.push_back(players[1]); // Player 2

    this->deck = deck;
    this->discardPile = discardPile;
    this->tradeArea = tradeArea;
}

bool Table::win(std::string& playerName) const {
    if (this->deck->isEmpty()) {
        if (players[0]->getNumCoins() > players[1]->getNumCoins()) {
            playerName = players[0]->getName();
            return true;
        } else if (players[1]->getNumCoins() > players[0]->getNumCoins()) {
            playerName = players[1]->getName();
            return true;
        } else {
            playerName = "";
            return false;
        }
    }
    return false;
}

void Table::printHand(bool all) const {
    // Print the top card or the entire hand (all triggewr)
    //This doesnt make sense in the context of the game.
}

std::vector<std::string> Table::getPlayerNames() const{
    std::vector<std::string> names;
    names.push_back(this->players[0]->getName());
    names.push_back(this->players[1]->getName());
    return names;
}

std::ostream& operator<<(std::ostream& out, const Table& table) {
    std::vector<std::string> names = table.getPlayerNames();
    out << "|---------------- TABLE ----------------" << std::endl;
    out << "|Player 1: " << table.players[0]->getName();
    out << " || Player 2: " << table.players[1]->getName() << std::endl;
    out << "|Discard Pile:" << std::endl;
    out << "|    " << *table.discardPile << std::endl;
    out << "|Trade Area: " << std::endl;
    out << "|    " << *table.tradeArea << std::endl;
    out << "|---------------------------------------";
    return out;
}