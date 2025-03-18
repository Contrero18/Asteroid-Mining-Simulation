#pragma once
#include <iostream>
#include <cstring>

class piataResurse{
    std::string resursa;
    float pretMinim;
    float pretMaxim;
    float pret;
    float cantitate;
    static int numarResurse;
    float profitBrut;
public:
    piataResurse(const std::string resursa = "", const float pretMinim = 0, const float pretMaxim = 0, const float pret = 0,
    const float cantitate = 0, const float profitBrut = 0);
    ~piataResurse();
    std::string getResursa() const;
    void setResursa(const std::string resursa);
    float getPretMinim() const;
    void setPretMinim(const float pretMinim);
    float getPretMaxim() const;
    void setPretMaxim(const float pretMaxim);
    float getPret() const;
    void setPret(const float pret);
    int getNumarResurse() const;
    void setNumarResurse(const int numarResurse);
    float getCantitate() const;
    void setCantitate(const float cantitate);
    float getProfitBrut() const;
    void setProfitBrut(const float profitBrut);
};
