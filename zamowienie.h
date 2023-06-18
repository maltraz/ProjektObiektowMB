#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H
#include <string>
#include <vector>

using namespace std;

class Zamowienie {
public:
    string produkt;
    int ilosc;
    float stawkaVAT;
    float cena;
    string dataZamowienia;
    float pelnaWartosc;
    string sposobPlacenia;
    string klijentelia;
    void dodajZamowienie(vector<Zamowienie>& zamowienia, vector<string>& produkty);
    void edytujZamowienie(vector<Zamowienie>& zamowienia);
    vector<string> PobierzProduktyZListy(string filename);
    void wyswietlProdukty(vector<string>& produkty);
    void wyswietlZamowienia(vector<Zamowienie>& zamowienia);
    void zapiszZamowieniadoPlikuTekstowego(vector<Zamowienie>& zamowienia, string filename);
    void zapiszZamowieniadoPlikuBinarnego(vector<Zamowienie>& zamowienia, string filename);
};

#endif // ZAMOWIENIE_H
