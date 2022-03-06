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

bool LygintiPagalPavardeDidejanciai(Studentas a, Studentas b)
{
    return a.pavarde < b.pavarde;
}

void RusiuotiStudentusPagalPavarde(vector<Studentas> &studentai)
{
    sort(studentai.begin(), studentai.end(), LygintiPagalPavardeDidejanciai);
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

    int x = -1;
    cout << "Pasirinkite pazymiu ivedimo buda: " << endl;
    cout << "0 - automatinis pazymiu ivedimas" << endl;
    cout << "1 - rankinis pazymiu ivedimas" << endl;
    cin >> x;
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
    else
    {
        ofstream open_of("Rezultatai.txt");
        my_buffer << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15)
                  << "Galutinis (Vid.) Galutinis (Med.)" << endl;
        my_buffer << string(63, '-') << endl;
        for (auto studentas : studentai)
        {
            my_buffer << left << setw(15) << studentas.pavarde << setw(15) << studentas.vardas << setw(17) << fixed
                      << setprecision(2) << studentas.galutinis_vid << studentas.galutinis_med << endl;
        }
        open_of << my_buffer.str();
        cout << "Duomenys isvesti i Rezultatai.txt faila." << endl;
    }
    my_buffer.clear();
}

void SkaitymasIsFailo(vector<Studentas> &studentai, string failo_vardas)
{
    int pazymiu_kiekis = -3;

    stringstream my_buffer;
    ifstream open_if(failo_vardas);
    try
    {
        if (open_if.fail())
            throw runtime_error("Nepavyko atidaryti duomenu failo.");
    }
    catch (exception &ex)
    {
        cout << ex.what();
        exit(0);
    }
    my_buffer << open_if.rdbuf();
    open_if.close();

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
    Isvedimas(studentai, "");
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
        Isvedimas(studentai, "m");
    }
    else
    {
        for (auto &s : studentai)
        {
            s.galutinis_vid = VidurkioApskaiciavimas(s.nd) * 0.4 + s.egz * 0.6;
        }
        Isvedimas(studentai, "v");
    }
}
