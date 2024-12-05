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
    if (i > getNumChains())
    {
        throw std::out_of_range("Index out of range");
    }
    return *this->chains[i];
}

void Player::buyThirdChain()
{
    if (this->getMaxNumChains() != 3)
    {
        this->maxChains = 3;
        this->coins -= 3;
    }
    chains.resize(getMaxNumChains());
}

void Player::addChain(int i, ChainBase *chain)
{
    this->chains[i] = chain;
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

std::ostream &Player::printFields(std::ostream &out, bool tabbed = false) const
{
    for (const auto &chain : this->chains)
    {
        if (chain != nullptr)
        {
            if(tabbed) out << "\t";
            chain->print(out);
            out << std::endl;
        } else {
            out << "EMPTY" << std::endl;
        }
    }
    return out;
}

std::ostream &operator<<(std::ostream &out, const Player &player)
{
    out << "======================" << std::endl;
    out << "| Player: " << player.getName() << std::endl;
    out << "======================" << std::endl;
    out << "|Hand: " << player.hand << std::endl;
    out << "|Coins: " << player.getNumCoins() << std::endl;
    out << "|Fields: " << player.getNumChains() << "/" << player.getMaxNumChains() << std::endl;
    out << "|Fields Details:" << std::endl;
    player.printFields(out, true);
    out << "|-------------------------------------------------" << std::endl;
    return out;
}
