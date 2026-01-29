#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class PlikTekstowy
{
protected:
    string PLIK_TEKSTOWY;
public:
    PlikTekstowy(string plikTekstowy);
    string pobierzNazwePliku();
    bool czyPlikJestPusty(fstream &plikTekstowy);
};

#endif // PLIKTEKSTOWY_H