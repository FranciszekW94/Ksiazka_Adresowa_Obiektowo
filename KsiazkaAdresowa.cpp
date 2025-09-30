#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
    // Wczytaj adresatów dla zalogowanego użytkownika
    adresatMenedzer.zalogujUzytkownika(
        uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()
    );
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika()
{
   return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}
void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
    // Wyczyść dane adresatów po wylogowaniu
    adresatMenedzer.zalogujUzytkownika(0);
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenedzer.wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenedzer.dodajAdresata();
}

