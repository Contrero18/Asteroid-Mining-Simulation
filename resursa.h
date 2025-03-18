#pragma once
#include <iostream>
#include <string>
class Resursa{
    std::string denumire;
    int cantitateTotala;
    int randament;
    float cantitatePosibila; //cantitatea calculata dupa ce se aplica randamentul de extragere
public:
    Resursa(const std::string denumire = "", const int cantitateTotala = 0,
    const int randament = 0, const float cantitatePosibila = 0);
    ~Resursa();
    std::string getDenumire() const;
    void setDenumire(const std::string denumire);
    int getCantitateTotala() const;
    void setCantitateTotala(const int cantitateTotala);
    int getRandament() const;
    void setRandament(const int randament);
    float getCantitatePosibila() const;
    void setCantitatePosibila(float cantitatePosibila);
};