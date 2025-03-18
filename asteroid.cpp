#include "asteroid.h"

int Asteroid:: counter = 1;
int Asteroid:: numarAsteroizi = 0;

Asteroid:: Asteroid(const int distanta, const std::vector<Resursa> resurse, const float cantitateResurse) : id("A" + std::to_string(counter++)),
distanta(distanta){}

Asteroid:: ~Asteroid(){}

std::string Asteroid:: getId() const{
    return id;
}

int Asteroid:: getDistanta() const{
    return distanta;
}

void Asteroid:: setDistanta(const int distanta){
    this->distanta=distanta;
}

std::vector<Resursa>& Asteroid::getResurse(){
    return resurse;
}

void Asteroid::setResurse(const std::vector<Resursa>& newResurse) {
    resurse = newResurse;
}

void Asteroid::adaugaResursa(const Resursa& resursa) {
    resurse.push_back(resursa);
}

int Asteroid:: getNumarAsteroizi() const{
    return numarAsteroizi;
}

void Asteroid:: setNumarAsteroizi(const int numarAsteroizi){
    this->numarAsteroizi=numarAsteroizi;
}

float Asteroid:: getCantitateResurse() const{
    return cantitateResurse;
}

void Asteroid:: setCantitateResurse(const float cantitateResurse){
    this->cantitateResurse=cantitateResurse;
}