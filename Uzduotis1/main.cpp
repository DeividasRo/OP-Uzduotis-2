#include "studentu_suvestine.h"

int main()
{
	vector<Studentas> studentai, vargsiukai, moksliukai;
	duration<double> diff;
	int x;
	while (true)
	{
		cout << "\nPasirinkite norima atlikti veiksma: " << endl;
		cout << "1 - rankinis duomenu ivedimas" << endl;
		cout << "2 - generuoti duomenu faila" << endl;
		cout << "3 - isvesti apdorotus duomenis i failus" << endl;
		x = TinkamoSveikojoSkaiciausIvedimas();
		if (x == 1)
			RankinisIvedimas(studentai);
		else if (x == 2)
		{
			cout << "Iveskite norimu sugeneruoti duomenu failu namu darbu kieki." << endl;
			cin >> x;
			if (x > 0)
			{
				for (int i = 1000; i <= 10000000; i *= 10)
				{
					auto start = high_resolution_clock::now();
					GeneruotiDuomenuFaila(i, x);
					auto end = high_resolution_clock::now();
					diff = end - start;
					cout << i << " studentu failo kurimo laikas: " << diff.count() << " s" << endl;
				}
			}
		}
		else if (x == 3)
		{
			using namespace std::chrono;
			for (int i = 1000; i <= 10000000; i *= 10)
			{
				auto full_start = high_resolution_clock::now();
				cout << endl;

				auto start = high_resolution_clock::now();
				SkaitymasIsFailo(studentai, "studentai" + to_string(i) + ".txt");
				auto end = high_resolution_clock::now();
				diff = end - start;
				cout << i << " studentu duomenu nuskaitymo is failo laikas: " << diff.count() << " s" << endl;

				start = high_resolution_clock::now();
				PadalintiStudentusKategorijomis(studentai, vargsiukai, moksliukai);
				end = high_resolution_clock::now();
				diff = end - start;
				cout << i << " studentu  dalijimo i dvi kategorijas laikas: " << diff.count() << " s" << endl;

				start = high_resolution_clock::now();
				IsvedimasIFaila(vargsiukai, "vargsiukai" + to_string(i) + ".txt");
				end = high_resolution_clock::now();
				diff = end - start;
				cout << i << " studentu isvedimo i vargsiukai.txt faila laikas: " << diff.count() << " s" << endl;

				start = high_resolution_clock::now();
				IsvedimasIFaila(moksliukai, "moksliukai" + to_string(i) + ".txt");
				end = high_resolution_clock::now();
				diff = end - start;
				cout << i << " studentu isvedimo i moksliukai.txt faila laikas: " << diff.count() << " s" << endl;

				auto full_end = high_resolution_clock::now();
				diff = full_end - full_start;
				cout << i << " studentu testavimo bendras laikas: " << diff.count() << " s" << endl;
			}
		}
		else
			break;
	}

	system("pause");
	return 0;
}
