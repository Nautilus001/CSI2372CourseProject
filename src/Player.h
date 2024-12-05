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
    Player(const std::string name = "");

    Hand hand;

    std::string getName() const;
    int getNumCoins() const;
    int getMaxNumChains() const;
    int getNumChains() const;

    Player& operator+=(int coins);
    ChainBase& operator[](int index);

    void buyThirdChain();
    void addChain(int i, ChainBase *chain);

    void popFront();

    std::ostream& printHand(std::ostream& out, bool all) const;
    std::ostream &printFields(std::ostream &out, bool tabbed) const;
    friend std::ostream &operator<<(std::ostream &out, const Player &player);
};

#endif
