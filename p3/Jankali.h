#ifndef _Jankali_h
#define _Jankali_h
#include "Betonski.h"
#include <vector>
#include "Coordinate.h"
#include <iostream>

using namespace std;

class Jankali{
    friend ostream& operator<<(ostream &os, const Jankali &jankali );
    protected:
        string name;
        int power;
        vector <Coordinate> traps;
        vector <Betonski> subdued;
    public:
        Jankali( string name);
        string getName() const;
        int getPower() const;
        void hunt(vector <Betonski *> betonskis);
        bool setTrap(const Coordinate &coord);
        void spoil();
        void spoil(JunkType type);
        void spoil(int pos);
        
        
};

#endif