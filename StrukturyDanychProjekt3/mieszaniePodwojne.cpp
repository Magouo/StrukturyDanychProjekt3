#include "mieszaniePodwojne.h"
using namespace std;
int mieszaniePodwojne::hash1(int klucz)
{
    return klucz % rozmiar;
}

int mieszaniePodwojne::hash2(int klucz)
{
    return ( 5 - (klucz % 5));
}

void mieszaniePodwojne::rehash()
{
    int staryRozmiar = rozmiar;
    Dane* staraTablica = tablica;
    rozmiar *= 2;
    tablica = new Dane[rozmiar];
    wielkosc = 0;

    for (int i = 0; i < staryRozmiar; i++)
    {
        if (staraTablica[i].czyZajete)
        {
            insert(staraTablica[i].klucz, staraTablica[i].wartosc);
        }
    }
    delete[] staraTablica;
}

void mieszaniePodwojne::insert(int klucz, int wartosc)
{
    if (wielkosc >= rozmiar / 2)
    {
        rehash();
    }
    int index = hash1(klucz);
    int kolejny = hash2(klucz);
    while (tablica[index].czyZajete && tablica[index].klucz != klucz)
    {
        index = (index + kolejny) % rozmiar;
    }
    if (!tablica[index].czyZajete)
    {
        wielkosc++;
    }
    tablica[index].klucz = klucz;
    tablica[index].wartosc = wartosc;
    tablica[index].czyZajete = true;
}

void mieszaniePodwojne::remove(int klucz)
{
    int index = hash1(klucz);
    int kolejny = hash2(klucz);
    int startIndex = index;

    while (tablica[index].czyZajete)
    {
        if (tablica[index].klucz == klucz)
        {
            tablica[index].czyZajete = false;
            wielkosc--;
            return;
        }
        index = (index + kolejny) % rozmiar;
        if (index == startIndex)
        {
            break;
        }
    }
}

void mieszaniePodwojne::pokaz()
{
    for (int i = 0; i < rozmiar; i++)
    {
        if (tablica[i].czyZajete)
        {
            cout << "Index: " << i << " klucz " << tablica[i].klucz << " wartosc " << tablica[i].wartosc << endl;
        }
    }
}

