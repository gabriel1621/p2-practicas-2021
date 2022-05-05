#ifndef _Junk_h
#define _Junk_h

#include <iostream>

using namespace std;

class Junk{
    friend ostream& operator<<(ostream &os, );
    protected:
        type JunkType;
        int quantity;
    public:
        Junk();
        Junk(type JunkType,int quantity )
        JunkType getType() const;
        int getQuantity() const;
        char getTypeChar() const;
        int getValue() const;

        
}

#endif