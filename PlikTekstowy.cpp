#include "PlikTekstowy.h"

PlikTekstowy::PlikTekstowy(string plikTekstowy)
: PLIK_TEKSTOWY(plikTekstowy) {};

string PlikTekstowy::pobierzNazwePliku()
{
    return PLIK_TEKSTOWY;
}

bool PlikTekstowy::czyPlikJestPusty(fstream &plikTekstowy)
{
    plikTekstowy.seekp(0, ios::end);
    if (plikTekstowy.tellp() == 0)
        return true;
    else
        return false;
}