#include <iostream>
#include <string.h>
#include <vector>
#include "CardFactory.h"
#include "Table.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void clearScreen()
{
    // for (int i = 0; i < 50; ++i)
    // {
    //     std::cout << std::endl;
    // }
}

void letUserRead(int seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void createNewChainAt(int i, Player *p, Card *c)
{
    if (typeid(*c) == typeid(Black))
    {
        Chain<Black> *newChain = new Chain<Black>(); // Create Chain<Black>
        p->addChain(i, newChain);
        *newChain += c; // Add the card to the newly created chain
    }
    else if (typeid(*c) == typeid(Blue))
    {
        Chain<Blue> *newChain = new Chain<Blue>(); // Create Chain<Blue>
        p->addChain(i, newChain);
        *newChain += c; // Add the card to the newly created chain
    }
    else if (typeid(*c) == typeid(Chili))
    {
        Chain<Chili> *newChain = new Chain<Chili>(); // Create Chain<Chili>
        p->addChain(i, newChain);
        *newChain += c; // Add the card to the newly created chain
    }
    else if (typeid(*c) == typeid(Garden))
    {
        Chain<Garden> *newChain = new Chain<Garden>(); // Create Chain<Garden>
        p->addChain(i, newChain);
        *newChain += c; // Add the card to the newly created chain
    }
    else if (typeid(*c) == typeid(Green))
    {
        Chain<Green> *newChain = new Chain<Green>(); // Create Chain<Green>
        p->addChain(i, newChain);
        *newChain += c; // Add the card to the newly created chain
    }
    else if (typeid(*c) == typeid(Red))
    {
        Chain<Red> *newChain = new Chain<Red>(); // Create Chain<Red>
        p->addChain(i, newChain);
        *newChain += c; // Add the card to the newly created chain
    }
    else if (typeid(*c) == typeid(Soy))
    {
        Chain<Soy> *newChain = new Chain<Soy>(); // Create Chain<Soy>
        p->addChain(i, newChain);
        *newChain += c; // Add the card to the newly created chain
    }
    else if (typeid(*c) == typeid(Stink))
    {
        Chain<Stink> *newChain = new Chain<Stink>(); // Create Chain<Stink>
        p->addChain(i, newChain);
        *newChain += c; // Add the card to the newly created chain
    }
    else
    {
        throw IllegalTypeException();
    }
}

void addCardToPlayerChain(Player *p, Card *c)
{
    if (p == nullptr || c == nullptr)
    {
        cout << "Invalid player or card" << endl;
        return;
    }
    // if there is no existing field
    if (p->getNumChains() == 0)
    {
        createNewChainAt(p->getNumChains(), p, c);
        return;
    }
    // check if this type card type exists in the players hand before starting a new chain
    // case where they dont have max chain, but also already have a chain of this type
    else
    {
        // If the player already has a chain of this type
        for (int i = 0; i < p->getNumChains(); i++)
        {
            if (c->getName() == ((*p)[i]).getName())
            {
                p->operator[](i) += c;
                return;
            }
        }
    }

    // if the card doesnt match but there are still more fields
    if (p->getNumChains() < p->getMaxNumChains())
    {
        createNewChainAt(p->getNumChains(), p, c);
        return;
    }

    // If none of these then we will show then the fields and make them sell one
    cout << "\nYou must sell a chain, which field will you harvest? (1";
    if (p->getNumChains() > 1)
    {
        cout << ", 2";
    }
    if (p->getNumChains() > 2)
    {
        cout << ", 3";
    }
    cout << ")" << endl;
    p->printFields(cout, false);
    int j;
    cin >> j;
    int coins = (*p)[j - 1].sell(); // Sell the chain
    *p += coins;
    createNewChainAt(j - 1, p, c); // Add the new chain to the player
    return;
}

void takeCardFromTradeArea(Player *p, TradeArea *ta)
{
    if (ta->isEmpty())
    {
        return;
    }

    // If TradeArea is not empty
    // Add bean cards from the TradeArea to chains or discard them.
    string selectedChain = "";
    do
    {
        clearScreen();
        cout << *p << endl;
        cout << "Trade Area: " << *ta << endl;
        cout << "What card would you like to take from the Trade Area? (\"none\" to skip)" << endl;
        cout << "Select: ";
        cin >> selectedChain;

        if (selectedChain != "none")
        {
            try
            {
                auto chain = ta->trade(selectedChain);
                if (chain)
                {
                    addCardToPlayerChain(p, chain);
                }
                else
                {
                    std::cout << "Trade failed: no card found for the selected chain." << std::endl;
                }
            }
            catch (const std::exception &e)
            {
                std::cout << "Error: " << e.what() << std::endl; // Handle trade failure
            }
        }
    } while (selectedChain != "none" && !ta->isEmpty()); // While the player doesnt want to skip and tradeArea isnt empty
}

int main(int argc, char const *argv[])
{

    // set up uninitilized pointers
    CardFactory *cardFactory = new CardFactory();
    Player *player1 = nullptr;
    Player *player2 = nullptr;
    vector<Player *> playerArray;
    Deck *pDeck = nullptr;
    Table *pTable = nullptr;
    DiscardPile *pDiscardPile = new DiscardPile();
    TradeArea *pTradeArea = new TradeArea();

    string existingGame;
    cout << "Do you have a saved game? y/n" << endl;
    cin >> existingGame;

    if (existingGame[0] == 'y')
    {
        // load from file.....
        cout << "NOT IMPLEMENTED";
        return 0;
    }
    else
    {
        // Setup
        string player1Name;
        cout << "Enter player 1 name: ";
        cin >> player1Name;

        string player2Name;
        cout << "Enter player 2 name: ";
        cin >> player2Name;

        player1 = new Player(player1Name);
        player2 = new Player(player2Name);
        playerArray.push_back(player1);
        playerArray.push_back(player2);

        // need to keep this deck in memory
        static Deck deck = cardFactory->getDeck();

        pDeck = &deck;

        // Draw 5 cards each
        for (int i = 0; i < 4; ++i)
        {
            // Make sure creating a hand is part of player
            player1->hand += pDeck->draw();
            player2->hand += pDeck->draw();
        }
        pTable = new Table(playerArray, pDeck, pTradeArea, pDiscardPile);
    }

    bool pause = false;

    // While there are still cards on the Deck
    while (!pDeck->isEmpty())
    {

        //  if pause save game to file and exit
        if (pause)
        {
            // implement save to file
            // Never go around to this
            return 0;
        }

        // For each Player
        for (Player *player : playerArray)
        {
            clearScreen();
            cout << "**********************************" << endl;
            cout << "*        " << player->getName() << "'s Turn" << endl;
            cout << "**********************************" << endl;

            // Display Table
            cout << *pTable << endl;
            // Player draws top card from Deck
            player->hand += pDeck->draw();

            // Display player info
            cout << *player;

            // If these conditions are met we will offer the player a chance to buy a 3rd field
            if (player->getNumCoins() >= 3 && player->getMaxNumChains() == 2)
            {
                std::string freeRealEstate = "";
                cout << "Would you like to purchase a 3rd field for 3 coins? (y/n)" << endl;
                cin >> freeRealEstate;
                if (freeRealEstate == "y")
                    player->buyThirdChain();
                clearScreen();
                cout << *player;
            }

            takeCardFromTradeArea(player, pTradeArea);

            int numCards = pTradeArea->numCards();
            for (int i = 0; i < numCards; ++i)
            {
                *pDiscardPile += pTradeArea->pop();
            }
            // First card must be played
            if (!player->hand.empty())
            {
                cout << "SYSTEM: You must play the first card from your hand." << endl;
                // Play the topmost card from Hand.
                Card *card = player->hand.play();
                cout << "You played: " << card->getName() << endl;

                addCardToPlayerChain(player, card); // add to a chain

                letUserRead(2);

                cout << *player;

                if (!player->hand.empty())
                {
                    // if player decides to
                    std::string playSecondCard;
                    cout << "Your top card is: " << (player->hand.top()->getName()) << endl;
                    cout << "Would you like to play this card? (y/n)" << endl;
                    cin >> playSecondCard;
                    if (playSecondCard == "y")
                    {
                        addCardToPlayerChain(player, player->hand.play());
                        cout << *player;
                    }
                }
            }

            // If the player has card(s) in their hand
            if (!player->hand.empty())
            {
                // Show the player's full hand and player selects an arbitrary card
                cout << "Your hand: ";
                player->printHand(cout, true); // print entire hand

                // If player decides to
                cout << "Would you like to discard a card? (y/n)" << endl;
                string discardACard;
                cin >> discardACard;
                if (discardACard[0] == 'y')
                {

                    // Discard the arbitrary card from the player's hand and place it on the discard pile.
                    int cardToDiscard;
                    cout << "Which card will you discard? 1 to " << player->hand.size() << endl;
                    cin >> cardToDiscard;
                    *pDiscardPile += player->hand[cardToDiscard - 1]; // We need to POP from players hand
                    cout << "Your hand: ";
                    player->printHand(cout, true); // print entire hand
                    cout << endl;
                }
            }

            //    Draw three cards from the deck and place cards in the trade area
            cout << "SYSTEM: The following cards are drawn and added to Trade Area:" << endl;
            for (int i = 0; i < 3; i++)
            {
                Card *card = pDeck->draw();
                cout << card->getName() << endl;
                *pTradeArea += card;
            }
            cout << endl;

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
            cout << "SYSTEM: You drew 2 cards and ended your turn" << endl;
            letUserRead(2);
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
    letUserRead(5);
}