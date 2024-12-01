#include <iostream>
#include <string.h>
#include <vector>
#include "CardFactory.h"
#include "Table.h"
#include "Hand.h"
#include "Player.h"

using namespace std;

void addCardToPlayerChain(Player *p, Card *c)
{
    cout << "enter addCTPC" << endl;
    cout << "chain status: " << p->getNumChains() << "/" << p->getMaxNumChains() << endl;
    // if there is an empty field
    if (p->getNumChains() < p->getMaxNumChains())
    {
        cout << "current chains: " << p->getNumChains() << endl;
        
        p->operator[](p->getNumChains()) += c;
        cout << "added to chain" << endl;
        //TODO: Edge case where they dont have max chain, but also already have a chain of this type
    }
    else
    {
        cout << "at max chains: " << endl;
        bool chainTypeExists = false;
        // If the player already has a chain of this type
        for (int i = 0; i < p->getNumChains(); i++)
        {
            if (c->getName() == p->operator[](i).getName())
            {
                cout << "natching chain found" << endl;
                chainTypeExists = true;
                p->operator[](i) += c;
                cout << "added" << endl;
                break;
            }
        }
        // If not
        if (!chainTypeExists)
        {
            cout << "You must sell a chain, which field will you harvest? (1";
            if (p->getNumChains() > 1) {
                cout << ", 2";
            }
            if (p->getNumChains() > 2) {
                cout << ", 3";
            }
            cout << ")" << endl;
            int j;
            cin >> j;
            p += p->operator[](j - 1).sell(); // Sell the chain
            p->operator[](j - 1) += c;        // Add the chain to the player
        }
    }
    cout << "done addCTPC" << endl;
}

void takeCardFromTradeArea(Player *p, TradeArea *ta)
{
    cout << "enter takeCardFromTradeArea" << endl;
    //   If TradeArea is not empty
    // this is only relevant for the first turn, we may want to move the long trade area logic out of main for readability
    if (!ta->isEmpty())
    {
        cout << "ta is not empty" <<endl;
        //    Add bean cards from the TradeArea to chains or discard them.
        string selectedChain = "";
        do
        {
            cout << "What chain would you like to take? (\"none\" to skip)" << endl;
            cin >> selectedChain;

            if (selectedChain != "none") {
                try {
                    auto chain = ta->trade(selectedChain);
                    if (chain) { 
                        addCardToPlayerChain(p, chain);  
                    } else {
                        std::cout << "Trade failed: no card found for the selected chain." << std::endl;
                    }
                } catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << std::endl;  // Handle trade failure
                }
            }
        } while (selectedChain != "none" && !ta->isEmpty()); // While the player doesnt want to skip and tradeArea isnt empty
    }
    cout << "ta is empty" << endl;
}

int main(int argc, char const *argv[])
{

    // set up uninitilized pointers
    CardFactory* cardFactory = new CardFactory();
    Player *player1 = nullptr;
    Player *player2 = nullptr;
    vector<Player *> playerArray;
    Deck *pDeck = nullptr;
    DiscardPile *pDiscardPile = nullptr;
    TradeArea *pTradeArea = nullptr;
    Table *pTable = nullptr;

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
        cout << "begin setup" << endl;
        // Setup
        string player1Name;
        cout << "Enter player 1 name: " << endl;
        cin >> player1Name;

        string player2Name;
        cout << "Enter player 2 name: " << endl;
        cin >> player2Name;

        player1 = new Player(player1Name);
        player2 = new Player(player2Name);
        playerArray.push_back(player1);
        playerArray.push_back(player2);

        Deck d = cardFactory->getDeck();
        pDeck = &d;

        // Draw 5 cards each
        for (int i = 0; i < 5; i++)
        {
            cout << i;
            // Make sure creating a hand is part of player
            player1->hand += pDeck->draw();
            player2->hand += pDeck->draw();
        }

        pDiscardPile = new DiscardPile();
        pTradeArea = new TradeArea();
        cout << "making a table" << endl;
        pTable = new Table(playerArray, pDeck, pTradeArea, pDiscardPile);
        cout << "end setup" << endl;
    }

    bool pause = false;

    // While there are still cards on the Deck
    while (!pDeck->isEmpty())
    {
        cout << "deck is not empty" << endl;

        //  if pause save game to file and exit
        if (pause)
        {
            // TODO: implement save to file
            break;
        }

        //  For each Player
        for (Player *player : playerArray)
        {
            cout << "player turn" << endl;
            //   Display Table
            cout << *pTable; // This should display all the information except for the players hand
            //   Player draws top card from Deck
            player->hand += pDeck->draw();

            // IMPORTANT: The code given in the PDF gives no option to buy a third field
            //            we should give the option to here if the player has not already done so AND has enough coins

            takeCardFromTradeArea(player, pTradeArea);

            // First card must be played
            char playACard = 'y'; // could make this more robust using char array
            while (playACard == 'y')
            {
                //    Play the topmost card from Hand.
                Card *card = player->hand.play();
                cout << "You played: " << *card << endl;

                // Add to a chain
                cout << "call to add" << endl;
                addCardToPlayerChain(player, card);

                // if player decides to
                cout << "Your top card is: " << player->hand.top() << endl;
                cout << "Would you like to play this card? (y/n)" << endl;
                cin >> playACard;
            }

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

            //     if player wants to chain the card
            takeCardFromTradeArea(player, pTradeArea);
            //     else card remains in trade area for the next player.

            // Draw two cards from Deck and add the cards to the player's hand (at the back).
            player->hand += (pDeck->draw());
            player->hand += (pDeck->draw());
        }
    }

    string p1Name = player1->getName();
    if (pTable->win(p1Name))
    {
        cout << player1->getName() << " wins!" << endl;
    }
    else
    {
        cout << player2->getName() << " wins!" << endl;
    }
}