#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <Hand.h>
#include <vector>
#include "Chain.h"

class Player {
private:
    std::string name;
    Hand hand;
    int coins;
    std::vector<Chain> chains; // Using a vector access to .size
public:
    Player(const std::string& name);
    std::string getName() const;
    int getNumCoins() const;
    Player& operator+=(int coins);
    int getMaxNumChains() const;
    int getNumChains() const;
    Chain<Card>& operator[](int index);
    void buyThirdChain();
    void printHand(std::ostream& out, bool all) const;
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
};

#endif
