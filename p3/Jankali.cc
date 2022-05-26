#include "Jankali.h"

Jankali::Jankali(string name){
    
    if (name.length()<1){
        throw EXCEPTION_NAME;
    }
    else{
        this->name=name;
        power=300;
    }

}
string Jankali::getName() const{
    return name;
}
int Jankali::getPower() const{
    return power;
}
void Jankali::hunt(vector<Betonski *>betonskis){
    
    for (unsigned int i=0;i<traps.size();i++){
        *(betonskis).getPosition();
        if(*(betonskis->getPosition()==traps[i])&&(betonskis->captured==false)){
            *(betonskis)captured=true;
            subdued.push_back(*Betonski);

        }

    }
    

}
bool Jankali::setTrap(const Coordinate &coord){
    unsigned int contador=0;
    bool vacio=false;
    do{
        if( (traps[contador].getRow() != coord.getRow()) && (traps[contador].getColumn() != coord.getColumn()) ){
            vacio=true;
        }

    }while((vacio==true)||contador==traps.size());
    int coste=(coord.getRow()+2)*(coord.getColumn()+2);
    if ((vacio==true)&&(power>coste)){
        traps.push_back(coord);
        
        power=power-coste;
        return true;
    }
    else{
        return false;
    }
}
void Jankali::spoil(){
    int suma;
    bool rebelado;
    for(unsigned int i=subdued.size();i>=0;--i){
        rebelado=true;
        try{
            (suma=subdued[i]->spoliation());
        }
        catch (){
            rebelado=false;
            subdued.erase(subdued.begin()+i);
        }
        if(rebelado==true){
            this->power=(this->power)+suma;
        }
    }

}
void Jankali::spoil(JunkType type){
    int suma;
    bool rebelado=true;
    
        
        try{
            (suma=subdued[type]->spoliation());
        }
        catch(){
            rebelado=false;
            subdued.erase(subdued.begin()+type);
        }
        if(rebelado==true){
            this->power=(this->power)+suma;
        }
    

}
void Jankali::spoil(int pos){

}
ostream& operator<<(ostream &os,const Jankali &jankali){
    os<<"Jankali "<<'"'<<jankali.getName()<<'"'<<" "<<jankali.getPower()<<endl;
    for (unsigned int i=0;i<jankali.subdued.size();i++){
        os<<*(jankali.subdued[i])<<endl;
    }
    os <<"Traps ";
    for (unsigned int i=0;i<jankali.traps.size();i++){
        os<<(jankali.traps[i]);
    }
    return os;
}