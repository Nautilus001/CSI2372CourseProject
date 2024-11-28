#include "../include/Player.h"
#include "../include/Hand.h"
#include "Player.h"
//TODO: INCLUDE HAND

Player::Player(const std::string& name) {
    this->name = name;
    this->coins = 0;
    this->chains;
    this->maxChains = 2;  
    this->hand;  
}

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
    return this->chains.size();
}

Chain<Card*>& Player::operator[](int i){
    if (i >= 0 && i < this->chains.size()) {
        return *this->chains[i];
    } else {
        throw std::out_of_range("Index out of range");
    }
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
