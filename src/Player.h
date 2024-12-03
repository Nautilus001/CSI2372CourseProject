#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <Vector>
#include <optional>
#include "Hand.h"
#include "Chain.h"
#include "ChainBase.h"

class Player {
private:
    std::string name;
    int coins;
    int maxChains;
    std::vector<ChainBase*> chains;
public:
    Hand hand;
    Player(const std::string name = "");
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
