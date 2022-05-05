#ifndef _Betonski_h
#define _Betonski_h

#include <iostream>

using namespace std;

class Betonski{
    friend ostream& operator<<(ostream &os, );
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
        int calculateValue(type JunkType) const;
        int spoliation();
        int spoliation(type JunkType);
        int extract(Map &map);
        bool move(Map &map const);
        


        
}

#endif