#include "studentu_suvestine.h"

int main()
{
	vector<Studentas> studentai;
	cout << "Pasirinkite duomenu ivedimo buda: " << endl;
	cout << "0 - skaitymas is failo" << endl;
	cout << "1 - rankinis ivedimas" << endl;
	int x = -1;
	cin >> x;
	while (x != 1 && x != 0)
	{
		cout << "Nera tokio pasirinkimo. Iveskite teisinga skaiciu." << endl;
		cin >> x;
	};
	if (x == 0)
		SkaitymasIsFailo(studentai, "Studentai100000.txt");
	else
		RankinisIvedimas(studentai);

	system("pause");
}
