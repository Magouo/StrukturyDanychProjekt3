#include <iostream>
#include "adresowanieOtwarte.h"
#include "mieszanieKukulcze.h"
#include "mieszaniePodwojne.h"
#include <chrono>
using namespace std;

int main()
{
	double adresowanieOtwarteInsert = 0;
	double adresowanieOtwarteRemove = 0;

	double podwojneMieszanieInsert = 0;
	double podwojneMieszanieRemove = 0;

	double mieszanieKukulczeInsert = 0;
	double mieszanieKukulczeRemove = 0;

	chrono::duration<double, nano> czas;

	int rozmiar = 1600000;

	for (int i = 0; i < 10; i++)
	{
		adresowanieOtwarte otwarte;
		mieszaniePodwojne podwojne;
		mieszanieKukulcze kukulka;

		for (int j = 0; j < rozmiar; j++)
		{
			otwarte.insert(j, rand() % 10000 + 1);
			podwojne.insert(j, rand() % 10000 + 1);
			kukulka.insert(j, rand() % 10000 + 1);
		}

		for (int k = 0; k < 5; k++)
		{
			auto start = chrono::high_resolution_clock::now();
			otwarte.insert(rozmiar + k, rand() % 10000 + 1);
			auto stop = chrono::high_resolution_clock::now();
			czas = stop - start;
			adresowanieOtwarteInsert += czas.count();

			auto start1 = chrono::high_resolution_clock::now();
			podwojne.insert(rozmiar + k, rand() % 10000 + 1);
			auto stop1 = chrono::high_resolution_clock::now();
			czas = stop1 - start1;
			podwojneMieszanieInsert += czas.count();

			auto start2 = chrono::high_resolution_clock::now();
			kukulka.insert(rozmiar + k, rand() % 10000 + 1);
			auto stop2 = chrono::high_resolution_clock::now();
			czas = stop2 - start2;
			mieszanieKukulczeInsert += czas.count();

		}

		for (int l = 0; l < 5; l++)
		{
			auto start = chrono::high_resolution_clock::now();
			otwarte.remove(1 + l);
			auto stop = chrono::high_resolution_clock::now();
			czas = stop - start;
			adresowanieOtwarteRemove += czas.count();

			auto start1 = chrono::high_resolution_clock::now();
			podwojne.remove(1 + l);
			auto stop1 = chrono::high_resolution_clock::now();
			czas = stop1 - start1;
			podwojneMieszanieRemove += czas.count();

			auto start2 = chrono::high_resolution_clock::now();
			kukulka.remove(1 + l);
			auto stop2 = chrono::high_resolution_clock::now();
			czas = stop2 - start2;
			mieszanieKukulczeRemove += czas.count();

		}
	}

	cout << "Rozmiar: " << rozmiar << endl;
	cout << "Adresowanie Otwarte" << endl;
	cout << "Insert: " << adresowanieOtwarteInsert / 50 << endl;
	cout << "Remove: " << adresowanieOtwarteRemove / 50 << endl;

	cout << "Mieszanie Podwojne" << endl;
	cout << "Insert: " << podwojneMieszanieInsert / 50 << endl;
	cout << "Remove: " << podwojneMieszanieRemove / 50 << endl;

	cout << "Mieszanie kukulcze" << endl;
	cout << "Insert: " << mieszanieKukulczeInsert / 50 << endl;
	cout << "Remove: " << mieszanieKukulczeRemove / 50 << endl;
}