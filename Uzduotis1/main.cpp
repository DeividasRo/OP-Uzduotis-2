#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

struct Studentas
{
	string vardas, pavarde;
	vector<int> nd;
	int egz = 0;
	double galutinis;
};

bool YraSveikasisSkaicius(string x) // tikrina ar visi eilutes simboliai yra skaitmenys
{
	if (!isdigit(x[0]) && x[0] != '-') return false;
	for (int i = 1; i < x.length(); i++)
	{
		if (!isdigit(x[i]))
			return false;
	}
	return true;
}
void NetinkamosIvestiesPerspejimas()
{
	cout << "Netinkama ivestis. Prasome ivesti sveikaji skaiciu: ";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void TinkamoSveikojoSkaiciausIvedimas(string& x)
{
	cin >> x;
	while (!YraSveikasisSkaicius(x))
	{
		NetinkamosIvestiesPerspejimas();
		cin >> x;
	}
}

void StudentoIvedimas(Studentas& s)
{
	cout << "Iveskite varda: ";
	cin >> s.vardas;
	cout << "Iveskite pavarde: ";
	cin >> s.pavarde;
	cout << "Suveskite namu darbu pazymius. Noredami sustabdyti ivedima, iveskite neigiama skaiciu." << endl;
	string x = "0";
	while (stoi(x) >= 0 || s.nd.size() == 0)
	{
		cout << "Iveskite " << s.nd.size() + 1 << " pazymi: ";
		TinkamoSveikojoSkaiciausIvedimas(x);
		if (stoi(x) >= 0)
			s.nd.push_back(stoi(x)); // stoi - string paverciamas i int
	}
	cout << "Iveskite gauta egzamino rezultata: ";
	while (stoi(x) < 0)
	{
		TinkamoSveikojoSkaiciausIvedimas(x);
		if (stoi(x) < 0)
			cout << "Egzamino rezultatas turi buti teigiamas: ";
	}
	s.egz = stoi(x);
}

void IvestiSkaiciavimoBuda(string& skaiciavimo_budas) // vartotojas paklausiamas iraso norima skaiciavimo buda (vidurki arba mediana)
{
	cout << "Kokiu budu apskaiciuoti galutini bala?" << endl;
	cout << "v - Vidurkis" << endl;
	cout << "m - Mediana" << endl;
	cout << "Irasykite atitinkama trumpini: ";
	cin >> skaiciavimo_budas;
	while (skaiciavimo_budas != "v" && skaiciavimo_budas != "m")
	{
		cout << "Iveskite tinkama trumpini: ";
		cin >> skaiciavimo_budas;
	}
}

void GalutinioApskaiciavimasVidurkiu(Studentas& s)
{
	double pazymiu_suma = 0;
	for (int i = 0; i < s.nd.size(); i++)
	{
		pazymiu_suma += s.nd[i];
	}
	s.galutinis = 0.4 * pazymiu_suma / s.nd.size() + 0.6 * s.egz;
}

void GalutinioApskaiciavimasMediana(Studentas& s)
{
	double mediana = 0;
	for (int i = 0; i < s.nd.size(); i++)
		for (int j = i + 1; j < s.nd.size(); j++)
			if (s.nd[i] > s.nd[j])
			{
				int t = s.nd[i];
				s.nd[i] = s.nd[j];
				s.nd[j] = t;
			}
	if (s.nd.size() % 2 == 0)
		mediana = (s.nd[s.nd.size() / 2] + s.nd[s.nd.size() / 2 - 1]) / 2.0;
	else
		mediana = s.nd[s.nd.size() / 2];
	s.galutinis = 0.4 * mediana + 0.6 * s.egz;
}

void Isvedimas(vector<Studentas> studentai, string galutinis_budas)
{
	cout << "\n" << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15)
		<< galutinis_budas << endl;
	cout << string(45, '-') << endl;
	for (int i = 0; i < studentai.size(); i++)
	{
		cout << left << setw(15) << studentai[i].pavarde << setw(15) << studentai[i].vardas << fixed
			<< setprecision(2) << studentai[i].galutinis;
		cout << endl;
	}
}

int main()
{
	vector<Studentas> studentai;
	string skaiciavimo_budas = "v";
	string testi_ivedima = "taip";
	while (testi_ivedima == "taip")
	{
		Studentas s;
		StudentoIvedimas(s);
		studentai.push_back(s);
		cout << "Jei norite prideti dar viena studenta, irasykite zodi 'taip': ";
		cin >> testi_ivedima;
	}
	IvestiSkaiciavimoBuda(skaiciavimo_budas);

	if (skaiciavimo_budas == "m")
	{
		for (int i = 0; i < studentai.size(); i++)
		{
			GalutinioApskaiciavimasMediana(studentai[i]);
		}
		Isvedimas(studentai, "Galutinis (Med.)");
	}
	else
	{
		for (int i = 0; i < studentai.size(); i++)
		{
			GalutinioApskaiciavimasVidurkiu(studentai[i]);
		}
		Isvedimas(studentai, "Galutinis (Vid.)");
	}
	system("pause");
}