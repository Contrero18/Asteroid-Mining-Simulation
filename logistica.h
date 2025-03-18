#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
#include "racheta.h"
#include "asteroid.h"
#include "resursa.h"
#include "piataResurse.h"

namespace logistica{
    void citireRachete(char * numeFisier,Racheta **& rachete);
    void citirePiata(char * numeFisier, piataResurse *& piata);
    void citireAsteroid(char * numeFisier, Asteroid *&asteroizi);
    void misiune(Racheta **& rachete, piataResurse *& piata, Asteroid *&asteroizi);
    void profitTotal(Racheta **& rachete);
    void profitPeResursa(piataResurse *& piata);
    void clasamentRachete(Racheta **& rachete);
    void eliberareMemorie(Racheta **& rachete, piataResurse *& piata, Asteroid *&asteroizi);
}