#include "resursa.h"

Resursa:: Resursa(const std::string denumire, const int cantitateTotala,
const int randament, const float cantitatePosibila) :
denumire(denumire), cantitateTotala(cantitateTotala), randament(randament),
cantitatePosibila(cantitatePosibila){}
    
Resursa:: ~Resursa(){}
    
std::string Resursa:: getDenumire() const{
    return denumire;
}
    
void Resursa:: setDenumire(const std::string denumire){
    this->denumire=denumire;
}
    
int Resursa:: getCantitateTotala() const{
    return cantitateTotala;
}
    
void Resursa:: setCantitateTotala(const int cantitateTotala){
    this->cantitateTotala=cantitateTotala;
}
    
int Resursa:: getRandament() const{
    return randament;
}
    
void Resursa:: setRandament(const int randament){
    this->randament=randament;
}

float Resursa:: getCantitatePosibila() const{
    return cantitatePosibila;
}
    
void Resursa:: setCantitatePosibila(float cantitatePosibila){
    this->cantitatePosibila=cantitatePosibila;
}
