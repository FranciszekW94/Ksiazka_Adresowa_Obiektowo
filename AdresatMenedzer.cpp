#include "AdresatMenedzer.h"
#include <iostream>
#include <string>

using namespace std;

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

   // system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(ID_ZALOGOWANEGO_UZYTKOWNIKA, plikZAdresatami.pobierzZPlikuIdOstatniegoAdresata());

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

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}


int AdresatMenedzer::podajIdWskazanegoAdresata()
{
    int idWybranegoAdresata = 0;
    
    wyswietlWszystkichAdresatow();
    
    if (!adresaci.empty())
    {
        cout << "Podaj id adresata: ";
        cin >> idWybranegoAdresata;
        cin.ignore();
    }
    return idWybranegoAdresata;
}

void AdresatMenedzer::usunAdresata()
{
    int idUsuwanegoAdresata = 0;

    //system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWskazanegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't')
            {
                plikZAdresatami.usunWskazanegoAdresataZPliku(idUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
               // system("pause");
                return;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                //system("pause");
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        //system("pause");
    }
}




void AdresatMenedzer::edytujAdresata()
{
   // system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWskazanegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                ustawNoweImie(adresaci[i]);
                break;
            case '2':
                ustawNoweNazwisko(adresaci[i]);
                break;
            case '3':
                ustawNowyNumerTelefonu(adresaci[i]);
                break;
            case '4':
                ustawNowyEmail(adresaci[i]);
                break;
            case '5':
                ustawNowyAdres(adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    //system("pause");
}

char AdresatMenedzer::wybierzOpcjeZMenuEdycja()
{
    char wybor;
    cout << endl << ">>> MENU EDYCJI <<<" << endl;
    cout << "1. Zmien imie" << endl;
    cout << "2. Zmien nazwisko" << endl;
    cout << "3. Zmien numer telefonu" << endl;
    cout << "4. Zmien email" << endl;
    cout << "5. Zmien adres" << endl;
    cout << "6. Powrot do menu uzytkownika" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();
    return wybor;
}

void AdresatMenedzer::ustawNoweImie(Adresat &adresat)
{
    string noweImie;
    cout << "Podaj nowe imie: ";
    noweImie = wczytajLinie();
    noweImie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(noweImie);
    adresat.ustawImie(noweImie);
    plikZAdresatami.zaktualizujDaneAdresataWPliku(adresat);
    cout << "Imie zostalo zmienione." << endl;
}

void AdresatMenedzer::ustawNoweNazwisko(Adresat &adresat)
{
    string noweNazwisko;
    cout << "Podaj nowe nazwisko: ";
    noweNazwisko = wczytajLinie();
    noweNazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(noweNazwisko);
    adresat.ustawNazwisko(noweNazwisko);
    plikZAdresatami.zaktualizujDaneAdresataWPliku(adresat);
    cout << "Nazwisko zostalo zmienione." << endl;
}

void AdresatMenedzer::ustawNowyNumerTelefonu(Adresat &adresat)
{
    string nowyNumer;
    cout << "Podaj nowy numer telefonu: ";
    nowyNumer = wczytajLinie();
    adresat.ustawNumerTelefonu(nowyNumer);
    plikZAdresatami.zaktualizujDaneAdresataWPliku(adresat);
    cout << "Numer telefonu zostal zmieniony." << endl;
}

void AdresatMenedzer::ustawNowyEmail(Adresat &adresat)
{
    string nowyEmail;
    cout << "Podaj nowy email: ";
    nowyEmail = wczytajLinie();
    adresat.ustawEmail(nowyEmail);
    plikZAdresatami.zaktualizujDaneAdresataWPliku(adresat);
    cout << "Email zostal zmieniony." << endl;
}

void AdresatMenedzer::ustawNowyAdres(Adresat &adresat)
{
    string nowyAdres;
    cout << "Podaj nowy adres: ";
    nowyAdres = wczytajLinie();
    adresat.ustawAdres(nowyAdres);
    plikZAdresatami.zaktualizujDaneAdresataWPliku(adresat);
    cout << "Adres zostal zmieniony." << endl;
}

void AdresatMenedzer::wyszukajPoImieniu()
{
    string szukaneImie;
    cout << "Podaj imie do wyszukania: ";
    cin.ignore();
    szukaneImie = wczytajLinie();
    szukaneImie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(szukaneImie);
    
    bool znaleziono = false;
    cout << endl << ">>> WYNIKI WYSZUKIWANIA <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    
    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzImie() == szukaneImie)
        {
            wyswietlDaneAdresata(adresaci[i]);
            znaleziono = true;
        }
    }
    
    if (!znaleziono)
    {
        cout << "Nie znaleziono adresatow o imieniu: " << szukaneImie << endl;
    }
    
    (void)system("read -p 'Nacisnij dowolny klawisz aby kontynuowac...'");
}

void AdresatMenedzer::wyszukajPoNazwisku()
{
    string szukaneNazwisko;
    cout << "Podaj nazwisko do wyszukania: ";
    cin.ignore();
    szukaneNazwisko = wczytajLinie();
    szukaneNazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(szukaneNazwisko);
    
    bool znaleziono = false;
    cout << endl << ">>> WYNIKI WYSZUKIWANIA <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    
    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzNazwisko() == szukaneNazwisko)
        {
            wyswietlDaneAdresata(adresaci[i]);
            znaleziono = true;
        }
    }
    
    if (!znaleziono)
    {
        cout << "Nie znaleziono adresatow o nazwisku: " << szukaneNazwisko << endl;
    }
    
    (void)system("read -p 'Nacisnij dowolny klawisz aby kontynuowac...'");
}