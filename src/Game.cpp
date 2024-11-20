#include <iostream>
#include <string.h>
#include "..\include\CardFactory.h"
#include "..\include\Table.h"
#include "..\include\Hand.h"

using namespace std;
int main(int argc, char const *argv[])
{
    // set up uninitilized pointers
    Player *player1;
    Player *player2;
    Player *playerArray[2] = {player1, player2};
    Deck *pDeck;
    DiscardPile *pDiscardPile;
    TradeArea *pTradeArea;
    Table *pTable = new Table(playerArray, pDeck, pTradeArea, pDiscardPile);

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
        cout << "Enter player 1 name: " << endl;
        cin >> player1Name;

        string player2Name;
        cout << "Enter player 2 name: " << endl;
        cin >> player2Name;

        player1 = new Player(player1Name);
        player2 = new Player(player2Name);

        Deck d = CardFactory::getFactory().getDeck();
        pDeck = &d;

        // Draw 5 cards each
        for (int i = 0; i < 5; i++)
        {
            // Make sure creating a hand is part of player
            player1->hand += pDeck->draw();
            player2->hand += pDeck->draw();
        }

        pDiscardPile = new DiscardPile();
        pTradeArea = new TradeArea();
    }

    bool pause = false;

    while (!pDeck->isEmpty())
    {
        if (pause)
        {
            // TODO: implement save to file
            break;
        }

        // Each player has a turn
        for (Player *player : playerArray)
        {
            cout << *pTable;
            player->hand += pDeck->draw();

            if (!pTradeArea->isEmpty())
            {
                char takeACard[10] = ""; // [10] to give extra space, we might want to use a single char here
                                         // instructions are not clear on this, I made it a string since tradeArea.trade(const std::string& beanName)                    do
                {
                    cout << "What card would you like to take? (\"none\" to skip)" << endl;
                    cin >> takeACard;
                    if (strcmp("none", takeACard) != 0)
                    {
                        pTradeArea->trade(takeACard); // parsing should be done in this function
                    }
                }
                while (strcmp(takeACard, "none") != 0 && !pTradeArea->isEmpty()); // While the player doesnt want to skip and tradeArea isnt empty
            }

            cout << "You played: " << player->hand.play() << endl;

            //   If chain is ended, cards for chain are removed and player receives coin(s).

            cout << "Your top card is: " << player->hand.top() << endl;
            cout << "Would you like to play this card? (y/n)" << endl;
            string playACard;
            cin >> playACard;
            if (playACard[0] == 'y')
            {
                cout << "You played: " << player->hand.play() << endl;
            }

            //   If chain is ended, cards for chain are removed and player receives coin(s).

            cout << "Would you like to discard a card? (y/n)" << endl;
            string disgardACard;
            cin >> disgardACard;
            if (disgardACard[0] == 'y')
            {
                player->printHand(cout, true); // print entire hand
                int cardToDiscard;
                cout << "Which card will you discard? " << endl;
                cin >> cardToDiscard;
                *pDiscardPile += player->hand[cardToDiscard]; // We need to POP from players hand
            }
            // TODO: finish a players turn
        }
    }
}
