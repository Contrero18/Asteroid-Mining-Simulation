#pragma once
#include <iostream>
#include <string>

class Racheta{
    static int counter;
    const std::string id;
    int capacitate;
    int consum;
    int combustibil;
    float pretCombustibil;
    float costTotalCombustibil;
    int drumuri;
    int pretMisiune; //
    int misiuni;
    static int numarRachete;
    float profitNet;
    float pretSortare;
    int scorEficienta;
public:
    Racheta(const int capacitate = 0, const int consum = 0, const int combustibil = 0, 
    const float pretCombustibil = 0, const int drumuri = 0, const int misiuni = 0, 
    const float costTotalCombustibil = 0, const float pretSortare = 0 , const float profitNet = 0, const int scorEficienta = 0);
    Racheta(const Racheta &);
    Racheta & operator = (const Racheta &);
    ~Racheta();
    std::string getId() const;
    int getCapacitate() const;
    void setCapacitate(const int capacitate);
    int getConsum() const;
    void setConsum(const int consum);
    int getCombustibil() const;
    void setCombustibil(const int combustibil);
    float getPretCombustibil() const;
    void setPretCombustibil(const float pretCombustibil);
    int getDrumuri() const;
    void setDrumuri(const int drumuri);
    int getMisiuni() const;
    void setMisiuni(const int misiuni);
    int getPretMisiune() const;
    void setPretMisiune(const int PretMisiune);
    int getNumarRachete() const;
    void setNumarRachete(const int numarRachete);
    float getPretSortare() const;
    void setPretSortare(const float pretSortare);
    float getProfitNet() const;
    void setProfitNet(const float profitNet);
    float getCostTotalCombustibil() const;
    void setCostTotalCombustibil(const float costTotalCombustibil);
    float getScorEficienta() const;
    void setScorEficienta(const float scorEficienta);
};