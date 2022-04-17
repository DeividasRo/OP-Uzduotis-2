#include "studentu_suvestine.h"

int main()
{
	deque<Studentas> studentai, vargsiukai, moksliukai;
	duration<double> diff;
	int x;
	while (true)
	{
		cout << "\nPasirinkite norima atlikti veiksma: " << endl;
		cout << "0 - uzbaigti programos veikima" << endl;
		cout << "1 - rankinis duomenu ivedimas" << endl;
		cout << "2 - generuoti duomenu failus" << endl;
		cout << "3 - isvesti apdorotus duomenis i failus" << endl;
		x = TinkamoSveikojoSkaiciausIvedimas();
		if (x == 1)
			RankinisIvedimas(studentai);
		else if (x == 2)
		{
			int stud_kiek = 0, paz_kiek = 0;
			string check = "t";
			while (check == "t")
			{
				cout << "Iveskite norimo sugeneruoti duomenu failo studentu kieki: ";
				stud_kiek = TinkamoSveikojoSkaiciausIvedimas();
				cout << "Iveskite norimo sugeneruoti duomenu failo namu darbu kieki: ";
				paz_kiek = TinkamoSveikojoSkaiciausIvedimas();
				if (stud_kiek > 0)
				{

					auto start = high_resolution_clock::now();
					GeneruotiDuomenuFaila(stud_kiek, paz_kiek);
					auto end = high_resolution_clock::now();
					diff = end - start;
					cout << stud_kiek << " studentu failo kurimo laikas: " << diff.count() << " s" << endl;
				}
				cout << "Ar norite sugeneruoti dar viena faila [t/n]? " << endl;
				cin >> check;
			}
		}
		else if (x == 3)
		{
			string ivesties_failas, ivesties_failo_pav;
			int stud_kiekis = 0;
			while (true)
			{
				cout << "\nIveskite norimo apdoroti duomenu failo varda: ";
				cin >> ivesties_failo_pav;
				if (ivesties_failo_pav.substr(ivesties_failo_pav.length() - 4, 4) != ".txt") // galimybe ivesti failo varda be .txt pletinio
					ivesties_failas = ivesties_failo_pav + ".txt";
				else
					ivesties_failas = ivesties_failo_pav;
				ifstream fi(ivesties_failas);
				try
				{
					if (fi.fail())
						throw std::runtime_error("Nepavyko atidaryti duomenu failo.\n");
				}
				catch (std::exception &ex)
				{
					cout << ex.what();
					break;
				}
				stud_kiekis = stoi(ivesties_failas.substr(2, ivesties_failas.length() - 2));

				auto full_start = high_resolution_clock::now();
				cout << endl;

				auto start = high_resolution_clock::now();
				SkaitymasIsFailo(studentai, ivesties_failas);
				auto end = high_resolution_clock::now();
				diff = end - start;
				cout << stud_kiekis << " studentu duomenu nuskaitymo is failo laikas: " << diff.count() << " s\n";

				start = high_resolution_clock::now();
				PadalintiStudentusKategorijomis(studentai, vargsiukai, moksliukai);
				end = high_resolution_clock::now();
				diff = end - start;
				cout << stud_kiekis << " studentu dalijimo i dvi kategorijas laikas: " << diff.count() << " s\n";

				start = high_resolution_clock::now();
				IsvedimasIFaila(vargsiukai, "vargsiukai" + to_string(stud_kiekis) + ".txt");
				end = high_resolution_clock::now();
				diff = end - start;
				cout << stud_kiekis << " studentu isvedimo i vargsiukai.txt faila laikas: " << diff.count() << " s\n";

				start = high_resolution_clock::now();
				if (!moksliukai.empty())
					IsvedimasIFaila(moksliukai, "moksliukai" + to_string(stud_kiekis) + ".txt");
				else
					IsvedimasIFaila(studentai, "moksliukai" + to_string(stud_kiekis) + ".txt");
				end = high_resolution_clock::now();
				diff = end - start;
				cout << stud_kiekis << " studentu isvedimo i moksliukai.txt faila laikas: " << diff.count() << " s\n";

				auto full_end = high_resolution_clock::now();
				diff = full_end - full_start;
				cout << stud_kiekis << " studentu testavimo bendras laikas: " << diff.count() << " s\n";
			}
		}
		else
			break;
	}

	system("pause");
	return 0;
}
