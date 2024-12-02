#include "TradeArea.h"

TradeArea::TradeArea()
{
    std::list<Card *> cards;
}

bool TradeArea::isEmpty()
{
    return this->cards.empty();
}

TradeArea &TradeArea::operator+=(Card *card)
{
    cards.push_back(card);
    return *this;
}

bool TradeArea::legal(Card *card) const
{
    if (card == nullptr)
    {
        return false;
    }
    
    for (const auto &elem : this->cards)
    {
        if (elem->getName() == card->getName())
        {
            return true;
        }
    }
    return false;
}

Card *TradeArea::trade(const std::string &beanName)
{
    for (auto it = cards.begin(); it != cards.end(); ++it)
    {
        if ((*it)->getName() == beanName)
        {
            Card *card = *it;
            cards.erase(it);
            return card;
        }
    }
    throw std::runtime_error("No matching card found for the given bean name");
}

int TradeArea::numCards() const
{
    return this->cards.size();
}

std::vector<Card *> TradeArea::getCards() const
{
    std::vector<Card *> cardVector;
    for (auto &card : this->cards)
    {
        cardVector.push_back(card);
    }
    return cardVector;
}

std::ostream &operator<<(std::ostream &out, const TradeArea &tradeArea)
{
    for (auto &card : tradeArea.getCards())
    {
        card->print(out);
    }
    return out;
}
