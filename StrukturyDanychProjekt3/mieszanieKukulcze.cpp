#include "mieszanieKukulcze.h"
using namespace std;
int mieszanieKukulcze::hash1(int klucz)
{
	return klucz % rozmiar;
}

int mieszanieKukulcze::hash2(int klucz)
{
	return (klucz % rozmiar) % rozmiar;
}

void mieszanieKukulcze::rehash()
{
	int staryRozmiar = rozmiar;
	Dane* staraTablica1 = tablica1;
	Dane* staraTablica2 = tablica2;
	rozmiar *= 2;
	tablica1 = new Dane[rozmiar];
	tablica2 = new Dane[rozmiar];
	wielkosc = 0;

	for (int i = 0; i < staryRozmiar; i++)
	{
		if (staraTablica1[i].czyZajete)
		{
			insert(staraTablica1[i].klucz, staraTablica1[i].wartosc);
		}
		if(staraTablica2[i].czyZajete)
		{
			insert(staraTablica2[i].klucz, staraTablica2[i].wartosc);
		}
	}
	delete[] staraTablica1;
	delete[] staraTablica2;
}

void mieszanieKukulcze::kukulkaInsert(int klucz, int wartosc, int licznik)
{
	if (licznik >= maxPowtorzenia)
	{
		rehash();
		insert(klucz, wartosc);
		return;
	}

	int index1 = hash1(klucz);
	if (!tablica1[index1].czyZajete)
	{
		tablica1[index1].klucz = klucz;
		tablica1[index1].wartosc = wartosc;
		tablica1[index1].czyZajete = true;
		wielkosc++;
		return;
	}
	int tenSamklucz = tablica1[index1].klucz;
	int tenSamKluczWartosc = tablica1[index1].wartosc;

	tablica1[index1].klucz = klucz;
	tablica1[index1].wartosc = wartosc;
	tablica1[index1].czyZajete = true;

	int index2 = hash2(tenSamklucz);

	if (!tablica2[index2].czyZajete)
	{
		tablica2[index2].klucz = tenSamklucz;
		tablica2[index2].wartosc = tenSamKluczWartosc;
		tablica2[index2].czyZajete = true;
		return;
	}
	if (tablica1[index1].klucz == klucz && tablica2[index2].klucz == klucz)
	{
		tablica1[index1].klucz = klucz;
		tablica1[index1].wartosc = wartosc;
		tablica1[index1].czyZajete = true;
		return;
	}
	kukulkaInsert(tenSamklucz, tenSamKluczWartosc, licznik + 1);

}

void mieszanieKukulcze::insert(int klucz, int wartosc)
{
	if (wielkosc >= rozmiar / 2)
	{
		rehash();
	}
	kukulkaInsert(klucz, wartosc, 0);
}

void mieszanieKukulcze::remove(int klucz)
{
	int index1 = hash1(klucz);
	if (tablica1[index1].czyZajete)
	{
		tablica1[index1].czyZajete = false;
		wielkosc--;
		return;
	}
	int index2 = hash2(klucz);
	if (tablica2[index2].czyZajete)
	{
		tablica2[index2].czyZajete = false;
		wielkosc--;
		return;
	}
}

void mieszanieKukulcze::pokaz()
{
	cout << "Tablica 1:" << endl;
	for (int i = 0; i < rozmiar; i++)
	{
		if (tablica1[i].czyZajete)
		{
			cout << "Index: " << i << " klucz: " << tablica1[i].klucz << " wartosc: " << tablica1[i].wartosc << endl;
		}

	}
	cout << "Tablica 2: " << endl;
	for (int i = 0; i < rozmiar; i++)
	{
		if (tablica2[i].czyZajete)
		{
			cout << "Index: " << i << " klucz: " << tablica2[i].klucz << " wartosc: " << tablica2[i].wartosc << endl;
		}
	}
}
