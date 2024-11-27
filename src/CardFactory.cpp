#include "../include/CardFactory.h"

CardFactory::CardFactory()
{
    // Initialize necessary members here
}

CardFactory &CardFactory::getFactory()
{
    // Return the instance of CardFactory
    static CardFactory instance;
    return instance;
}

Deck CardFactory::getDeck() const
{
    // Create and return a NEW Deck object
    // TODO: shuffle
    return Deck();
}
