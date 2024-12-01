#include "Hand.h"

Hand &Hand::operator+=(Card *card)
{
    cards.push_back(card);
    return *this;
}

Card *Hand::play()
{
    if (!cards.empty())
    {
        Card *front = cards.front();
        cards.erase(cards.begin());
        return front;
    }
    return nullptr;
}

Card *Hand::top() const
{
    if (!cards.empty())
    {
        Card *front = cards.front();
        return front;
    }
    return nullptr;
}

Card *Hand::operator[](int index)
{
    if (index < 0 || index >= cards.size())
    {
        throw std::out_of_range("Index out of range");
    }
    Card *card = cards[index];
    cards.erase(cards.begin() + index);
    return card;
}

std::ostream &operator<<(std::ostream &out, const Hand &hand)
{
    for (const auto &card : hand.cards)
    {
        out << "(" << *card << ")" << card->getName() << ", "; // Prints the name of the card
    }
    out << std::endl;
    return out;
}

bool Hand::empty()
{
    return this->cards.empty();
}

int Hand::size()
{
    return this->cards.size();
}
