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
    int maxChains;
    std::vector<Chain<Card*>*> chains; // Using a vector access to .size
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
    std::ostream& printHand(std::ostream& out, bool all) const;
    std::ostream &printFields(std::ostream &out) const;
    friend std::ostream &operator<<(std::ostream &out, const Player &player);
};

#endif
