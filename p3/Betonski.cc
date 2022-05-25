#include "Betonski.h"
#include <string.h>
#include "Util.h"

Betonski::Betonski(string name){
    
    if (name.length()<1){
        throw EXCEPTION_NAME;
    }
    else{
        this->name=name;
        captured=false;
        anger=0;
        Coordinate position;
    }

}
Coordinate Betonski::getPosition() const{
    return position;
}
void Betonski::capture(){
    captured=true;
    
}
void Betonski::setPosition(const Coordinate &coord){

    position=coord;
}
int Betonski::calculateValue() const{
    int suma;
    for (i=0;i<bag.size();++i){
        suma=suma+bag[i].getValue();
    }
    return suma;
}
int Betonski::calculateValue(JunkType type) const{
    int suma;
    
    suma=suma+bag[type].getValue();
    
    return suma;

}
int Betonski::spoliation(){
    int spoli=calculateValue()+getAnger();
    if (isCaptured()==false){
        throw BETONSKI_NOT_CAPTURED;
    }
    else{
        if(spoli>5000){
            anger=0;
            captured=false;
            throw EXCEPTION_REBELION;

        }
        else{
            anger=calculateValue();
            for (i=bag.size();i>0;--i){
                bag[i].erase();
            }
        }
    }

}
int Betonski::spoliation(JunkType type){
    int spoli=calculateValue(type)+getAnger();
    if (isCaptured()==false){
        throw BETONSKI_NOT_CAPTURED;
    }
    else{
        if(spoli>5000){
            anger=0;
            captured=false;
            throw EXCEPTION_REBELION;N;

        }
        else{
            anger=calculateValue(type);
            bag[type].erase();
        }
    }

}
int Betonski::extract(Map &map){
    if(map.isInside(position)){
     Junk nuevorecu;
     nuevorecu=map.collectJunk(coord);

     
        if (nuevorecu!=WASTELAND){
         bag.push_back(nuevorecu);
         return nuevorecu.getValue()
        }
        else{
            return 0;
        }

    }
    
}
bool Betonski::move(const Map &map) const{
    if (map.isInside(position)==true){
        
        int num=Util::getRandomNumber(8);
        return true;

        switch(num){
            case 0:
                position=[]
        }
        

    }
    else{
        throw EXCEPTION_OUTSIDE;
    }

}
string Betonski::traduCapture() const{
    if (isCaptured()==false){
        return "Free";
    }
    else{
       return "Captured";
    }

}
ostream& operator<<(ostream &os,const Betonski &betonski){
    os<<"Betonski "<<'"'<<betonski.getName()<<'"'<<betonski.traduCapture()<<betonski.getAnger()<<betonski.getPosition()<<endl;
    if (betonski.calculateValue()<1){
        os<<"";
    }
    else{
        os<<"[GOLD:"<<betonski.calculateValue(GOLD)<<"] "
        <<"[STONE:"<<betonski.calculateValue(STONE)<<"] "
        <<"[FOOD:"<<betonski.calculateValue(FOOD)<<"] ";
    }
    return os;
}
