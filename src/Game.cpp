#include <iostream>
#include "Game.h"

using namespace std;
int main(int argc, char const *argv[])
{
    string existingGame;
    cout << "Do you have a saved game? y/n" << endl;
    cin >> existingGame;

    if (existingGame[0] == 'y')
    {
        // load from file.....
        // TODO: Implement save and load functions if we have time
    }
    else
    {
        // Setup
        string player1Name;
        cout << "Enter player 1 name : " << endl;
        cin >> player1Name;

        string player2Name;
        cout << "Enter player 2 name : " << endl;
        cin >> player2Name;

        Player* pPlayer1 = new Player(player1Name);
        Player* pPlayer2 = new Player(player2Name);
        Player* pPlayerArray[2] = {pPlayer1, pPlayer2};
        
        Deck* deck = new Deck(); // Should be preshuffled - should happen on init

        // Draw 5 cards each
        for (int i = 0; i < 5; i++)
        {
            //TODO: Add hand to player
            pPlayer1->hand+= deck->draw(); 
            pPlayer2->hand+= deck->draw();
        }
        DiscardPile* pDiscardPile = new DiscardPile();
        TradeArea* pTradeArea = new TradeArea();
        Table* pTable =  new Table(players, deck, discardPile, tradeArea); //TODO change Table init to take references
    }

    bool pause = false;

    // Can we create function signatures not specified in the PDF? | I think we can for sure
    // If not we should update isEmpty in Deck.draw() | //TODO: this
    while (!table->deck->isEmpty)
    {
        if (pause)
        {
            // TODO: implement save to file
            break;
        }
        // Each player has a turn
        for (Player player : table.players){ // make sure this is accessing the players in table memory
            cout << table;
            player.hand+=table.deck.draw();

            // again we will need to update this bool in tradeArea
            if(!table.tradeArea.isEmpty){
            
            // Stopping here, im confused about the implementation for trading
                
            } 

            // TODO: finish a players turn  
        }
    }
}
