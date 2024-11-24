#include "../include/Chain.h"

template <typename T>
Chain<T>::Chain() {
    // Initialize any neccesary members here
}

template <typename T>
Chain<T>& Chain<T>::operator+=(T card) {
    // Add a card to the chain
    return *this;
}

template <typename T>
int Chain<T>::sell() const {
    // Calculate coins earned from the chain
    return 0;
}

// need some way to know what type of cards are stored in this chain
template <typename T>
std::string Chain<T>::getName()
{
    return std::string();
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& chain) {
    // Output details of the chain to the stream
    return out;
}

