#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>


#include "UzytkownikMenedrzer.h"
#include "AdresatMenedzer.h"

using namespace std;


class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;    
    AdresatMenedzer adresatMenedzer;

  public:
      KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) :                 uzytkownikMenedzer(nazwaPlikuZUzytkownikami), adresatMenedzer(nazwaPlikuZAdresatami) 
{
          uzytkownikMenedzer.wczytajUzytkownikowZPliku();
         // adresatMenedzer.dopiszAdresataDoPliku();
      } ; 

      void rejestracjaUzytkownika();
      void wypiszWszystkichUzytkownikow();
      void logowanieUzytkownika();
      int pobierzIdZalogowanegoUzytkownika();
      void wylogowanieUzytkownika();
      void zmianaHaslaZalogowanegoUzytkownika();
      void dodajAdresata();
      void wyswietlWszystkichAdresatow();
      
          
 
};

#endif