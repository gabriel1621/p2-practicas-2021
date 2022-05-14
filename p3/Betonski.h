/*#ifndef _Betonski_h
#define _Betonski_h
#include "Coordinate.h"
#include "Map.h"
#include <iostream>
#include "Util.h"

using namespace std;

class Betonski{
    friend ostream& operator<<(ostream &os,const Betonski &betonski);
    protected:
        string name;
        int anger;
        bool captured;
    public:
        Betonski(string name);
        string getName() const;
        int getAnger() const;
        bool isCaptured() const;
        Coordinate getPosition() const;
        void captured();
        void setPosition();
        int calculateValue(JunkType type) const;
        int spoliation();
        int spoliation(JunkType type);
        int extract(Map &map);
        bool move(Map &map) const;
        


        
};

#endif*/