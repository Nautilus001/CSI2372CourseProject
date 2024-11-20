#include "../include/Chain.h"

template <typename T>
Chain<T>::Chain() {
    // Initialize any neccesary members here
}

template <typename T>
Chain<T>& Chain<T>::operator+=(Card* card) {
    // Add a card to the chain
    return *this;
}

template <typename T>
int Chain<T>::sell() const {
    // Calculate coins earned from the chain
    return 0;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& chain) {
    // Output details of the chain to the stream
    return out;
}
