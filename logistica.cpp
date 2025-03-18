#include "logistica.h"

void logistica:: citireRachete(char * numeFisier,Racheta **& rachete){
    std::ifstream fisier(numeFisier);
    if (!fisier.is_open()) {
        std::cout<<"Fisierul nu a putut fi deschis\n";
        exit(1);
    }
    std::string linie;
    int numarRachete = -1; //-1 ca este si antetul tabelui

    while (getline(fisier, linie)) {
        numarRachete++;
    }
    if(numarRachete<=0){ //am pus mai mic sau egal in cazul ca exista si varianta in care fisierul sa fie gol in totalitate 
        std::cout<<"NU EXISTA RACHETE\n";
        exit(0);
    }
    fisier.clear();
    fisier.seekg(0);
    getline(fisier,linie); //citesc antetul ala, poate nu il puneti in teste ca inebunesc
    rachete=new Racheta*[numarRachete];
    for(int i=0; i<numarRachete; i++){
        rachete[i]=new Racheta();
        std::string id;
        getline(fisier, id, ';'); //doar il citesc ca oricum il initializez frumos la inceput cand creez racheta
        //si nu de alta, da trebuie sa ajung la datele care ma intereseaza
        std::string temp;
        getline(fisier, temp, ';');
        rachete[i]->setCapacitate(stoi(temp));
        getline(fisier, temp, ';');
        rachete[i]->setConsum(stoi(temp));
        getline(fisier, temp, ';');
        rachete[i]->setCombustibil(stoi(temp));
        getline(fisier, temp, '\n');
        rachete[i]->setPretCombustibil(stof(temp));
    }
    rachete[0]->setNumarRachete(numarRachete);
    fisier.close();
}

void logistica:: citirePiata(char * numeFisier, piataResurse *& piata){
    std::ifstream fisier(numeFisier);
    if (!fisier.is_open()) {
        std::cout<<"Fisierul nu a putut fi deschis\n";
        exit(1);
    }
    std::string linie;
    int numarResurse= -1; //-1 ca este si antetul tabelui

    while (getline(fisier, linie)) {
        numarResurse++;
    }
    if(numarResurse<=0){ //am pus mai mic sau egal in cazul ca exista si varianta in care fisierul sa fie gol in totalitate 
        std::cout<<"NU EXISTA RESURSE\n";
        exit(0);
    }
    fisier.clear();
    fisier.seekg(0);
    getline(fisier,linie);
    piata= new piataResurse[numarResurse];
    piata[0].setNumarResurse(numarResurse);
    for(int i=0; i<numarResurse; i++){
        std::string temp;
        getline(fisier, temp, ';');
        piata[i].setResursa(temp);
        getline(fisier, temp, ';');
        piata[i].setPretMinim(stof(temp));
        getline(fisier, temp, '\n');
        piata[i].setPretMaxim(stof(temp));
        piata[i].setPret(stof(temp));
    }
    fisier.close();
}

void logistica:: citireAsteroid(char * numeFisier, Asteroid *&asteroizi){
    std::ifstream fisier(numeFisier);
    if (!fisier.is_open()) {
        std::cout<<"Fisierul nu a putut fi deschis\n";
        exit(1);
    }
    //caut sa vad cat asteroizi am
    std::string ultimulAsteroid;
    fisier.seekg(-1, std::ios::end);

    bool gasit = false;
    while (!gasit) {
        char c;
        fisier.seekg(-2, std::ios::cur); // Ma uit in oglinzi, ma asigur si dau cu spatele
        fisier.get(c);

        if (c == '\n') { //daca dau de enter inseam na ca urmatoarea e ultima linie deci imi citesc id-ul de la asteroid
            getline(fisier, ultimulAsteroid, ';');
            gasit = true;
        }

        if (fisier.tellg() <= 1) { //in cazul in care nu am avea asteroizi o sa afisez pe ecran ca de ce nu (este si conditie de iesire din while daca nu am asteroizi)
            fisier.seekg(0);
            getline(fisier, ultimulAsteroid);
            gasit = true;
            if(ultimulAsteroid == "ID Asteroid;Resursă;Cantitate totală (kg);Randament extracție (%);Distanță (km)" || ultimulAsteroid.empty()){
                std::cout<<"NU EXISTA ASTEROIZI\n";
                exit(0);
            }
        }
    }
    ultimulAsteroid.erase(0, 1); //sterg primul caracter ca sa pot sa scot numarul de asteroizi
    int numarAsteroizi=stoi(ultimulAsteroid); 
    asteroizi=new Asteroid[numarAsteroizi];
    asteroizi[0].setNumarAsteroizi(numarAsteroizi);
    std::string linie;
    fisier.clear();
    fisier.seekg(0);
    getline(fisier,linie);
    int i=0;
    while(i<numarAsteroizi){
        std::string id;
        std::streampos pozitie1 = fisier.tellg(); // salvez pozitia actuala ca s ama intorc mai tarziu la ea
        getline(fisier, id, ';');
        std::streampos pozitie2 = fisier.tellg();
        std::streampos diferenta = pozitie2 - pozitie1;
        if(id == asteroizi[i].getId()){
            std::string denumire;
            std::string temp;
            getline(fisier, denumire, ';');
            getline(fisier, temp, ';');
            int cantitate = stoi(temp);
            getline(fisier, temp, ';');
            int randament = stoi(temp);
            getline(fisier, temp, '\n');
            asteroizi[i].setDistanta(stoi(temp));
            float cantitatePosibila= ((float)randament/100)*cantitate;
            Resursa a(denumire, cantitate, randament, cantitatePosibila);
            asteroizi[i].adaugaResursa(a);
            asteroizi[i].setCantitateResurse(asteroizi[i].getCantitateResurse()+cantitatePosibila);
        }else{
            fisier.seekg(pozitie2 - diferenta); // iar aici ma intorc la pozitia aia
            i++;
        }
    }
    fisier.close();
}

std::string adaugaVirgule(double valoare) {
    std::ostringstream oss;
    oss << valoare;
    std::string numar = oss.str();
    size_t pozitiePunct = numar.find('.'); //caut pozitia
    std::string parteIntreaga = numar.substr(0, pozitiePunct);
    std::string parteFractionara = (pozitiePunct != std::string::npos) ? numar.substr(pozitiePunct) : "";
    int virgula = parteIntreaga.length() - 3; //adaug virgulele
    while (virgula > 0) {
        parteIntreaga.insert(virgula, ",");
        virgula -= 3;
    }

    return parteIntreaga + parteFractionara;
}


void logistica:: misiune(Racheta **& rachete, piataResurse *& piata, Asteroid *&asteroizi){

    std::ofstream fisier("misiuni.csv");
    if (!fisier.is_open()) {
        std::cout<<"Fisierul nu a putut fi deschis\n";
        exit(1);
    }
    fisier<<"ID Rachetă;ID Asteroid;Resursă;Cantitate extrasă (kg);Combustibil consumat (kg);Cost combustibil ($);Profit brut ($);Profit net ($)\n";
    for(int i=0; i<asteroizi[0].getNumarAsteroizi(); i++){
        for(int j=0; j<rachete[0]->getNumarRachete(); j++){
            float drumuri= (float)asteroizi[i].getCantitateResurse() / rachete[j]->getCapacitate();
            if((float)(int)drumuri == drumuri){
                rachete[j]->setDrumuri((int)drumuri);
            }else{
                rachete[j]->setDrumuri((int)drumuri + 1);
            }
            float pretSortare=rachete[j]->getDrumuri() * 2 * ((float)asteroizi[i].getDistanta() / 1000) * rachete[j]->getPretCombustibil();
            rachete[j]->setPretSortare(pretSortare);
        }

        //sortare
        for(int j=0; j<rachete[0]->getNumarRachete(); j++){
            for(int k=j; k<rachete[0]->getNumarRachete(); k++){
                if(rachete[j]->getPretSortare() > rachete[k]->getPretSortare()){
                    Racheta *temp;
                    temp=rachete[j];
                    rachete[j]=rachete[k];
                    rachete[k]=temp;
                }
            }
        }
        int ok = 0; 
        while(asteroizi[i].getCantitateResurse() > 0.0001f){ //misiunea 
            ok=0;
            int ok2 = 0;
            int j;
            do{ // caut cea mai ok racheta care poate ajunge la asteroid
                for(j=0; j<rachete[0]->getNumarRachete(); j++){
                    if((int)((float)rachete[j]->getCombustibil() / rachete[j]->getConsum() )* 1000 > 2 * asteroizi[i].getDistanta()){
                        ok = 1;
                        break;
                    }
                }
                if(ok == 0 && i == asteroizi[0].getNumarAsteroizi() - 1){
                    return;
                }else if(ok == 0){
                    ok2=1;
                    break;
                }
            }while(!ok);
            if(ok2 == 1){
                break;
            }
            fisier<<rachete[j]->getId()<<";"<<asteroizi[i].getId()<<";";
            float capacitateConsumata = 0;
            float profitBrut = 0;
            std::string numeResursa = "";
            float cantitateExtrasa = 0;
            for(auto& resursa : asteroizi[i].getResurse()){
                if((float)rachete[j]->getCapacitate() <= resursa.getCantitatePosibila() && capacitateConsumata == 0){ //daca adaug o singura resursa
                    asteroizi[i].setCantitateResurse(asteroizi[i].getCantitateResurse() - (float)rachete[j]->getCapacitate()); // scad capacitatea din totalu resurselor
                    resursa.setCantitatePosibila(resursa.getCantitatePosibila() - (float)rachete[j]->getCapacitate()); // actualizez cantitatea resursei
                    for(int k=0; k<piata[0].getNumarResurse(); k++){
                        if(resursa.getDenumire() == piata[k].getResursa()){ // caut resursa pe piata 
                            numeResursa = numeResursa + "&" + resursa.getDenumire(); //ca sa afisez mai tarziu
                            float cantitateNeprocesata = (float)rachete[j]->getCapacitate();
                            cantitateExtrasa = cantitateExtrasa + cantitateNeprocesata;
                            while(cantitateNeprocesata){
                                float n = piata[k].getCantitate(); // spatiul consumat din piata in n pentru prelucrare
                                if(10000 - std::fmod(n, 10000) > cantitateNeprocesata){ //daca am destul spatiu in piata pana la 10k
                                    piata[k].setCantitate(piata[k].getCantitate() + cantitateNeprocesata); //care e pana in 10k
                                    profitBrut = profitBrut + cantitateNeprocesata * piata[k].getPret();
                                    piata[k].setProfitBrut(piata[k].getProfitBrut() + cantitateNeprocesata * piata[k].getPret()); //profitul brut pe resursa
                                    cantitateNeprocesata = 0;
                                }else{
                                    n = std::fmod(piata[k].getCantitate(), 10000);
                                    n = 10000 - n;
                                    cantitateNeprocesata = cantitateNeprocesata - n;
                                    piata[k].setCantitate(piata[k].getCantitate() + n); // practic completez pana la 10k
                                    profitBrut = profitBrut + n * piata[k].getPret();
                                    piata[k].setProfitBrut(piata[k].getProfitBrut() + n * piata[k].getPret());
                                    if(0.9 * piata[k].getPret() > piata[k].getPretMinim()){
                                        piata[k].setPret(0.9 * piata[k].getPret());
                                    }else{
                                        piata[k].setPret((float)piata[k].getPretMinim());
                                    }
                                }
                            }
                        }
                    }
                    break; //pentru ca umplu racheta din prima resursa direct
                }else if((float)rachete[j]->getCapacitate() > resursa.getCantitatePosibila() && capacitateConsumata == 0){
                    if(resursa.getCantitatePosibila() == 0){ //daca este goala resursa, continui la urmatoarea
                        continue;
                    }
                    asteroizi[i].setCantitateResurse(asteroizi[i].getCantitateResurse() - resursa.getCantitatePosibila()); // scad capacitatea din totalu resurselor
                    //trebuie scazut din resursele totale si probabil si la cele din asteroid, la fel si mai jos
                    for(int k=0; k<piata[0].getNumarResurse(); k++){
                        if(resursa.getDenumire() == piata[k].getResursa()){
                            numeResursa = numeResursa + "&" + resursa.getDenumire();
                            float cantitateNeprocesata = resursa.getCantitatePosibila();
                            capacitateConsumata = capacitateConsumata + cantitateNeprocesata;
                            cantitateExtrasa = cantitateExtrasa + cantitateNeprocesata;
                            while(cantitateNeprocesata){
                                float n = piata[k].getCantitate(); // spatiul consumat din piata in n pentru prelucrare
                                if(10000 - std::fmod(n, 10000)> cantitateNeprocesata){ //daca am destul spatiu in piata pana la 10k
                                    piata[k].setCantitate(piata[k].getCantitate() + cantitateNeprocesata); //care e pana in 10k
                                    profitBrut = profitBrut + cantitateNeprocesata * piata[k].getPret();
                                    piata[k].setProfitBrut(piata[k].getProfitBrut() + cantitateNeprocesata * piata[k].getPret());
                                    cantitateNeprocesata = 0;
                                }else{
                                    n = std::fmod(piata[k].getCantitate(), 10000);
                                    n = 10000 - n;
                                    cantitateNeprocesata = cantitateNeprocesata - n;
                                    piata[k].setCantitate(piata[k].getCantitate() + n); // practic completez pana la 10k
                                    profitBrut = profitBrut + n * piata[k].getPret();
                                    piata[k].setProfitBrut(piata[k].getProfitBrut() + n * piata[k].getPret());
                                    if(0.9 * piata[k].getPret() > piata[k].getPretMinim()){
                                        piata[k].setPret(0.9 * piata[k].getPret());
                                    }else{
                                        piata[k].setPret((float)piata[k].getPretMinim());
                                    }
                                }
                            }
                        }
                    }
                    resursa.setCantitatePosibila(0); // actualizez cantitatea resursei
                }else if((rachete[j]->getCapacitate() - capacitateConsumata) <= resursa.getCantitatePosibila()){ //daca adaug o singura resursa
                    asteroizi[i].setCantitateResurse(asteroizi[i].getCantitateResurse() - (rachete[j]->getCapacitate() - capacitateConsumata)); // scad capacitatea din totalu resurselor
                    resursa.setCantitatePosibila(resursa.getCantitatePosibila() - (rachete[j]->getCapacitate() - capacitateConsumata)); // actualizez cantitatea resursei
                    for(int k=0; k<piata[0].getNumarResurse(); k++){
                        if(resursa.getDenumire() == piata[k].getResursa()){ // caut resursa pe piata
                            numeResursa = numeResursa + "&" + resursa.getDenumire();
                            float cantitateNeprocesata = ((float)rachete[j]->getCapacitate() - capacitateConsumata);
                            cantitateExtrasa = cantitateExtrasa + cantitateNeprocesata;
                            while(cantitateNeprocesata){
                                float n = piata[k].getCantitate(); // spatiul consumat din piata in n pentru prelucrare
                                if(10000 - std::fmod(n, 10000) > cantitateNeprocesata){ //daca am destul spatiu in piata pana la 10k
                                    piata[k].setCantitate(piata[k].getCantitate() + cantitateNeprocesata); //care e pana in 10k
                                    profitBrut = profitBrut + cantitateNeprocesata * piata[k].getPret();
                                    piata[k].setProfitBrut(piata[k].getProfitBrut() + cantitateNeprocesata * piata[k].getPret());
                                    cantitateNeprocesata = 0;
                                }else{
                                    n = std::fmod(piata[k].getCantitate(), 10000);
                                    n = 10000 - n;
                                    cantitateNeprocesata = cantitateNeprocesata - n;
                                    piata[k].setCantitate(piata[k].getCantitate() + n); // practic completez pana la 10k
                                    profitBrut = profitBrut + n * piata[k].getPret();
                                    piata[k].setProfitBrut(piata[k].getProfitBrut() + n * piata[k].getPret());
                                    if(0.9 * piata[k].getPret() > piata[k].getPretMinim()){
                                        piata[k].setPret(0.9 * piata[k].getPret());
                                    }else{
                                        piata[k].setPret((float)piata[k].getPretMinim());
                                    }
                                }
                            }
                        }
                    }
                    break; //pentru ca umplu racheta din prima resursa direct

                }else{
                    if(resursa.getCantitatePosibila() == 0){ //daca este goala resursa, continui la urmatoarea
                        continue;
                    }
                    asteroizi[i].setCantitateResurse(asteroizi[i].getCantitateResurse() - resursa.getCantitatePosibila()); // scad capacitatea din totalu resurselor

                    for(int k=0; k<piata[0].getNumarResurse(); k++){
                        if(resursa.getDenumire() == piata[k].getResursa()){
                            numeResursa = numeResursa + "&" + resursa.getDenumire();
                            float cantitateNeprocesata = resursa.getCantitatePosibila();
                            capacitateConsumata = capacitateConsumata + cantitateNeprocesata;
                            cantitateExtrasa = cantitateExtrasa + cantitateNeprocesata;
                            while(cantitateNeprocesata){
                                float n = piata[k].getCantitate(); // spatiul consumat din piata in n pentru prelucrare
                                if(10000 - std::fmod(n, 10000) > cantitateNeprocesata){ //daca am destul spatiu in piata pana la 10k
                                    piata[k].setCantitate(piata[k].getCantitate() + cantitateNeprocesata); //care e pana in 10k
                                    profitBrut = profitBrut + cantitateNeprocesata * piata[k].getPret();
                                    piata[k].setProfitBrut(piata[k].getProfitBrut() + cantitateNeprocesata * piata[k].getPret());
                                    cantitateNeprocesata = 0;
                                }else{
                                    n = std::fmod(piata[k].getCantitate(), 10000);
                                    n = 10000 - n;
                                    cantitateNeprocesata = cantitateNeprocesata - n;
                                    piata[k].setCantitate(piata[k].getCantitate() + n); // practic completez pana la 10k
                                    profitBrut = profitBrut + n * piata[k].getPret();
                                    piata[k].setProfitBrut(piata[k].getProfitBrut() + n * piata[k].getPret());
                                    if(0.9 * piata[k].getPret() > piata[k].getPretMinim()){
                                        piata[k].setPret(0.9 * piata[k].getPret());
                                    }else{
                                        piata[k].setPret((float)piata[k].getPretMinim());
                                    }
                                }
                            }
                        }
                    }
                    resursa.setCantitatePosibila(0); // actualizez cantitatea resursei

                }

            }
            
            rachete[j]->setMisiuni(rachete[j]->getMisiuni() + 1);
            //afisari
            fisier<<numeResursa.erase(0, 1)<<";";
            fisier<<cantitateExtrasa<<";";
            int combustibilConsumat = ((float)asteroizi[i].getDistanta() / 1000) * 2 * rachete[j]->getConsum();
            fisier<<combustibilConsumat<<";";
            fisier<<((float)asteroizi[i].getDistanta() / 1000) * 2 * rachete[j]->getConsum() * rachete[j]->getPretCombustibil()<<";";
            rachete[j]->setCostTotalCombustibil(rachete[j]->getCostTotalCombustibil() + ((float)asteroizi[i].getDistanta() / 1000) * 2 * rachete[j]->getConsum() * rachete[j]->getPretCombustibil());
            //afisez profit brut
            fisier<<adaugaVirgule(profitBrut)<<";";
            //afisez si calculez profitNet
            int profitNet = profitBrut - ((float)asteroizi[i].getDistanta() / 1000) * 2 * rachete[j]->getConsum() * rachete[j]->getPretCombustibil();
            fisier<<adaugaVirgule(profitNet)<<"\n";
            rachete[j]->setProfitNet(rachete[j]->getProfitNet() + profitNet);
        }
    }
    fisier.close();
}

void logistica:: profitTotal(Racheta **& rachete){
    std::ofstream fisier("profit_total.csv");
    if (!fisier.is_open()) {
        std::cout<<"Fisierul nu a putut fi deschis\n";
        exit(1);
    }
    fisier<<"ID Rachetă;Profit brut ($);Cost total combustibil ($);Profit net ($)\n";
    //in primul rand le sortez ca au ramas nesortate din functia misiune
    if(rachete[0]->getNumarRachete()>1){
        for(int i = 0; i<rachete[0]->getNumarRachete(); i++){
            for(int j = i; j<rachete[0]->getNumarRachete(); j++){
                if(stoi(rachete[i]->getId().erase(0, 1)) > stoi(rachete[j]->getId().erase(0, 1))){
                    Racheta *temp = rachete[i];
                    rachete[i]=rachete[j];
                    rachete[j]=temp;
                }
            }
        }
    }

    for(int i = 0; i<rachete[0]->getNumarRachete(); i++){
        fisier<<rachete[i]->getId()<<";";
        int profitBrut = rachete[i]->getProfitNet() + rachete[i]->getCostTotalCombustibil();
        fisier<<adaugaVirgule(profitBrut)<<";";
        fisier<<rachete[i]->getCostTotalCombustibil()<<";"<<adaugaVirgule(rachete[i]->getProfitNet())<<"\n";
    }
    fisier.close();
}

void logistica:: profitPeResursa(piataResurse *& piata){
    std::ofstream fisier("profit_resursa.csv");
    if (!fisier.is_open()) {
        std::cout<<"Fisierul nu a putut fi deschis\n";
        exit(1);
    }
    fisier<<"Resursă;Cantitate extrasă (kg);Profit brut ($)\n";
    for(int i = 0; i<piata[0].getNumarResurse(); i++){
        fisier<<piata[i].getResursa()<<";"<<piata[i].getCantitate()<<";"<<adaugaVirgule(piata[i].getProfitBrut())<<"\n";
    }
    fisier.close();
}

void logistica:: clasamentRachete(Racheta **& rachete){
    //calculez scorul de eficienta
    for(int i = 0; i<rachete[0]->getNumarRachete(); i++){
        if(rachete[i]->getMisiuni()){
            int scorEficienta = rachete[i]->getProfitNet() / rachete[i]->getMisiuni();
            rachete[i]->setScorEficienta(scorEficienta);
        }
    }
    //sortare in functie de clasament
    if(rachete[0]->getNumarRachete()>1){
        for(int i = 0; i<rachete[0]->getNumarRachete(); i++){
            for(int j = i; j<rachete[0]->getNumarRachete(); j++){
                if(rachete[i]->getScorEficienta() < rachete[j]->getScorEficienta()){
                    Racheta *temp = rachete[i];
                    rachete[i]=rachete[j];
                    rachete[j]=temp;
                }
            }
        }
    }
    std::ofstream fisier("clasament_rachete.csv");
    if (!fisier.is_open()) {
        std::cout<<"Fisierul nu a putut fi deschis\n";
        exit(1);
    }
    fisier<<"Loc;ID Rachetă;Profit net ($);Număr misiuni;Scor eficiență\n";
    for(int i = 0; i < rachete[0]->getNumarRachete(); i++){
        fisier<<i+1<<";"<<rachete[i]->getId()<<";"<<adaugaVirgule(rachete[i]->getProfitNet())<<";";
        fisier<<rachete[i]->getMisiuni()<<";"<<adaugaVirgule(rachete[i]->getScorEficienta())<<"\n";
    }
    fisier.close();
}

void logistica:: eliberareMemorie(Racheta **& rachete, piataResurse *& piata, Asteroid *&asteroizi){
    delete[] piata;
    delete[] asteroizi;
    for(int i=0; i<rachete[0]->getNumarRachete(); i++){
        delete rachete[i];
    }
    delete[] rachete;
}