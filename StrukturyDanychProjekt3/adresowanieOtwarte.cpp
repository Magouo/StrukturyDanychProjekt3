#include "adresowanieOtwarte.h"
using namespace std;
int adresowanieOtwarte::hash(int klucz)
{
	return klucz %  rozmiar;
}

void adresowanieOtwarte::rehash()
{
	int staryRozmiar = rozmiar;
	Dane* staraTablica = tablica;
	rozmiar *= 2;
	tablica = new Dane[rozmiar];
	wielkosc = 0;
	for (int i = 0; i < staryRozmiar; i++)
	{
		if (staraTablica->czyZajete)
		{
			insert(staraTablica[i].klucz, staraTablica[i].wartosc);
		}
	}
	delete[] staraTablica;
}


void adresowanieOtwarte::insert(int klucz, int wartosc)
{
	if (wielkosc >= rozmiar / 2)
	{
		rehash();
	}
	int index = hash(klucz);

	while (tablica[index].czyZajete && tablica[index].klucz != klucz)
	{
		index = (index + 1) % rozmiar;
	}
	if (!tablica[index].czyZajete)
	{
		wielkosc++;
	}
	tablica[index].klucz = klucz;
	tablica[index].wartosc = wartosc;
	tablica[index].czyZajete = true;
}

void adresowanieOtwarte::remove(int klucz)
{
	int index = hash(klucz);
	int indexPoczatek = index;
	
	while (tablica[index].czyZajete)
	{
		if (tablica[index].klucz == klucz)
		{
			tablica[index].czyZajete = false;
			wielkosc--;
			return;
		}
		index = (index + 1) % rozmiar;
		if (index == indexPoczatek)
		{
			break;
		}
	}
}

void adresowanieOtwarte::pokaz()
{
	for (int i = 0; i < rozmiar; i++)
	{
		if (tablica[i].czyZajete)
		{
			cout << "Index: " << i << " klucz: " << tablica[i].klucz << " wartoœæ " << tablica[i].wartosc << endl;
		}
	}
}
