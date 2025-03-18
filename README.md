# Nume: Buboaca Justin
# Grupa: 324AB
# IDE: Visual Studio Code
# Sistem de operar: Host: Windows 10 pro, Virtual Box: Linux Mint (am zis sa fac tema pe linux ca sa nu mai am surpriza de data trecuta in care pe windows imi merge bine iar in checker nu primeam punctele si apoi a trebuit sa imi portez pe linux sa vad exact care era treaba si am descoperit cu valgrind care era faza, ma rog, asta daca o sa mai avem checker)

# Observatii
Dupa ce am am citit mai bine tema am observat ca scrie "începând cu extragerea resurselor de la primul asteroid și continuând cu extragerea resurselor de la al doilea asteroid" ceea ce ar insemna ca trebuie extrase resursele in de la asteroizi in ordinea in care se afla ei. In caz contrar s-ar fi puttu face o sortare sa se vada care era cel mai fain de utilizat, dar daca cerinta asta ne cere, inseamna ca nu e cazul de asa ceva.

# Cum functioneaza main

La fel ca si data trecuta am creat un namespace cu numele logistica, fiecare functie avand rolul descris mai jos.

# Functiile din namespace

`citireRachete` face exact ce ii zice si numele. Deschide fisierul, apoi numara cate linii sunt in fisier pentru a putea stii cate rachete sunt in total. In cazul in care in tabel avem antetul sau este chiar gol atunci iesim din program pentru prelucrarea datelor nu ar fi posibila.

`citirePiata` functioneaza exact ca si citire rachete

`citireAsteroid` asta este putin mai speciala pentru ca putem avea acelasi asteroid pe mai multe randuri asa ca uite la ce s a gandit baiatul vostru: duc cursorul din fisier la final si merg cu spatele pana dau de primul "\n". In acel moment citesc linia si ar insemna ca am ultima linie deci automat si id-ul de la ultima linie pe care il extrag exterior si il transform cu stoi in intreg dupa ce elimin primul caracter si scot frumos numarul de asteroizi. Daca totusi nu dau de acel \n o sa ajung la inceputul fisierului iar acolo citesc antetul sau daca fisierul este gol nu citesc nimic. Deci citesc si daca se intampla sa fie antetul sau sirul gol ies din prigram ca nu o sa am cum sa prelucrez mai tarziu datele. Dupa ce am terminat cu partea asta, ma intorc la incepiutul fisierului si de acolo citesc antet si continui sa citesc doar ca aici putem sa avem mai multe resurse pe asteroid, deci verific daca ma aflu in acelasi asteroid la citire. Daca ma aflu in acelasi asteroid ii adaug resursele, daca nu trec la urmatorul asteroid si ii adaug lui resursele si tot asa pana citesc toate datele.

`misiune` este o functie ceva mai speciala as zice ca practic aici se realizeaza cam toata logica din spatele programului. Totodata, cu ajutorul acestei functii scriu in fisierul misiuni.csv informatiile aferente fiecarei misiuni realizate. Primul lucru pe care l am facut a fost sa calculez numarul de drumuri si un pret aferent pe care l am folosit ulterior la sortarea rachetelor pentru a stabili ordinea celor mai bune rachete pentru fiecare asteroid in parte. Mai pe romaneste, am luat asteroidul si am sortat rachetele in functie de cea mai profitabila pentru fiecare asteroid in parte. Dupa ce am stabilit aceasta ordine incep practic sa realizez misiunea care este trecuta si in cod ca si comment prin //misiunea. Anyway, de aici incepe practic partea mai interesanta, grea, cum vreti sa ii ziceti. Pentru asteroidul in care ma aflu verific cu atentie daca poate ajunge vreo racheta la el. In cazul in care nici o racheta nu poate ajunge la asteroidul, programul l-am facut in asa fel ca daca nu poate ajunge biata racheta la asteroid, sa trec la verificarea pentru urmatorul asteroid pana ajung la ultimul la care nu se mai poate ajunge sau pana am terminat de mers pe la toate. Ulterior, cu un eachfor am parcusr vectorul meu cu resurse de pe asteroid, facand matematica corespunzatoare cu pixul pe hartie.. ma rog.. cu pen-ul pe tableta ca sa nu zic vreo minciuna.. astfel, am ajuns la ideea ca exista 4 cazuri de tratat:
1. cazul in care o resursa este intr-o canitate mai mare decat capacitatea rachetei si scap usor luand doar acea resursa
2. cazul in care nu mi se umple capacitatea rachetei ceea ce duce la cazurile 3 si 4
3. daca nu s-a umplut capacitatea rachetei iar urmatoarea resursa ar umple restul de spatiu am terminat usor
4. daca nu se umple nici cu cantitatea asta de resursa, caut sa vad iarasi sa mai adaug.
P.S. am uitat sa mentionez ca la 2 si 4 trebuie verificata daca mai exista vreo resursa de unde practic ca sa nu parcurgem degeaba toate acele linii de cod.
In fiecare dintre aceste cazuri am actualizat cantitatiele vandute, profitul realizat, am prelucrat sa vad ce resurse am extras, am facut matematica pentru pret si sper ca nu uit sa mentionez ceva important. 
Dupa realizarea acestora mai calculez si scriu in fisiere restul de informatii necesare cu cantiatea necesara, etc.. daca vedeti ca am afisat cu o formula combusibilul consumat si dupa l-am calculat iar, inseamna doar ca nu l-am mai modificat ca faceam niste teste. Ulterior mai calculez si scriu profiturile cu virgurile aferente.

`profitTotal` e o functie care nu face nimic prea special. Face o sortare a rachetelor ele ramanand in ordine nesortata din prelucrarea de mai sus, dupa care le scriu in ordine informatiile necesare.

`profitPeResursa` este o scriere in fisiere a resurselor.

`clasamentRachete` calculeaza intai scorul de eficienta pentru fiecare racheta realizand ulterior o sortare dupa acesta. Apoi scrie in clasament_rachete.csv dupa cum ni se cere.

`eliberareMemorie` face exact ce ii zice si numele, ii elibereaza memoria. 

# Update fata de primul cod
1. Am actualizat logica astfel incat sa se reincarce combustibilul rachetei. (inainte se putea merge pana se termina de tot combustibilul din rezervor)
2. SOme minor bug fixes
3. Am actualizat programul astfel incat sa poata lucra si cu cazurile in care pretul este float sau cantitate totala e float (de altfel ma lovisem si de un bug din cauza erorilor din virgula mobila)
4. Am actualizat logica de adaugare a virgulei cu o functie care pentru numerele mai umane (mici) ii adauga virgule
