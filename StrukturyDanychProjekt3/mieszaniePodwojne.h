#pragma once
#include <iostream>
class mieszaniePodwojne
{
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
	int hash1(int klucz);
	int hash2(int klucz);
	void rehash();

public:
	mieszaniePodwojne()
	{
		rozmiar = 2;
		wielkosc = 0;
		tablica = new Dane[rozmiar];
	}
	~mieszaniePodwojne()
	{
		delete[] tablica;
	}
	void insert(int klucz, int wartosc);
	void remove(int klucz);
	void pokaz();
};

