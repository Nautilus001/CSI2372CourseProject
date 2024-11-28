#include "../include/Player.h"
#include "../include/Hand.h"
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

Chain<Card*>& Player::operator[](int index) {
    return *this->chains[index];
}

void Player::buyThirdChain() {
    if(this->getMaxNumChains() != 3){
        this->maxChains = 3;
    }
}

void Player::printHand(std::ostream& out, bool all) const {
    if(all){
        out << this->hand;
    }
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << "Player: " << player.name << "\n";
    out << "Coins: " << player.coins << "\n";
    out << "Chains: " << player.getNumChains() << "/" << player.getMaxNumChains() << "\n";
    
    out << "Hand: " << player.hand << "\n";

    out << "Chains: \n";
    for (const auto& chain : player.chains) {
        out << *chain << "\n";
    }

    return out;
}
