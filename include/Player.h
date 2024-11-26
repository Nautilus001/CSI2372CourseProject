#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <Vector>
#include "Hand.h"
#include "Chain.h"

class Player {
private:
    std::string name;
    int coins;
    std::vector<Chain<Card*>> chains; // Using a vector access to .size
public:
    Hand hand;
    Player(const std::string& name = "");
    std::string getName() const;
    int getNumCoins() const;
    Player& operator+=(int coins);
    int getMaxNumChains() const;
    int getNumChains() const;
    Chain<Card*>& operator[](int index);
    void buyThirdChain();
    void printHand(std::ostream& out, bool all) const;
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
};

#endif
