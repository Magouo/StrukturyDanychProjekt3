#pragma once
#include <iostream>
class mieszanieKukulcze
{
private:
	struct Dane {
		int klucz;
		int wartosc;
		bool czyZajete;
		Dane()
		{
			klucz = 0;
			wartosc = 0;
			czyZajete = false;
		}
	};
	Dane* tablica1;
	Dane* tablica2;
	int rozmiar;
	int wielkosc;
	int maxPowtorzenia;

	int hash1(int klucz);
	int hash2(int klucz);
	void rehash();
	void kukulkaInsert(int klucz, int wartosc, int licznik);
public:
	mieszanieKukulcze()
	{
		rozmiar = 2;
		wielkosc = 0;
		maxPowtorzenia = 10;
		tablica1 = new Dane[rozmiar];
		tablica2 = new Dane[rozmiar];
	}
	~mieszanieKukulcze()
	{
		delete[] tablica1;
		delete[] tablica2;
	}
	void insert(int klucz, int wartosc);
	void remove(int klucz);
	void pokaz();
};

