#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Studentas
{
	string vardas, pavarde;
	int nd_kiekis = 0;
	int* nd = new int[nd_kiekis + 1];
	int egz = 0;
	double galutinis;
};

void AtlaisvintiAtminti(vector<Studentas> studentai)
{
	for (auto& s : studentai)
	{
		delete[] s.nd;
	}
}

bool YraSveikasisSkaicius(string x) // tikrina ar visi eilutes simboliai yra skaitmenys
{
	for (int i = 0; i < x.length(); i++)
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
	while (x != "-1" && !YraSveikasisSkaicius(x))
	{
		NetinkamosIvestiesPerspejimas();
		cin >> x;
	}
}

void PridetiNDPazymi(Studentas& s, int pazymis)
{
	int naujas_nd_kiekis = s.nd_kiekis + 1;
	int* naujas_nd = new int[naujas_nd_kiekis];
	for (int i = 0; i < s.nd_kiekis; i++)
	{
		naujas_nd[i] = s.nd[i];
	}
	naujas_nd[naujas_nd_kiekis - 1] = pazymis;

	delete[] s.nd;
	s.nd_kiekis = naujas_nd_kiekis;
	s.nd = naujas_nd;
}

void StudentoIvedimas(Studentas& s)
{
	cout << "Iveskite varda: ";
	cin >> s.vardas;
	cout << "Iveskite pavarde: ";
	cin >> s.pavarde;
	cout << "Suveskite namu darbu pazymius. Noredami sustabdyti ivedima, irasykite skaiciu '-1'." << endl;
	string x;
	while (x != "-1" || s.nd_kiekis == 0)
	{
		cout << "Iveskite " << s.nd_kiekis + 1 << " pazymi: ";
		TinkamoSveikojoSkaiciausIvedimas(x);
		if (x != "-1")
			PridetiNDPazymi(s, stoi(x)); // stoi - string paverciamas i int
	}
	cout << "Iveskite gauta egzamino rezultata: ";
	TinkamoSveikojoSkaiciausIvedimas(x);
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
	for (int i = 0; i < s.nd_kiekis; i++)
	{
		pazymiu_suma += s.nd[i];
	}
	s.galutinis = 0.4 * pazymiu_suma / s.nd_kiekis + 0.6 * s.egz;
}

void GalutinioApskaiciavimasMediana(Studentas& s)
{
	double mediana = 0;
	for (int i = 0; i < s.nd_kiekis; i++)
		for (int j = i + 1; j < s.nd_kiekis; j++)
			if (s.nd[i] > s.nd[j])
			{
				int t = s.nd[i];
				s.nd[i] = s.nd[j];
				s.nd[j] = t;
			}
	if (s.nd_kiekis % 2 == 0)
		mediana = (s.nd[s.nd_kiekis / 2] + s.nd[s.nd_kiekis / 2 - 1]) / 2.0;
	else
		mediana = s.nd[s.nd_kiekis / 2];
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
	AtlaisvintiAtminti(studentai);
	system("pause");
}