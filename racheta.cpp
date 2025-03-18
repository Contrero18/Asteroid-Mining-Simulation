#include "racheta.h"

int Racheta:: counter = 1;
int Racheta:: numarRachete = 0;

Racheta:: Racheta(const int capacitate, const int consum, const int combustibil, 
const float pretCombustibil, const int drumuri, const int misiuni, const float costTotalCombustibil,
const float pretSortare, const float profitNet, const int scorEficienta) : id("R" + std::to_string(counter++)),
capacitate(capacitate), consum(consum), combustibil(combustibil), pretCombustibil(pretCombustibil),
drumuri(drumuri), misiuni(misiuni){}

Racheta:: Racheta(const Racheta & other){}

Racheta & Racheta:: operator = (const Racheta &){
    return *this;
}

Racheta:: ~Racheta(){}

std::string Racheta:: getId() const{
    return id;
}

int Racheta:: getCapacitate() const{
    return capacitate;
}

void Racheta:: setCapacitate(const int capacitate){
    this->capacitate=capacitate;
}

int Racheta:: getConsum() const{
    return consum;
}

void Racheta:: setConsum(const int consum){
    this->consum=consum;
}

int Racheta:: getCombustibil() const{
    return combustibil;
}

void Racheta:: setCombustibil(const int combustibil){
    this->combustibil=combustibil;
}

float Racheta:: getPretCombustibil() const{
    return pretCombustibil;
}

void Racheta:: setPretCombustibil(const float pretCombustibil){
    this->pretCombustibil=pretCombustibil;
}

int Racheta:: getDrumuri() const{
    return drumuri;
}

void Racheta:: setDrumuri(const int drumuri){
    this->drumuri=drumuri;
}

int Racheta:: getMisiuni() const{
    return misiuni;
}

void Racheta:: setMisiuni(const int misiuni){
    this->misiuni=misiuni;
}

int Racheta:: getPretMisiune() const{
    return pretMisiune;
}

void Racheta:: setPretMisiune(const int PretMisiune){
    this->pretMisiune=pretMisiune;
}

int Racheta:: getNumarRachete() const{
    return numarRachete;
}

void Racheta:: setNumarRachete(const int numarRachete){
    this->numarRachete=numarRachete;
}

float Racheta:: getPretSortare() const{
    return pretSortare;
}

void Racheta:: setPretSortare(const float pretSortare){
    this->pretSortare=pretSortare;
}

float Racheta:: getProfitNet() const{
    return profitNet;
}

void Racheta:: setProfitNet(const float profitNet){
    this->profitNet=profitNet;
}

float Racheta:: getCostTotalCombustibil() const{
    return costTotalCombustibil;
}

void Racheta:: setCostTotalCombustibil(const float costTotalCombustibil){
    this->costTotalCombustibil=costTotalCombustibil;
}

float Racheta::  getScorEficienta() const{
    return scorEficienta;
}

void Racheta::  setScorEficienta(const float scorEficienta){
    this->scorEficienta=scorEficienta;
}