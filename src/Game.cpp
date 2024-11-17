#include <iostream>

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

        Player player1 = new Player(player1Name);
        Player player2 = new Player(player2Name);
        Player[] players = {player1, player2};
        
        Deck deck = Deck.getDeck(); // Should be preshuffled

        // Draw 5 cards each
        for (int i = 0; i < 5; i++)
        {
            player1.hand+= deck.draw();
            player2.hand+= deck.draw();
        }
        DiscardPile discardPile = new DiscardPile();
        TradeArea tradeArea = new TradeArea();
        Table table =  new Table(players, deck, discardPile, tradeArea);
    }

    bool pause = false;

    // Can we create function signatures not specified in the PDF?
    // If not we should update isEmpty in Deck.draw()
    while (!table.deck.isEmpty)
    {
        if (pause)
        {
            // TODO: implement save to file
            break;
        }
        // Each player has a turn
        for (Player player : table.players){ // make sure this is accessing the players in table memory
            cout << table;
            player.hand+=table.deck.draw()

            // again we will need to update this bool in tradeArea
            if(!table.tradeArea.isEmpty){
            
            // Stopping here, im confused about the implementation for trading
                
            } 

            // TODO: finish a players turn  
        }
    }
}
