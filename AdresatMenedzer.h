#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer
{
   const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
   vector <Adresat> adresaci;
   PlikZAdresatami plikZAdresatami;
   
   void wyswietlDaneAdresata(Adresat adresat);
   Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
   string wczytajLinie();
   string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
   int podajIdWskazanegoAdresata();
   char wybierzOpcjeZMenuEdycja();
   void ustawNoweImie(Adresat &adresat);
   void ustawNoweNazwisko(Adresat &adresat);
   void ustawNowyNumerTelefonu(Adresat &adresat);
   void ustawNowyEmail(Adresat &adresat);
   void ustawNowyAdres(Adresat &adresat);

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) 
        : plikZAdresatami(nazwaPlikuZAdresatami), 
          ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    
   void wyswietlWszystkichAdresatow();
   void dodajAdresata();
   void usunAdresata();
   void edytujAdresata();
   void wyszukajPoImieniu();
   void wyszukajPoNazwisku();
};

#endif
