#include "../include/CardFactory.h"
#include "../include/Chain.h"
#include "Chain.h"

template <typename T>
Chain<T>::Chain(std::istream& in, const CardFactory* factory) {
    std::string beanType;
    while (in >> beanType) { //TODO: this is wrong
        if (beanType == T().getName()) {
            cards.push_back(dynamic_cast<T*>(factory->createCard(beanType)));
        }
    }
}

template <typename T> 
int Chain<T>::sell() {
    if(cards.empty()) return 0;
    int numCards = cards.size();
    return cards.front()->getCardsPerCoin(numCards);
}

template <typename T>
Chain<T>& Chain<T>::operator+=(Card* card) {
    try {
        if(T().getName() == card->getName()){
            cards.push_back(card);
        } else {
            throw IllegalTypeException();
        }
    } catch (const IllegalTypeException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return *this;   
}

template <typename T>
void Chain<T>::print(std::ostream& os) const {
    os << T().getName() << " ";
    for (const auto& card : cards) {
        os << card.print();
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& chain) {
    out << T().getName();
    for (const T* card : chain.cards) {
        card->print(out);
    }

    return out;
}

template <typename T>
std::string getName() {
    return front().getName();
}

template <typename T>
void addCard(T* card) {
    cards.push_back(card);  // Calls push_back() on the vector to add the card
}

template <typename T>
int Chain<T>::numCards() {
    return cards.size();
}