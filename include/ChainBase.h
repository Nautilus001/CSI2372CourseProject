#ifndef CHAINBASE_H
#define CHAINBASE_H

#include <ostream>

class Chain_Base {
public:
    virtual ~Chain_Base() = default;
    virtual int sell() = 0;
    virtual void print(std::ostream& os) const = 0;
};

#endif