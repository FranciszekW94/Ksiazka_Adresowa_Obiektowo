#include <iostream>
#include "KsiazkaAdresowa.h"
#include <cstdlib>

using namespace std;

int main ()
{
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt", "Adresaci.txt");

    while (true)
    {
        if (ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() == 0)
        {
            // MENU GŁÓWNE
            cout << ">>> MENU GŁÓWNE <<<" << endl;
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "3. Wypisz wszystkich użytkownikow" << endl;
            cout << "9. Wyjście" << endl;
            cout << "Twój wybor: ";
            
            char wybor;
            cin >> wybor;

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
               // system("clear");
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
               // system("clear");
                break;
            case '3':
                ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
                //system("clear");
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                break;
            }
        }
        else
        {
            // MENU UŻYTKOWNIKA
            cout << ">>> MENU UZYTKOWNIKA <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Dodaj adresata" << endl;
            cout << "2. Wyszukaj po imieniu" << endl;
            cout << "3. Wyszukaj po nazwisku" << endl;
            cout << "4. Wyświetl adresatow" << endl;
            cout << "5. Usuń adresata" << endl;
            cout << "6. Edytuj adresata" << endl;
            cout << "---------------------------" << endl;
            cout << "7. Zmień haslo" << endl;
            cout << "8. Wyloguj się" << endl;
            cout << "---------------------------" << endl;
            cout << "Twój wybor: ";
            
            char wybor;
            cin >> wybor;

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                //system("clear");
                break;
            case '2':
                ksiazkaAdresowa.wyszukajPoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyszukajPoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                //system("clear");
                break;
            case '8':
                ksiazkaAdresowa.wylogowanieUzytkownika();
               // system("clear");
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                break;
            }
        }
    }

    return 0;
}