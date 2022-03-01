#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <numeric>
#include <algorithm>
#include <chrono>
#include <random>
#include <fstream>
using namespace std;

struct Studentas
{
	string vardas, pavarde;
	vector<int> nd;
	int egz = 0;
	double galutinis_vid = 0;
	double galutinis_med = 0;
};

int SugeneruotiPazymi()
{
	mt19937 mt(static_cast<long unsigned int>(chrono::high_resolution_clock::now().time_since_epoch().count()));
	uniform_int_distribution<int> dist(0, 10);
	return dist(mt);
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
	s.galutinis_vid = 0.4 * pazymiu_suma / s.nd.size() + 0.6 * s.egz;
}

void GalutinioApskaiciavimasMediana(Studentas &s)
{
	double mediana = 0;
	sort(s.nd.begin(), s.nd.end());
	if (s.nd.size() % 2 == 0)
		mediana = (s.nd[s.nd.size() / 2] + s.nd[s.nd.size() / 2 - 1]) / 2.0;
	else
		mediana = s.nd[s.nd.size() / 2];
	s.galutinis_med = 0.4 * mediana + 0.6 * s.egz;
}

string bufer_nusk(string read_name)
{
	vector<string> splited;
	string line;
	stringstream my_buffer;

	ifstream open_f(read_name);
	my_buffer << open_f.rdbuf();
	open_f.close();
	while (my_buffer)
	{
		if (!my_buffer.eof())
		{
			getline(my_buffer, line);
			splited.push_back(line);
		}
		else
			break;
	}
	string output;
	for (std::string &a : splited)
		(a.compare(*splited.rbegin()) != 0)
			? output += a + "\n"
			: output += a;
	splited.clear();
	return output;
}

void SugeneruotiVardaPavarde(Studentas &s)
{
	mt19937 mt(static_cast<long unsigned int>(chrono::high_resolution_clock::now().time_since_epoch().count()));
	uniform_int_distribution<int> dist(0, 9);

	string vardai[10] = {"Irma", "Alma", "Irena", "Egle", "Jolanta", "Petras", "Jonas", "Ignas", "Darius", "Simas"};
	string pavardes_m[10] = {"Pavardaite1", "Pavardaite2", "Pavardaite3", "Pavardaite4", "Pavardaite5", "Pavardaite6", "Pavardaite7", "Pavardaite8", "Pavardaite9", "Pavardaite10"};
	string pavardes_v[] = {"Pavardenis1", "Pavardenis2", "Pavardenis3", "Pavardenis4", "Pavardenis5", "Pavardenis6", "Pavardenis7", "Pavardenis8", "Pavardenis9", "Pavardenis10"};

	s.vardas = vardai[dist(mt)];
	switch (*s.vardas.rbegin())
	{
	case 's':
		s.pavarde = pavardes_v[dist(mt)];
		break;
	default:
		s.pavarde = pavardes_m[dist(mt)];
		break;
	};
}

bool LygintiPagalVardaDidejanciai(Studentas a, Studentas b)
{
	return a.vardas < b.vardas;
}

void RusiuotiPagalVarda(vector<Studentas> &studentai)
{
	sort(studentai.begin(), studentai.end(), LygintiPagalVardaDidejanciai);
}

void StudentoIvedimas(Studentas &s)

{
	cout << "Iveskite varda: ";
	cin >> s.vardas;
	cout << "Iveskite pavarde: ";
	cin >> s.pavarde;

	int x = -1;
	cout << "Pasirinkite pazymiu ivedimo buda: " << endl;
	cout << "0 - automatinis pazymiu ivedimas" << endl;
	cout << "1 - rankinis pazymiu ivedimas" << endl;
	while (x != 1 && x != 0)
	{
		cout << "Nera tokio pasirinkimo. Iveskite teisinga skaiciu." << endl;
		cin >> x;
	}
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
		cout << "Iveskite norimu sugeneruoti pazymiu kieki: ";
		while (x <= 0)
		{
			x = TinkamoSveikojoSkaiciausIvedimas();
			if (x <= 0)
				cout << "Netinkama ivestis. Iveskite teigiama sveikaji skaiciu: ";
		}
		cout << "Pazymiai: ";
		for (int i = 0; i < x; i++)
		{
			s.nd.push_back(SugeneruotiPazymi());
			cout << s.nd[i] << " ";
		}
		s.egz = SugeneruotiPazymi();
		cout << "\nEgzaminas: " << s.egz << endl;
	}
}

void Isvedimas(vector<Studentas> studentai, string galutinis_budas)
{
	if (galutinis_budas == "v")
	{
		cout << "\n"
			 << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15)
			 << "Galutinis (Vid.)" << endl;
		cout << string(45, '-') << endl;
		for (int i = 0; i < studentai.size(); i++)
		{
			cout << left << setw(15) << studentai[i].pavarde << setw(15) << studentai[i].vardas << fixed
				 << setprecision(2) << studentai[i].galutinis_vid;
			cout << endl;
		}
	}
	else if (galutinis_budas == "m")
	{
		cout << "\n"
			 << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15)
			 << "Galutinis (Med.)" << endl;
		cout << string(45, '-') << endl;
		for (int i = 0; i < studentai.size(); i++)
		{
			cout << left << setw(15) << studentai[i].pavarde << setw(15) << studentai[i].vardas << fixed
				 << setprecision(2) << studentai[i].galutinis_med;
			cout << endl;
		}
	}
	else
	{
		cout << "\n"
			 << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15)
			 << "Galutinis (Vid.) Galutinis (Med.)" << endl;
		cout << string(60, '-') << endl;
		for (int i = 0; i < studentai.size(); i++)
		{
			cout << left << setw(15) << studentai[i].pavarde << setw(15) << studentai[i].vardas << setw(17) << fixed
				 << setprecision(2) << studentai[i].galutinis_vid << studentai[i].galutinis_med;
			cout << endl;
		}
	}
}

void SkaitymasIsFailo()
{
	vector<Studentas> studentai;
	string duomenys = bufer_nusk("Studentai10000.txt");
	size_t pask_nd_poz = duomenys.find_last_of("ND");
	int pazymiu_kiekis = stoi(duomenys.substr(pask_nd_poz + 1, duomenys.find_first_of("Egz.") - pask_nd_poz - 1));

	duomenys.erase(0, duomenys.find_first_of("Egz.") + 4);

	istringstream iss(duomenys);
	while (iss)
	{
		Studentas s;
		iss >> s.vardas >> s.pavarde;
		SugeneruotiVardaPavarde(s);
		for (int i = 0; i < pazymiu_kiekis; i++)
		{
			int paz;
			iss >> paz;
			s.nd.push_back(paz);
		}
		iss >> s.egz;
		GalutinioApskaiciavimasMediana(s);
		GalutinioApskaiciavimasVidurkiu(s);
		studentai.push_back(s);
	}
	RusiuotiPagalVarda(studentai);
	Isvedimas(studentai, "");
}

void RankinisIvedimas()
{
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
		Isvedimas(studentai, "m");
	}
	else
	{
		for (int i = 0; i < studentai.size(); i++)
		{
			GalutinioApskaiciavimasVidurkiu(studentai[i]);
		}
		Isvedimas(studentai, "v");
	}
}

int main()
{
	srand(time(NULL));
	cout << "Pasirinkite duomenu ivedimo buda: " << endl;
	cout << "0 - skaitymas is failo" << endl;
	cout << "1 - rankinis ivedimas" << endl;
	int x = -1;
	while (x != 1 && x != 0)
	{
		cout << "Nera tokio pasirinkimo. Iveskite teisinga skaiciu." << endl;
		cin >> x;
	};
	if (x == 0)
		SkaitymasIsFailo();
	else
		RankinisIvedimas();
	system("pause");
}
