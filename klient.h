#ifndef KLIENT_H
#define KLIENT_H
#include <vector>
#include <string>

using namespace std;

enum Plec { mezczyzna, kobieta, inne, robot, helikopter_bojowy};
class Klient {
public:
    string imie;
    string nazwisko;
    string adres;
    Plec plec;
    void dodajKlienta(vector<Klient>& klienci);
    void edytujKlienta(vector<Klient>& klienci);
    void zapiszKlientaTekstowo(vector<Klient>& klienci, string filename);
    void zapiszKlientaBinarnie(vector<Klient>& klienci, string filename);
};

#endif // KLIENT_H
