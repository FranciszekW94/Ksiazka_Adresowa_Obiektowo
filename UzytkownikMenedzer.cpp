#include "UzytkownikMenedrzer.h"
#include <iostream>
#include <string>

using namespace std;


void UzytkownikMenedzer::rejestracjaUzytkownika()
{
  Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

  uzytkownicy.push_back(uzytkownik);
  
  plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

  cout << endl << "Konto zalozono pomyslnie" << endl << endl;
  //system("pause");

}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

   
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;

    do
    {
        cout  << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);

    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);
    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}


int UzytkownikMenedzer:: pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}


bool UzytkownikMenedzer:: czyIstniejeLogin(string login)
{ 
    for (int i = 0; i < uzytkownicy.size(); i++)
        {
            if (uzytkownicy[i].pobierzLogin() == login)
            {
                cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
                return true;
            }
        }
    return false;

}

void UzytkownikMenedzer:: wypiszWszystkichUzytkownikow()
{
    cout << "=== Lista wszystkich uzytkownikow ===" << endl;
    cout << "Liczba uzytkownikow w wektorze: " << uzytkownicy.size() << endl;
    
    for (int i = 0; i < uzytkownicy.size(); i++)
        {
            cout << "ID: " << uzytkownicy[i].pobierzId() << endl;
            cout << "Login: " << uzytkownicy[i].pobierzLogin() << endl;
            cout << "Haslo: " << uzytkownicy[i].pobierzHaslo() << endl;
            cout << "---" << endl;
        }
}

void UzytkownikMenedzer::wczytajUzytkownikowZPliku()
{
    cout << "Wczytywanie uzytkownikow z pliku..." << endl;
    plikZUzytkownikami.wczytajUzytkownikowZPliku(uzytkownicy);
    cout << "Wczytano " << uzytkownicy.size() << " uzytkownikow z pliku." << endl;
}



void UzytkownikMenedzer::logowanieUzytkownika()
{
    //Uzytkownik uzytkownik;
    string login = "", haslo = "";
    cout << endl << "Podaj login: ";
    //login = wczytajLinie();
    cin.ignore(); // Wyczyść bufor wejścia
    getline(cin, login);
     
   // vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    
    //while (itr != uzytkownicy.end())
    for (auto& uzytkownik : uzytkownicy)
    {
        
        //if (itr -> login == login)
        if (uzytkownik.pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
               // haslo = wczytajLinie();
                
                getline(cin, haslo);
               

                //if (itr -> haslo == haslo)
                if (uzytkownik.pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    //system("pause");
                    //return itr -> id;
                   //return uzytkownik.pobierzId();
                    idZalogowanegoUzytkownika = uzytkownik.pobierzId();
                    return;
                   // return idZalogowanegoUzytkownika;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
           // system("pause");
            //return 0;
            idZalogowanegoUzytkownika = 0;
            return;
            //return idZalogowanegoUzytkownika;
        }
       // itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    //system("pause");
   // return 0;
    idZalogowanegoUzytkownika = 0;
    //return idZalogowanegoUzytkownika;
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}


void UzytkownikMenedzer::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
}



void UzytkownikMenedzer:: zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    //noweHaslo = wczytajLinie();
    getline(cin, noweHaslo);

    for (auto& uzytkownik : uzytkownicy)
    {                
        if (uzytkownik.pobierzId() == idZalogowanegoUzytkownika)
        {
            uzytkownik.ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            break;  // break tylko jeśli znaleziono użytkownika
        }
    }
    
    // Zapisz zmiany do pliku
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}


