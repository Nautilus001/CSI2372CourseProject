#include "Player.h"
#include "Hand.h"

Player::Player(const std::string name)
    : name(name), 
      coins(0), 
      chains(3), 
      maxChains(2), 
      hand() {}

std::string Player::getName() const {
    return this->name;
}

int Player::getNumCoins() const {
    return this->coins;
}

Player& Player::operator+=(int coins) {
    this->coins += coins;
    return *this;
}

int Player::getMaxNumChains() const {
    return this->maxChains; 
}

int Player::getNumChains() const {
    int chainCount = 0;

    for (const auto& chain : this->chains) {
        if (chain != nullptr && !chain->empty()) {
            ++chainCount;
        }
    }

    return chainCount;
}

Chain<Card*>& Player::operator[](int i){
    std::cout << "operator called" << std::endl;
    if (i >= 0 && i < this->chains.size()) {
        std::cout << "returning chain: " << i << std::endl;
        if(chains[i] != nullptr){
            return *this->chains[i];
        } else {
            std::cout << "chain uninitialized" << std::endl;
        }
    }
    throw std::out_of_range("Index out of range");
}

void Player::buyThirdChain() {
    if(this->getMaxNumChains() != 3){
        this->maxChains = 3;
    }
}

std::ostream& Player::printHand(std::ostream& out, bool all) const {
    if(all){
        out << this->hand;
    }
    return out;
}

std::ostream& Player::printFields(std::ostream& out) const {
    for (auto& chain : this->chains) {
        out << chain;
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << "Player: " << player.getName() << "\n";
    out << "\tCoins: " << player.getNumCoins() << "\n";
    out << "\tFields: " << player.getNumChains() << "/" << player.getMaxNumChains() << "\n";
    player.printFields(out);
    return out;
}
