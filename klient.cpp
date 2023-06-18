#include "klient.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Klient::dodajKlienta(vector<Klient>& klienci) {
    Klient nowyKlient;
    cout << "Imie: ";
    cin >> nowyKlient.imie;
    cout << "Nazwisko: ";
    cin >> nowyKlient.nazwisko;
    cout << "Adres: ";
    cin >> nowyKlient.adres;
    cout << "Plec (0 - mezczyzna, 1 - kobieta, 2 - inne, 3 - robot, 4 - helikopter bojowy): ";
    int plec;
    cin >> plec;
    nowyKlient.plec = static_cast<Plec>(plec);
    klienci.push_back(nowyKlient);
    cout << "Nowy klient dodany!" << endl;
}

void Klient::edytujKlienta(vector<Klient>& klienci) {
    string nazwisko;
    cout << "Podaj nazwisko klienta, ktorego dane chcesz zmodyfikowac: ";
    cin >> nazwisko;
    bool found = false;
    for (auto& klient : klienci) {
        if (klient.nazwisko == nazwisko) {
            cout << "Nowe imie: ";
            cin >> klient.imie;
            cout << "Nowe nazwisko: ";
            cin >> klient.nazwisko;
            cout << "Nowy adres: ";
            cin >> klient.adres;
            cout << "Nowa plec: ";
            cout << "Plec (0 - mezczyzna, 1 - kobieta, 2 - inne, 3 - robot, 4 - helikopter bojowy): ";
            int plec;
            cin >> plec;
            klient.plec = static_cast<Plec>(plec);
            found = true;
            cout << "Dane klienta zostaly zaktualizowane!" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Klient nie zostal znaleziony!" << endl;
    }
}

void Klient::zapiszKlientaTekstowo(vector<Klient>& klienci, string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (auto& klient : klienci) {
            file << klient.imie << "," << klient.nazwisko << "," << klient.adres << "," << klient.plec << endl;
        }
        file.close();
        cout << "Dane klientow zostaly zapisane do pliku Tekstowego" << filename << "!" << endl;
    } else {
        cout << "Blad przy zapisie do pliku " << filename << "!" << endl;
    }
}

void Klient::zapiszKlientaBinarnie(vector<Klient>& klienci, string filename) {
    ofstream file(filename, ios::binary);
    if (file.is_open()) {
        for (auto& klient : klienci) {
            file.write(reinterpret_cast<char*>(&klient), sizeof(Klient));
        }
        file.close();
        cout << "Dane klientow zostaly zapisane do pliku Binarnego" << filename << "!" << endl;
    } else {
        cout << "Blad przy zapisie do pliku " << filename << "!" << endl;
    }
}


