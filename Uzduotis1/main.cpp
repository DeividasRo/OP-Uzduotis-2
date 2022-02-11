#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

const int N = 3;

struct Studentas
{
	string vardas, pavarde;
	int nd[N] = { 0 };
	int egz = 0;
	double galutinis_vid;
};

bool YraSveikasisSkaicius(string x)
{
	for (int i = 0; i < x.length(); i++)
	{
		if (!isdigit(x[i]))
			return false;
	}
	return true;
}

void Ivedimas(Studentas& temp)
{
	cout << "Iveskite varda: ";
	cin >> temp.vardas;
	cout << "Iveskite pavarde: ";
	cin >> temp.pavarde;
	for (int i = 0; i < N; i++)
	{
		cout << "Iveskite " << i + 1 << " pazymi: ";
		string x;
		cin >> x;
		while (!YraSveikasisSkaicius(x))
		{
			cout << "Netinkama ivestis. Prasome ivesti sveikaji skaiciu:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> x;
		}
		temp.nd[i] = stoi(x);
	}
	cout << "Iveskite gauta egzamino rezultata: ";
	cin >> temp.egz;
}

void GalutinioVidurkioApskaiciavimas(Studentas& temp)
{
	double pazymiu_suma = 0;
	for (int i = 0; i < N; i++)
	{
		pazymiu_suma += temp.nd[i];
	}
	temp.galutinis_vid = 0.4 * pazymiu_suma / N + 0.6 * temp.egz;
}

void Isvedimas(vector<Studentas> studentai)
{
	cout << "\n" << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15)
		<< "Galutinis (Vid.)" << endl;
	cout << string(45, '-') << endl;
	for (int i = 0; i < studentai.size(); i++)
	{
		cout << left << setw(15) << studentai[i].pavarde << setw(15) << studentai[i].vardas << fixed
			<< setprecision(2) << studentai[i].galutinis_vid;
		cout << endl;
	}
}

int main()
{
	vector<Studentas> studentai;
	string testi_ivedima = "taip";
	while (testi_ivedima == "taip")
	{
		Studentas s;
		Ivedimas(s);
		studentai.push_back(s);
		cout << "Jei norite prideti dar viena studenta, irasykite zodi 'taip': ";
		cin >> testi_ivedima;
	}

	for (int i = 0; i < studentai.size(); i++)
	{
		GalutinioVidurkioApskaiciavimas(studentai[i]);
	}

	Isvedimas(studentai);

	system("pause");
}