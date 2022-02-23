#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdlib.h>
#include <numeric>
#include <algorithm>
#include <time.h>
using namespace std;

struct Studentas
{
	string vardas, pavarde;
	vector<int> nd;
	int egz = 0;
	double galutinis = 0;
};

int SugeneruotiPazymi()
{
	return rand() % 11;
}

bool YraSveikasisSkaicius(string x) // tikrina ar visi eilutes simboliai yra skaitmenys
{
	if (!isdigit(x[0]) && x[0] != '-')
		return false;
	for (int i = 1; i < x.length(); i++)
	{
		if (!isdigit(x[i]))
			return false;
	}
	return true;
}

int TinkamoSveikojoSkaiciausIvedimas()
{
	string s;
	cin >> s;
	while (!YraSveikasisSkaicius(s))
	{
		cout << "Netinkama ivestis. Prasome ivesti sveikaji skaiciu: ";
		cin >> s;
	}
	return stoi(s);
}

void StudentoIvedimas(Studentas &s)
{
	cout << "Iveskite varda: ";
	cin >> s.vardas;
	cout << "Iveskite pavarde: ";
	cin >> s.pavarde;

	int x = 0;
	cout << "Pasirinkite pazymiu ivedimo buda: " << endl;
	cout << "0 - automatinis pazymiu ivedimas" << endl;
	cout << "1 - rankinis pazymiu ivedimas" << endl;
	cin >> x;
	if (x == 1) // pazymiu ivedimas rankiniu budu
	{
		cout << "\nSuveskite namu darbu pazymius. (Noredami nutraukti ivedima, iveskite neigiama arba didesni uz 10 skaiciu)" << endl;
		while (true)
		{
			cout << "Iveskite " << s.nd.size() + 1 << " pazymi: ";
			x = TinkamoSveikojoSkaiciausIvedimas();
			if (x >= 0 && x <= 10)
				s.nd.push_back(x);
			else if (s.nd.size() != 0)
				break;
		}
		cout << "Iveskite gauta egzamino rezultata: ";
		while (true)
		{
			x = TinkamoSveikojoSkaiciausIvedimas();
			if (x < 0)
				cout << "Egzamino rezultatas turi buti teigiamas: ";
			else if (x > 10)
				cout << "Egzamino rezultatas turi buti nuo 0 iki 10: ";
			else
				break;
		}
		s.egz = x;
	}
	else // pazymiu generavimas
	{
		cout << "Iveskite norimu sugeneruoti pazymiu kieki: " << endl;
		while (x <= 0)
		{
			x = TinkamoSveikojoSkaiciausIvedimas();
			if (x <= 0)
				cout << "Netinkama ivestis. Iveskite teigiama sveikaji skaiciu: ";
		}
		for (int i = 0; i < x; i++)
			s.nd.push_back(SugeneruotiPazymi());
		s.egz = SugeneruotiPazymi();
	}
}

void IvestiSkaiciavimoBuda(string &skaiciavimo_budas) // vartotojas paklausiamas iraso norima skaiciavimo buda (vidurki arba mediana)
{
	cout << "\nKokiu budu apskaiciuoti galutini bala?" << endl;
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

void GalutinioApskaiciavimasVidurkiu(Studentas &s)
{
	double pazymiu_suma = 0;
	pazymiu_suma = accumulate(s.nd.begin(), s.nd.end(), 0);
	s.galutinis = 0.4 * pazymiu_suma / s.nd.size() + 0.6 * s.egz;
}

void GalutinioApskaiciavimasMediana(Studentas &s)
{
	double mediana = 0;
	sort(s.nd.begin(), s.nd.end());
	if (s.nd.size() % 2 == 0)
		mediana = (s.nd[s.nd.size() / 2] + s.nd[s.nd.size() / 2 - 1]) / 2.0;
	else
		mediana = s.nd[s.nd.size() / 2];
	s.galutinis = 0.4 * mediana + 0.6 * s.egz;
}

void Isvedimas(vector<Studentas> studentai, string galutinis_budas)
{
	cout << "\n"
		 << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15)
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
	srand(time(NULL));
	vector<Studentas> studentai;
	string skaiciavimo_budas = "v";
	string testi_ivedima = "t";
	while (testi_ivedima == "t")
	{
		Studentas s;
		StudentoIvedimas(s);
		studentai.push_back(s);
		cout << "\nJei norite prideti dar viena studenta, irasykite 't': ";
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
