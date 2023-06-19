#include <iostream>
#include <fstream>
#include <vector>
#include "klient.h"
#include "zamowienie.h"
using namespace std;

void wyjdz();

int main() {
    vector<Klient> klienci;
    vector<Zamowienie> zamowienia;
    Zamowienie z;
    Klient k;
    vector<string> produkty = z.PobierzProduktyZListy("products.txt");

    int wybor;
        cout << endl;
        cout << "===== MENU = SKLEPU = KOMPUTEROWEGO = MALTRAZ.STUDIO ======================================" << endl;
        cout << "1.  Dodaj klienta" << endl;
        cout << "2.  Edytuj klienta" << endl;
        cout << "3.  Dodaj zamowienie" << endl;
        cout << "4.  Edytuj zamowienie" << endl;
        cout << "5.  Wyswietl liste dostepnych produktow" << endl;
        cout << "6.  Wyswietl liste zamowien" << endl;
        cout << "7.  Zapisz dane klientow do pliku tekstowego" << endl;
        cout << "8.  Zapisz dane klientow do pliku binarnego" << endl;
        cout << "9.  Zapisz dane zamowien do pliku tekstowego" << endl;
        cout << "10. Zapisz dane zamowien do pliku binarnego" << endl;
        cout << "0.  Wyjscie" << endl;
        cout << "====================================================" << endl;
        cout << "Wybierz opcje: " << endl;
    do {
        cin >> wybor;

        switch (wybor) {
            case 1:
                k.dodajKlienta(klienci);
                break;
            case 2:
                k.edytujKlienta(klienci);
                break;
            case 3:
                z.dodajZamowienie(zamowienia, produkty);
                break;
            case 4:
                z.edytujZamowienie(zamowienia);
                break;
            case 5:
                z.wyswietlProdukty(produkty);
                break;
            case 6:
                z.wyswietlZamowienia(zamowienia);
                break;
            case 7:
                k.zapiszKlientaTekstowo(klienci, "klienci.txt");
                break;
            case 8:
                k.zapiszKlientaBinarnie(klienci, "klienci.bin");
                break;
            case 9:
                z.zapiszZamowieniadoPlikuTekstowego(zamowienia, "zamowienia.txt");
                break;
            case 10:
                z.zapiszZamowieniadoPlikuBinarnego(zamowienia, "zamowienia.bin");
                break;
            case 0:
                cout << "Program konczy dzialanie" << endl;
                break;
            default:
                cout << "Podano nieprawidlowa opcje!" << endl;
                break;
        }
    } while (wybor != 0);

    return 0;
}
