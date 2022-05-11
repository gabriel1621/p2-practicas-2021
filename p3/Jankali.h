#ifndef _Jankali_h
#define _Jankali_h

#include <vector>

#include <iostream>

using namespace std;

class Jankali{
    friend ostream& operator<<(ostream &os, const Jankali &jankali );
    protected:
        string name;
        int power;
    public:
        Jankali( string name);
        string getName() const;
        int getPower() const;
        void hunt(vector <Betonski> betonskis);
        bool setTrap(Coordinate &coord const);
        void spoil();
        void spoil(type JunkType);
        void spoil(int pos);
        
        
}

#endif