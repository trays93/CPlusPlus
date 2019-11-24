#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

struct Aru
{
	string nev;
	int ar;
	int db;
};

int main()
{
	Aru bolt[15];
	int i, legdragabb, ertek = 0, atlagar = 0, aruszam, otnelTobbDb = 0;

	srand((unsigned)time(NULL));

	do
	{
		cout << "Add meg mennyi arut szeretnel felvenni (1-15): ";
		cin >> aruszam;
		cin.ignore();
		if (aruszam < 1 || 15 < aruszam)
		{
			cout << "Hiba! A termekszam 1 es 15 kozotti lehet!\n";
		}
	} while (aruszam < 1 || 15 < aruszam);

	for (i = 0; i < aruszam; i++)
	{
		cout << "Add meg a(z) " << i + 1 << ". aru nevet: ";
		getline(cin, bolt[i].nev);
		do
		{
			cout << "Add meg a(z) " << i + 1 << ". termek arat (100-5000): ";
			cin >> bolt[i].ar;
			cin.ignore();
			if (bolt[i].ar < 100 || bolt[i].ar > 5000)
			{
				cout << "Hiba! Az ar 100 es 5000 kozotti lehet!" << endl;
			}
		} while (bolt[i].ar < 100 || bolt[i].ar > 5000);
		bolt[i].db = rand() % 10 + 1;
		cout << "Termek darabaszama: " << bolt[i].db << endl;
	}

	system("cls");

	cout.setf(ios::left);
	cout << setw(25) << "Termeknev" << "\tAr\tDarabszam" << endl;

	for (i = 0; i < aruszam; i++)
	{
		cout << setw(25) << bolt[i].nev << "\t" << bolt[i].ar << "\t" << bolt[i].db << endl;
		ertek += bolt[i].ar * bolt[i].db;
		atlagar += bolt[i].ar;
		if (bolt[i].db > 5)
		{
			otnelTobbDb++;
		}
	}

	cout << endl << "A teljes arukeszlet erteke: " << ertek << endl;
	cout << "A termekek atlagos ara: " << (float)atlagar / aruszam << endl;
	cout << otnelTobbDb << " db termeknek van 5-nel tobb darab raktarkeszleten." << endl << endl;

	legdragabb = 0;
	for (i = 1; i < aruszam; i++)
	{
		if (bolt[legdragabb].ar < bolt[i].ar)
		{
			legdragabb = i;
		}
	}
	cout << "A legdragabb termek neve es ara: " << bolt[legdragabb].nev << " - " << bolt[legdragabb].ar << endl << endl;

	cout << "20%-os aremeles utan:" << endl;
	for (i = 0; i < aruszam; i++)
	{
		bolt[i].ar *= 1.2;
		cout << setw(25) << bolt[i].nev << "\t" << bolt[i].ar << "\t" << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}