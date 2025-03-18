#include "logistica.h"

int main(int argc, char* argv[]){
    Racheta **rachete;
    piataResurse *piata;
    Asteroid *asteroizi;
    logistica::citireRachete(argv[1], rachete);
    logistica::citirePiata(argv[3], piata);
    logistica::citireAsteroid(argv[2], asteroizi);
    logistica::misiune(rachete, piata, asteroizi);
    logistica::profitTotal(rachete);
    logistica::profitPeResursa(piata);
    logistica::clasamentRachete(rachete);
    logistica::eliberareMemorie(rachete, piata, asteroizi);
    return 0;
}