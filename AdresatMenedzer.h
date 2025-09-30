#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
//#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer
{
   int idZalogowanegoUzytkownika;
   vector <Adresat> adresaci;
   PlikZAdresatami plikZAdresatami;
   

   void wyswietlDaneAdresata(Adresat adresat);
   Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
   string wczytajLinie();
   string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami), idZalogowanegoUzytkownika(0) {};
   void zalogujUzytkownika(int idUzytkownika);
   void wyswietlWszystkichAdresatow();
   void dodajAdresata();

  

};


#endif