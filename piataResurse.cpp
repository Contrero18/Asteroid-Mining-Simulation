#include "piataResurse.h"

int piataResurse:: numarResurse = 0;

piataResurse:: piataResurse(const std::string resursa, const float pretMinim, const float pretMaxim, const float pret, 
const float cantitate, const float profitBrut) : resursa(resursa), pretMinim(pretMinim), pretMaxim(pretMaxim), pret(pret),
cantitate(cantitate), profitBrut(profitBrut) {}

piataResurse:: ~piataResurse(){}

std::string piataResurse:: getResursa() const{
    return resursa;
}

void piataResurse:: setResursa(const std::string resursa){
    this->resursa=resursa;
}

float  piataResurse:: getPretMinim() const{
    return pretMinim;
}

void piataResurse:: setPretMinim(const float pretMinim){
    this->pretMinim=pretMinim;
}

float piataResurse:: getPretMaxim() const{
    return pretMaxim;
}

void piataResurse:: setPretMaxim(const float pretMaxim){
    this->pretMaxim=pretMaxim;
}

float piataResurse:: getPret() const{
    return pret;
}

void piataResurse:: setPret(const float pret){
    this->pret=pret;
}

int piataResurse:: getNumarResurse() const{
    return numarResurse;
}

void piataResurse:: setNumarResurse(const int numarResurse){
    this->numarResurse=numarResurse;
}

float piataResurse:: getCantitate() const{
    return cantitate;
}

void piataResurse:: setCantitate(const float cantitate){
    this->cantitate=cantitate;
}

float piataResurse:: getProfitBrut() const{
    return profitBrut;
}

void piataResurse:: setProfitBrut(const float profitBrut){
    this->profitBrut=profitBrut;
}