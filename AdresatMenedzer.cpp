#include "AdresatMenedzer.h"
#include <iostream>
#include <string>

using namespace std;

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

   // system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika, plikZAdresatami.pobierzZPlikuIdOstatniegoAdresata());

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
}


Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    Adresat adresat;

    adresat.ustawId(idOstatniegoAdresata + 1);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cin.ignore(); // Jednorazowe czyszczenie bufora na początku
    cout << "Podaj imie: ";
    string imie = wczytajLinie();
    imie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);

    cout << "Podaj nazwisko: ";
    string nazwisko = wczytajLinie();
    nazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    adresat.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(wczytajLinie());

    return adresat;
}

string AdresatMenedzer::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        tekst[0] = toupper(tekst[0]);
        for (int i = 1; i < tekst.length(); i++)
        {
            tekst[i] = tolower(tekst[i]);
        }
    }
    return tekst;
}


string AdresatMenedzer::wczytajLinie()
{
    string linia = "";
    getline(cin, linia);
    return linia;
}
void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    //system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i = 0; i < adresaci.size(); i++)
        {
            wyswietlDaneAdresata(adresaci[i]);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << "Nacisnij dowolny klawisz aby kontynuowac..." << endl;
    cin.get();
}


void AdresatMenedzer::zalogujUzytkownika(int idUzytkownika)
{
    idZalogowanegoUzytkownika = idUzytkownika;  // Ustaw ID zalogowanego użytkownika
    cout << "ID zalogowanego Uzytkownika z poziomu AdresatMenedzer: " << idZalogowanegoUzytkownika << endl;
    
    adresaci.clear();  // Wyczyść poprzednie dane
    if (idZalogowanegoUzytkownika > 0)
    {
        int idOstatniegoAdresataZPliku = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);
        cout << "Wczytano " << adresaci.size() << " adresatow dla uzytkownika ID: " << idZalogowanegoUzytkownika << endl;
        
        // Aktualizuj ID ostatniego adresata na podstawie wczytanych danych
        if (!adresaci.empty())
        {
            int najwyzszeId = 0;
            for (int i = 0; i < adresaci.size(); i++)
            {
                if (adresaci[i].pobierzId() > najwyzszeId)
                    najwyzszeId = adresaci[i].pobierzId();
            }
            // Ustaw ID ostatniego adresata w pliku na najwyższe znalezione ID
            plikZAdresatami.ustawIdOstatniegoAdresata(najwyzszeId);
        }
    }
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}
