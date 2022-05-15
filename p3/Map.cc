/*#include "Map.h"
#include "Junk.h"
#include "Util.h"
#include <vector>

Map::Map(int rows, int columns){

    if ((rows<=5)||(columns<=5)){
        throw EXCEPTION_SIZE;
    }
    else{
        rows=rows;
        columns=columns;
    }
    vector<vector<Junk>> junks;
    for (int i=0;i<rows;i++){
        Junk nuevoRecurso;
        JunkType recurso= recurso.Junk();

        for (int j=0;j<columns;j++){

            Junk.push_back(nuevoRecurso);
        }

        junks.push_back(Junk);
    }


}
bool Map::isInside(const Coordinate &coord) const{
    bool cordenadaOK = false;
    if (((row.coord>0)&&(row.coord<=rows)) || ((column.coord>0)&&(column.coord<=columns))){
        filaok=true;
    }

    return cordenadaOK;
    
}
void putJunk(const Junk &junk,const Coordinate &coord){
    if (isInside){

    }
    else{
        throw EXCEPTION_OUTSIDE;
    }
}*/