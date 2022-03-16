#include "studentu_suvestine.h"

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

bool LygintiPagalPavardeDidejanciai(Studentas a, Studentas b)
{
    return a.pavarde < b.pavarde;
}

void RusiuotiStudentusPagalPavarde(vector<Studentas> &studentai)
{
    sort(studentai.begin(), studentai.end(), LygintiPagalPavardeDidejanciai);
}

void StudentoIvedimas(Studentas &s)
{
    cout << "Iveskite varda: ";
    cin >> s.vardas;
    cout << "Iveskite pavarde: ";
    cin >> s.pavarde;

    int x = -1;
    cout << "Pasirinkite pazymiu ivedimo buda: " << endl;
    cout << "1 - automatinis pazymiu ivedimas" << endl;
    cout << "2 - rankinis pazymiu ivedimas" << endl;
    x = TinkamoSveikojoSkaiciausIvedimas();
    while (x != 1 && x != 2)
    {
        cout << "Nera tokio pasirinkimo. Iveskite teisinga skaiciu." << endl;
        cin >> x;
    }
    if (x == 2) // pazymiu ivedimas rankiniu budu
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
        x = TinkamoSveikojoSkaiciausIvedimas();
        while (x <= 0)
        {
            x = TinkamoSveikojoSkaiciausIvedimas();
            if (x <= 0)
                cout << "Netinkama ivestis. Iveskite teigiama sveikaji skaiciu: ";
        }
        cout << "Pazymiai: ";
        for (int i = 0; i < x; i++)
        {
            s.nd.push_back(GeneruotiPazymi());
            cout << s.nd[i] << " ";
        }
        s.egz = GeneruotiPazymi();
        cout << "\nEgzaminas: " << s.egz << endl;
    }
}

void IsvedimasIKonsole(vector<Studentas> studentai, string galutinis_budas)
{
    stringstream my_buffer;
    if (galutinis_budas == "v")
    {
        my_buffer << "\n"
                  << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15)
                  << "Galutinis (Vid.)" << endl;
        my_buffer << string(45, '-') << endl;
        for (auto studentas : studentai)
        {
            my_buffer << left << setw(15) << studentas.pavarde << setw(15) << studentas.vardas << fixed
                      << setprecision(2) << studentas.galutinis_vid << endl;
        }
        cout << my_buffer.str();
    }
    else if (galutinis_budas == "m")
    {
        my_buffer << "\n"
                  << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15)
                  << "Galutinis (Med.)" << endl;
        my_buffer << string(45, '-') << endl;

        for (auto studentas : studentai)
        {
            my_buffer << left << setw(15) << studentas.pavarde << setw(15) << studentas.vardas << fixed
                      << setprecision(2) << studentas.galutinis_med << endl;
        }

        cout << my_buffer.str();
    }
    my_buffer.clear();
}

void IsvedimasIFaila(vector<Studentas> &studentai, string rez_failas)
{
    stringstream my_buffer;
    ofstream fo(rez_failas);
    my_buffer << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15)
              << "Galutinis (Vid.) Galutinis (Med.)" << endl;
    my_buffer << string(63, '-') << endl;
    for (auto studentas : studentai)
    {
        my_buffer << left << setw(15) << studentas.pavarde << setw(15) << studentas.vardas << setw(17) << fixed
                  << setprecision(2) << studentas.galutinis_vid << studentas.galutinis_med << endl;
    }
    fo << my_buffer.str();
    // cout << "Duomenys isvesti i " << rez_failas << " faila." << endl;
    fo.close();
    my_buffer.clear();
    studentai.clear();
    studentai.shrink_to_fit();
}

void SkaitymasIsFailo(vector<Studentas> &studentai, string ivesties_failas)
{
    int pazymiu_kiekis = -3;

    stringstream my_buffer;
    ifstream fi(ivesties_failas);

    my_buffer << fi.rdbuf();
    fi.close();

    string zodis;
    while (zodis != "Egz.")
    {
        my_buffer >> zodis;
        pazymiu_kiekis++;
    }

    while (my_buffer)
    {
        Studentas s;
        my_buffer >> s.vardas >> s.pavarde;
        if (s.vardas == "" && s.pavarde == "")
            break;
        for (int i = 0; i < pazymiu_kiekis; i++)
        {
            int paz;
            my_buffer >> paz;
            s.nd.push_back(paz);
        }
        my_buffer >> s.egz;
        s.galutinis_med = MedianosApskaiciavimas(s.nd) * 0.4 + s.egz * 0.6;
        s.galutinis_vid = VidurkioApskaiciavimas(s.nd) * 0.4 + s.egz * 0.6;
        studentai.push_back(s);
    }
    RusiuotiStudentusPagalPavarde(studentai);
}

void RankinisIvedimas(vector<Studentas> &studentai)
{
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
    RusiuotiStudentusPagalPavarde(studentai);

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

    if (skaiciavimo_budas == "m")
    {
        for (auto &s : studentai)
        {
            s.galutinis_med = MedianosApskaiciavimas(s.nd) * 0.4 + s.egz * 0.6;
        }
        IsvedimasIKonsole(studentai, "m");
    }
    else
    {
        for (auto &s : studentai)
        {
            s.galutinis_vid = VidurkioApskaiciavimas(s.nd) * 0.4 + s.egz * 0.6;
        }
        IsvedimasIKonsole(studentai, "v");
    }
}

void PadalintiStudentusKategorijomis(vector<Studentas> &studentai, vector<Studentas> &vargsiukai, vector<Studentas> &moksliukai)
{
    for (auto &s : studentai)
    {
        if (s.galutinis_vid < 5.00 && s.galutinis_med < 5.00)
            vargsiukai.push_back(s);
        else
            moksliukai.push_back(s);
    }
    studentai.clear();
    studentai.shrink_to_fit();
}

void GeneruotiDuomenuFaila(int studentu_kiekis, int nd_kiekis)
{
    stringstream my_buffer;
    ofstream fo("studentai" + to_string(studentu_kiekis) + ".txt");
    int (*genpazPtr)() = GeneruotiPazymi;

    my_buffer << "Vardas" << setw(10) << "Pavarde";
    for (int i = 0; i < nd_kiekis; i++)
        my_buffer << setw(10) << "ND" << i + 1;
    my_buffer << setw(10) << "Egz." << endl;

    for (int i = 0; i < studentu_kiekis; i++)
    {
        my_buffer << "Vardas" << i + 1 << setw(10) << "Pavarde" << i + 1;
        for (int j = 0; j < nd_kiekis + 1; j++)
            my_buffer << setw(10) << genpazPtr();
        my_buffer << endl;
    }
    fo << my_buffer.str();
    my_buffer.clear();
    fo.close();
}