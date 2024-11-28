#include "../include/Table.h"

Table::Table(Player **players, Deck *deck, TradeArea *tradeArea, DiscardPile *discardPile) {
    // Initialize players
    this->players[0] = *players[0]; // Player 1
    this->players[1] = *players[1]; // Player 2

    this->deck = *deck;
    this->discardPile = *discardPile;
    this->tradeArea = *tradeArea;
}

bool Table::win(std::string& playerName) const {
    if (deck.isEmpty()) {
        if (players[0].getNumCoins() > players[1].getNumCoins()) {
            playerName = players[0].getName();
            return true;
        } else if (players[1].getNumCoins() > players[0].getNumCoins()) {
            playerName = players[1].getName();
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

std::ostream& operator<<(std::ostream& out, const Table& table) {
    out << "Players: \n";
    
    for (int i = 0; i < 2; ++i) {
        out << "Player " << (i + 1) << ": " << table.players[i] << "\n";
    }

    out << "Deck: \n";
    out << table.deck << "\n";

    out << "Discard Pile: \n";
    out << table.discardPile << "\n";

    out << "Trade Area: \n";
    out << table.tradeArea << "\n";

    return out;
}