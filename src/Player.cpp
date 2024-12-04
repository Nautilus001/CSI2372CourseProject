#include "Player.h"
#include "Hand.h"

Player::Player(const std::string name)
{
    this->name = name;
    this->coins = 0;
    this->maxChains = 2;
    chains.resize(maxChains);
}

std::string Player::getName() const
{
    return this->name;
}

int Player::getNumCoins() const
{
    return this->coins;
}

int Player::getMaxNumChains() const
{
    return this->maxChains;
}

int Player::getNumChains() const
{
    int chainCount = 0;

    for (const auto &chain : this->chains)
    {
        if (chain != nullptr && !chain->isEmpty())
        {
            ++chainCount;
        }
    }

    return chainCount;
}

Player &Player::operator+=(int coins)
{
    this->coins += coins;
    return *this;
}

ChainBase &Player::operator[](int i)
{
    std::cout << "Accesssing player chain by index" << i << std::endl;
    if (i > getNumChains())
    {
        throw std::out_of_range("Index out of range");
    }
    std::cout << "Returning" << std::endl;
    return *this->chains[i];
}

void Player::buyThirdChain()
{
    if (this->getMaxNumChains() != 3)
    {
        this->maxChains = 3;
    }
}

void Player::addChain(ChainBase *chain)
{
    this->chains[getNumChains()] = chain;
}

void Player::popFront()
{
    this->chains.erase(chains.begin());
}

std::ostream &Player::printHand(std::ostream &out, bool all) const
{
    if (all)
    {
        out << this->hand;
    }
    return out;
}

std::ostream &Player::printFields(std::ostream &out) const
{
    for (const auto &chain : this->chains)
    {
        if (chain != nullptr)
        {
            chain->print(out);
        }
    }
    return out;
}

std::ostream &operator<<(std::ostream &out, const Player &player)
{
    out << "Player: " << player.getName() << "\n";
    out << "\tHand: " << player.hand << "\n";
    out << "\tCoins: " << player.getNumCoins() << "\n";
    out << "\tFields: " << player.getNumChains() << "/" << player.getMaxNumChains() << "\n";
    player.printFields(out);
    return out;
}
