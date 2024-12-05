#include "TradeArea.h"
#include "DiscardPile.h"

bool TradeArea::isEmpty() const
{
    return this->cards.empty();
}

TradeArea &TradeArea::operator+=(Card *card)
{
    this->cards.push_back(card);
    return *this;
}

bool TradeArea::legal(Card *incomingCard) const
{
    if (incomingCard == nullptr)
    {
        return false;
    }
    
    for (const auto &card : this->cards)
    {
        if (card->getName() == incomingCard->getName())
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

Card* TradeArea::pop() {
    Card* card = this->cards.front();
    this->cards.pop_front();
    return card;
}

std::ostream &operator<<(std::ostream &out, const TradeArea &tradeArea)
{
    if(tradeArea.isEmpty()) {
        out << "Empty";
    } else {
        for (auto &card : tradeArea.cards)
        {
            out << card->getName() << " ";
        }
    }
    out << std::endl;
    return out;
}
