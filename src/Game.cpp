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

    // While there are still cards on the Deck
    while (!pDeck->isEmpty())
    {

        //  if pause save game to file and exit
        if (pause)
        {
            // TODO: implement save to file
            break;
        }

        //  For each Player
        for (Player *player : playerArray)
        {
            //   Display Table
            cout << *pTable;
            //   Player draws top card from Deck
            player->hand += pDeck->draw();

            //   If TradeArea is not empty
            // this is only relevant for the first turn
            if (!pTradeArea->isEmpty())
            {
                //    Add bean cards from the TradeArea to chains or discard them.
                char takeAChain[10] = ""; // [10] to give extra space, we might want to use a single char here
                                          // instructions are not clear on this, I made it a string since tradeArea.trade(const std::string& beanName)                    do
                do
                {
                    cout << "What chain would you like to take? (\"none\" to skip)" << endl;
                    cin >> takeAChain;
                    if (strcmp("none", takeAChain) != 0)
                    {
                        Card *c = (pTradeArea->trade(takeAChain)); // parsing should be done in this function
                        // TODO: plant chain
                    }
                } while (strcmp(takeAChain, "none") != 0 && !pTradeArea->isEmpty()); // While the player doesnt want to skip and tradeArea isnt empty
            }

            //  Play topmost card from Hand.
            cout << "You played: " << player->hand.play() << endl;

            //   If chain is ended, cards for chain are removed and player receives coin(s).
            cout << "Your top card is: " << player->hand.top() << endl;
            cout << "Would you like to play this card? (y/n)" << endl;
            string playACard;
            cin >> playACard;

            //   If player decides to
            if (playACard[0] == 'y')
            {
                //    Play the now topmost card from Hand.
                cout << "You played: " << player->hand.play() << endl;
            }

            //   TODO: If chain is ended, cards for chain are removed and player receives coin(s).

            //   If player decides to
            cout << "Would you like to discard a card? (y/n)" << endl;
            string disgardACard;
            cin >> disgardACard;
            if (disgardACard[0] == 'y')
            {
                // Show the player's full hand and player selects an arbitrary card
                player->printHand(cout, true); // print entire hand
                int cardToDiscard;

                //    Discard the arbitrary card from the player's hand and place it on the discard pile.
                cout << "Which card will you discard? " << endl;
                cin >> cardToDiscard;
                *pDiscardPile += player->hand[cardToDiscard]; // We need to POP from players hand
            }

            //    Draw three cards from the deck and place cards in the trade area
            cout << "The following cards are drawn:" << endl;
            for (int i = 0; i < 3; i++)
            {
                Card *card = pDeck->draw();
                cout << *card << endl;
                *pTradeArea += card;
            }

            //   while top card of discard pile matches an existing card in the trade area
            while (pTradeArea->legal(pDiscardPile->top()))
            {
                //    draw the top-most card from the discard pile and place it in the trade area
                *pTradeArea += (pDiscardPile->pickUp());
            }

            // TODO:
            // for all cards in the trade area
            //     if player wants to chain the card
            //         chain the card.
            //     else card remains in trade area for the next player.

            // Draw two cards from Deck and add the cards to the player's hand (at the back).
            player->hand += (pDeck->draw());
            player->hand += (pDeck->draw());
        }
    }

    if (player1->getNumCoins() > player2->getNumCoins())
    {
        cout << player1->getName() << " wins!" << endl;
    }
    else
    {
        cout << player2->getName() << " wins!" << endl;
    }
}
