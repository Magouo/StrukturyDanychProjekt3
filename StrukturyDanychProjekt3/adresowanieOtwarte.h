#pragma once
#include <iostream>
class adresowanieOtwarte
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

	Dane* tablica;
	int rozmiar;
	int wielkosc;
	int hash(int klucz);
	void rehash();
public:
	adresowanieOtwarte()
	{
		rozmiar = 2;
		wielkosc = 0;
		tablica = new Dane[rozmiar];

	}
	~adresowanieOtwarte()
	{
		delete[] tablica;
	}
	void insert(int klucz, int wartosc);
	void remove(int klucz);
	void pokaz();
};

