//DNI 48775081Q, Gabriel Pardo
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
    
    for (unsigned int j=0;j<betonskis.size();j++){
        for (unsigned int i=0;i<traps.size();i++){

            Coordinate betoCord=betonskis[j]->getPosition();

            if (traps[i].compare(betoCord)){

                if(betonskis[j]->isCaptured()==false){

                    betonskis[j]->capture();
                    subdued.push_back(betonskis[j]);

                }

            }
            

        }
    }
    

}
bool Jankali::setTrap(const Coordinate &coord){
    
    bool vacio=false;

    for (unsigned int i=0; i<traps.size();i++){
        if (traps[i].compare(coord)==true ){
            vacio=true;
        }

    }
    

    int coste=(coord.getRow()+2)*(coord.getColumn()+2);

    if ((vacio==false)&&(power>=coste)){
        traps.push_back(coord);
        
        power=power-coste;
        return true;
    }
    else{
        return false;
    }
}
void Jankali::spoil(){
    int suma=0;
    
    for(unsigned int i=0;i<subdued.size();i++){
        
        try{
            (suma=subdued[i]->spoliation());
            power=(power)+suma;
        }
        catch (...){
            
            subdued.erase(subdued.begin()+i);
            i--;
        }
       
    }

}
void Jankali::spoil(JunkType type){
    int suma=0;
     for(unsigned int i=0;i<subdued.size();i++){
        
        try{
            suma=subdued[i]->spoliation(type);
            power=(power)+suma;
        }
        catch (...){
            
            subdued.erase(subdued.begin()+i);
            i--;
        }
       
    }
    

}
void Jankali::spoil(int pos){
    int suma=0;
    int l=subdued.size();
    for (int i=0; i<l ;i++){
        if (i==pos){
            try{
                suma=subdued[i]->spoliation();
                power=(power)+suma;
            }
            catch(...){
            
             subdued.erase(subdued.begin()+i);
             i--;
            }
            
        }
    }
    
    
   

}
ostream& operator<<(ostream &os,const Jankali &jankali){
    os<<"Jankali "<<'"'<<jankali.name<<'"'<<" "<<jankali.power<<endl;
    for (unsigned int i=0;i<jankali.subdued.size();i++){
        os<<*(jankali.subdued[i]);
    }
    os <<"Traps "<<endl;
    for (unsigned int i=0;i<jankali.traps.size();i++){
        os<<(jankali.traps[i]);
    }
    
    return os;
}