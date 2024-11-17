#include "Player.h"

//TODO: INCLUDE HAND

Player::Player(const std::string& name) {
    // init the player with the given name
}

std::string Player::getName() const {
    // Return the player
    return "";
}

int Player::getNumCoins() const {
    // Return the number of coins the player has
    return 0; // Placeholder return value
}

Player& Player::operator+=(int coins) {
    // Add coins to the player's total
    return *this;
}

int Player::getMaxNumChains() const {
    // Return the max number of chains the player can have
    return 0; 
}

int Player::getNumChains() const {
    // Return the current number of chains the player has
    return 0;
}

Chain<Card>& Player::operator[](int index) {
    // Return the chain at the given index
    static Chain<Card> dummy;
    return dummy;
}

void Player::buyThirdChain() {
    // let the player to buy a third chain if they have enough coins
}

void Player::printHand(std::ostream& out, bool all) const {
    // Print either the top card or the entire hand (use all flag)
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
    // Print the player's details
    return out;
}
