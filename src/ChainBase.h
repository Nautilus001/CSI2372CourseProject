#ifndef CHAINBASE_H
#define CHAINBASE_H

#include <iostream>

class ChainBase {
public:
     virtual ~ChainBase() = default;

    // Common interface for all chains
    virtual int sell() = 0;
    virtual void print(std::ostream& os) const = 0;

    // Overload << operator to work with Chain_Base
    friend std::ostream& operator<<(std::ostream& os, const ChainBase& chain) {
        chain.print(os);
        return os;
    }
};

#endif
