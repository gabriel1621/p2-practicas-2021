#ifndef _Junk_h
#define _Junk_h
#include "Util.h"
#include <iostream>

using namespace std;

class Junk{
    friend ostream& operator<<(ostream &os, const Junk &junk);
    protected:
        JunkType type;
        int quantity;
    public:
        Junk();
        Junk(JunkType type ,int quantity );
        JunkType getType() const;
        int getQuantity() const;
        char getTypeChar() const;
        int getValue() const;

        
};

#endif