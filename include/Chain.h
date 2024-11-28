#ifndef CHAIN_H
#define CHAIN_H

#include <stddef.h>
#include <vector>
#include "Card.h"

class IllegalTypeException: public std::exception{
    virtual const char* what() const throw(){
        return "IllegalTypeException";
    }
};

class ChainBase{
protected:
    std::string d_beanType;
public:
    ChainBase(std::string _beanType) : d_beanType(_beanType) {};
    virtual ~ChainBase() = default;
    virtual int sell() = 0;
    std::string getBeanType() {
        return d_beanType;
    }
    
    virtual void print(std::ostream&) const = 0;
    
    friend std::ostream& operator<<(std::ostream& out, ChainBase& chain) {
        out << chain.getBeanType() << "\t";
        chain.print(out);
        return out;
    };
};

template <typename T>
class Chain : public ChainBase {   
private:
    std::vector<T*> beans; //holds pointers to cards of type T
public:
    Chain(std::istream& is, const CardFactory* factory);    // Constructor - to get from file
    Chain<T>& operator+=(Card* card);          // Add a card to the chain
    int sell() override;                       // Calculate coins earned from chain
    friend std::ostream& operator<<(std::ostream& out, const Chain<T>& chain);
    std::string getName();
};

#endif
