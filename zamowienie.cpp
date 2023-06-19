#include <iostream>
#include <fstream>
#include <vector>
#include "zamowienie.h"

using namespace std;

void Zamowienie::dodajZamowienie(vector<Zamowienie> &zamowienia, vector<string> &produkty)
{
    Zamowienie noweZamowienie;
    cout << "Wybierz produkt: " << endl;
    for (size_t i = 0; i < produkty.size(); ++i) {
        cout << i + 1 << ". " << produkty[i] << endl;
    }
    int produktIndex;
    cout << "Kto kupuje: " << endl;
    cin >> noweZamowienie.klijentelia;
    cout << "Wybierz numer produktu: ";
    cin >> produktIndex;
    if (produktIndex >= 1 && produktIndex <= produkty.size()) {
        noweZamowienie.produkt = produkty[produktIndex - 1];
        cout << "Ilosc: ";
        cin >> noweZamowienie.ilosc;
        cout << "Stawka VAT: ";
        cin >> noweZamowienie.stawkaVAT;
        cout << "Cena: ";
        cin >> noweZamowienie.cena;
        cout << "Data zamowienia: ";
        cin >> noweZamowienie.dataZamowienia;
        noweZamowienie.pelnaWartosc = noweZamowienie.cena * noweZamowienie.ilosc * (1 + noweZamowienie.stawkaVAT);
        cout << "Sposob platnosci (0 - przelew, 1 - blik, 2 - gotowka): ";
        int sposobPlacenia;
        cin >> sposobPlacenia;
        noweZamowienie.sposobPlacenia = static_cast<SposobPlatnosci>(sposobPlacenia);
        zamowienia.push_back(noweZamowienie);
        cout << "Nowe zamowienie zostalo dodane!" << endl;
    } else {
        cout << "Nie znaleziono podanego zamowienia!" << endl;
    }
}

void Zamowienie::edytujZamowienie(vector<Zamowienie>& zamowienia) {
    int IndexZamowienia;
    cout << "Podaj numer zamowienia, ktore chcesz zmodyfikowac: ";
    cin >> IndexZamowienia;
    if (IndexZamowienia >= 1 && IndexZamowienia <= zamowienia.size()) {
        Zamowienie& zamowienie = zamowienia[IndexZamowienia - 1];
        cout << "Nowy produkt: ";
        cin >> zamowienie.produkt;
        cout << "Nowa ilosc: ";
        cin >> zamowienie.ilosc;
        cout << "Nowa stawka VAT: ";
        cin >> zamowienie.stawkaVAT;
        cout << "Nowa cena: ";
        cin >> zamowienie.cena;
        cout << "Nowa data zamowienia: ";
        cin >> zamowienie.dataZamowienia;
        zamowienie.pelnaWartosc = zamowienie.cena * zamowienie.ilosc * (1 + zamowienie.stawkaVAT);
        cout << "Nowy sposob platnosci (0 - przelew, 1 - blik, 2 - gotowka): ";
        int sposobPlacenia;
        cin >> sposobPlacenia;
        zamowienie.sposobPlacenia = static_cast<SposobPlatnosci>(sposobPlacenia);
        cout << "Dane zamowienia zostaly zaktualizowane!" << endl;
    } else {
        cout << "Nieznaleziono podanego zamowienia!" << endl;
    }
}

vector<string> Zamowienie::PobierzProduktyZListy(string filename) {
    vector<string> produkty;
    ifstream file(filename);
    if (file.is_open()) {
        string produkt;
        while (getline(file, produkt)) {
            produkty.push_back(produkt);
        }
        file.close();
        cout << "Lista produktow zostala wczytana z pliku " << filename << "!" << endl;
    } else {
        cout << "Blad przy wczytywaniu pliku " << filename << "!" << endl;
    }
    return produkty;
}

void Zamowienie::wyswietlProdukty(vector<string>& produkty) {
    cout << "Lista dostepnych w sprzedaży produktow:" << endl;
    for (auto& product : produkty) {
        cout << " " << product << endl;
    }
}

void Zamowienie::wyswietlZamowienia(vector<Zamowienie>& zamowienia) {
    cout << "Lista zamowien:" << endl;
    for (size_t i = 0; i < zamowienia.size(); ++i) {
        Zamowienie& zamowienie = zamowienia[i];
        cout << "Zamowienie " << i + 1 << ":" << endl;
        cout << "Dane klijenta " << zamowienie.klijentelia << endl;
        cout << "Produkt: " << zamowienie.produkt << endl;
        cout << "Ilosc: " << zamowienie.ilosc << endl;
        cout << "Stawka VAT: " << zamowienie.stawkaVAT << endl;
        cout << "Cena: " << zamowienie.cena << endl;
        cout << "Data zamowienia: " << zamowienie.dataZamowienia << endl;
        cout << "Wartosc calego zamowienia: " << zamowienie.pelnaWartosc << endl;
        if(zamowienie.sposobPlacenia==0){
        cout << "Sposob platnosci: przelew " << endl; }
        if(zamowienie.sposobPlacenia==1){
        cout << "Sposob platnosci: blik " << endl; }
        if(zamowienie.sposobPlacenia==2){
        cout << "Sposob platnosci: gotowka " << endl; }
    }
}

void Zamowienie::zapiszZamowieniadoPlikuTekstowego(vector<Zamowienie> &zamowienia, string filename)
{
    ofstream file(filename);
    if (file.is_open()) {
        for (auto& zamowienie :zamowienia) {
            file << zamowienie.produkt << ", " << zamowienie.ilosc << ", " << zamowienie.stawkaVAT << ", " << zamowienie.cena
                 << ", " << zamowienie.dataZamowienia << ", " << zamowienie.pelnaWartosc << ", ";
                if(zamowienie.sposobPlacenia==0){
                cout << "Sposob platnosci: przelew " << endl; }
                if(zamowienie.sposobPlacenia==1){
                cout << "Sposob platnosci: blik " << endl; }
                if(zamowienie.sposobPlacenia==2){
                cout << "Sposob platnosci: gotowka " << endl; }
        }
        file.close();
        cout << "Dane zamowien zostalo zapisane do pliku Tekstowego" << filename << "!" << endl;
    } else {
        cout << "Blad przy zapisie do pliku " << filename << "!" << endl;
    }
}

void Zamowienie::zapiszZamowieniadoPlikuBinarnego(vector<Zamowienie> &zamowienia, string filename)
{
    ofstream file(filename, ios::binary);
    if (file.is_open()) {
        for (auto& zamowienie : zamowienia) {
            file.write(reinterpret_cast<char*>(&zamowienie), sizeof(Zamowienie));
        }
        file.close();
        cout << "Dane zamowien zostaly zapisane do pliku Binarnego " << filename << "!" << endl;
    } else {
        cout << "Blad przy zapisie do pliku " << filename << "!" << endl;
    }
}

