#ifndef CHAINBASE_H
#define CHAINBASE_H

#include <iostream>

class ChainBase {
public:
    virtual int sell() = 0;
    virtual bool isEmpty() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual ChainBase& operator+=(Card* card) = 0;

    friend std::ostream& operator<<(std::ostream& os, const ChainBase& chain) {
        chain.print(os);
        return os;
    }
};

#endif
