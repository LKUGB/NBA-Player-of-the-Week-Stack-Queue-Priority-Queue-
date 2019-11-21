//
// Created by MSI on 2019/11/21.
//

#include "Data.h"

using namespace std;

//implementing overloaded operator <<
ostream& operator<<(ostream &os, Data &dt){
    os << dt.activeSeason << "," << dt.playerName << "," << dt.team << "," << dt.seasonInLeague;
    return os;
}

//implementing comparison operator for comparing the active season member
bool operator< (const Data& dt, const Data& dt1){
    if(dt.seasonInLeague < dt1.seasonInLeague){
        return true; //the current player is less experienced than the one that we are comparing him to
    }
    else{
        return false;
    }
}

