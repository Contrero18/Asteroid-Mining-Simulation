#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "resursa.h"

class Asteroid{
    static int counter;
    const std::string id;
    int distanta;
    std::vector<Resursa> resurse;
    static int numarAsteroizi;
    float cantitateResurse;
public:
    Asteroid(const int distanta = 0, const std::vector<Resursa> resurse = {}, const float cantitateResurse = 0);
    ~Asteroid();
    std::string getId() const;
    int getDistanta() const;
    void setDistanta(const int distanta);
    std::vector<Resursa>& getResurse();
    void setResurse(const std::vector<Resursa>& newResurse);
    void adaugaResursa(const Resursa& resursa);
    int getNumarAsteroizi() const;
    void setNumarAsteroizi(const int numarAsteroizi);
    float getCantitateResurse() const;
    void setCantitateResurse(const float cantitateResurse);
};