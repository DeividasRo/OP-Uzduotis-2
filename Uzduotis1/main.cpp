#include "studentu_suvestine.h"

int main()
{
	vector<Studentas> studentai;
	cout << "Pasirinkite duomenu ivedimo buda: " << endl;
	cout << "0 - skaitymas is failo" << endl;
	cout << "1 - rankinis ivedimas" << endl;
	int x = 0;
	cin >> x;
	if (x == 1)
		RankinisIvedimas(studentai);
	else
	{
		cout << "Iveskite norimu sugeneruoti duomenu failu namu darbu kiekius." << endl;
		cout << "1000 studentu failo nd kiekis: ";
		cin >> x;
		GeneruotiDuomenuFaila(1000, x);
		cout << "10000 studentu failo nd kiekis: ";
		cin >> x;
		GeneruotiDuomenuFaila(10000, x);
		cout << "100000 studentu failo nd kiekis: ";
		cin >> x;
		GeneruotiDuomenuFaila(100000, x);
		cout << "1000000 studentu failo nd kiekis: ";
		cin >> x;
		GeneruotiDuomenuFaila(1000000, x);
		cout << "10000000 studentu failo nd kiekis: ";
		cin >> x;
		GeneruotiDuomenuFaila(10000000, x);
		// SkaitymasIsFailo(studentai, "studentai10000.txt");
	}

	system("pause");
}
