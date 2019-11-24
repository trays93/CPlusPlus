#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

struct csoki
{
	string nev;
	int ar;
	int darabSzam;
};

int main()
{
	csoki BOLT[15];

	int csokiDarab, i, osszErtek = 0, atlagAr = 0, legDragabbCsokiIndex = 0;

	cout << "Csokibolt leltar" << endl << endl;

	do
	{
		cout << "Adja meg a csokolade termekek szamat (1-15):";
		cin >> csokiDarab;
		cin.ignore();
		if ((csokiDarab < 1 || 15 < csokiDarab))
		{
			cout << "Hibas darabszam! A darabszam 1 es 15 kozotti lehet!" << endl;
		}
	} while (csokiDarab < 1 || 15 < csokiDarab);

	srand((unsigned)time(NULL));
	cout << endl;

	for (i = 0; i < csokiDarab; i++)
	{
		cout << "Adja meg a(z)" << i + 1 << ". csoki nevet: ";
		getline(cin, BOLT[i].nev);
		BOLT[i].darabSzam = rand() % 20 + 1;
		do
		{
			cout << "Adja meg a(z)" << i + 1 << ". csoki arat (Ft): ";
			cin >> BOLT[i].ar;
			cin.ignore();
			if (BOLT[i].ar < 100 || 1000 < BOLT[i].ar)
			{
				cout << "Hibas ar! Az ar 100 es 1000 Ft kozotti lehet!" << endl;
			}
		} while (BOLT[i].ar < 100 || 1000 < BOLT[i].ar);
	}

	system("cls");

	cout.setf(ios::left);
	cout << setw(25) << "Nev" << setw(15) << "Ar (Ft)" << setw(15) << "Db" << endl;
	for (i = 0; i < csokiDarab; i++)
	{
		cout << setw(25) << BOLT[i].nev << setw(15) << BOLT[i].ar << setw(15) << BOLT[i].darabSzam << endl;
		osszErtek += BOLT[i].ar * BOLT[i].darabSzam;
		atlagAr += BOLT[i].ar;
	}

	cout << endl << "A termekek osszerteke: " << osszErtek << " Ft" << endl;

	for (i = 1; i < csokiDarab; i++)
	{
		if (BOLT[legDragabbCsokiIndex].ar < BOLT[i].ar)
		{
			legDragabbCsokiIndex = i;
		}
	}
	cout << "A legdragabb csoki: " << BOLT[legDragabbCsokiIndex].nev << endl << endl;

	atlagAr /= csokiDarab;
	cout << "Az atlagar (" << atlagAr << " Ft) alatti csokik: " << endl;
	cout << setw(25) << "Nev" << setw(15) << "Db" << endl;
	for (i = 0; i < csokiDarab; i++)
	{
		if (atlagAr > BOLT[i].ar)
		{
			cout << setw(25) << BOLT[i].nev << setw(15) << BOLT[i].darabSzam << endl;
		}
	}

	system("pause");

	return 0;
}