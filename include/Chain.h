#ifndef CHAIN_H
#define CHAIN_H

#include <stddef.h>
#include <vector>
#include "Card.h"
#include "ChainBase.h"

class IllegalTypeException: public std::exception{
    virtual const char* what() const throw(){
        return "IllegalTypeException";
    }
};

template <typename T>
class Chain : public ChainBase {   
private:
    std::vector<T*> cards; //holds pointers to cards in chain
public:
    Chain(std::istream& is, const CardFactory* factory);    // Constructor - to get from file
    Chain<T>& operator+=(Card* card);        
    int sell();
    void print(std::ostream &os) const;
    template <typename U>
    friend std::ostream &operator<<(std::ostream &out, const Chain<T> &chain);
    std::string getName();
    void addCard(Card* card);
    int numCards();
};

#endif
