#ifndef CHAIN_H
#define CHAIN_H

#include <stddef.h>
#include <vector>
#include "Card.h"
#include "ChainBase.h"

class IllegalTypeException : public std::exception
{
    virtual const char *what() const throw()
    {
        return "IllegalTypeException";
    }
};

template <typename T>
class Chain : public ChainBase
{
private:
    std::vector<Card *> cards;
    const std::type_info *expectedType = nullptr;

public:
    Chain() = default;

    int sell() override
    {
        std::cout << "Selling chain of type " << cards.front()->getName() << std::endl;
        if (this->cards.empty())
            return 0;
        int numCards = this->cards.size();
        int amount = this->cards.front()->getCardsPerCoin(numCards);
        cards.clear();
        return amount;
    }

    bool isEmpty() const override
    {
        return cards.empty();
    }

    void print(std::ostream &out) const override
    {
        if (!isEmpty())
        {
            out << cards[0]->getName() << ": "; // Print the name of the chain
            for (const Card *card : cards)
            {
                card->print(out); // Call print() of the card to print its specific representation
                out << " ";
            }
        }
        else
        {
            out << "Empty chain"; // Handle empty chains
        }
    }

    Chain<T> &operator+=(Card *card)
    {
        if (cards.empty())
        {
            expectedType = &typeid(*card);
        }
        else
        {
            if (*expectedType != typeid(*card))
            {
                throw IllegalTypeException();
            }
        }
        cards.push_back(card);
        return *this;
    }

    std::string getName() const override
    {
        return cards.empty() ? "" : cards.front()->getName();
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Chain<T> &chain)
{
    if (!chain.isEmpty())
    {
        out << chain.getName() << ": ";
        for (Card *card : chain.cards)
        {
            out << *card << " ";
        }
    }
    return out;
}

#endif
