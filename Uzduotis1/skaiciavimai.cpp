#include "skaiciavimai.h"

uniform_int_distribution<int> dist(0, 10);
mt19937 mt(static_cast<long unsigned int>(high_resolution_clock::now().time_since_epoch().count()));

int GeneruotiPazymi()
{
    return dist(mt);
}

double VidurkioApskaiciavimas(vector<int> m)
{
    double pazymiu_suma = 0;
    pazymiu_suma = accumulate(m.begin(), m.end(), 0);
    return pazymiu_suma / m.size();
}

double MedianosApskaiciavimas(vector<int> m)
{
    double mediana = 0;
    sort(m.begin(), m.end());
    if (m.size() % 2 == 0)
        mediana = (m[m.size() / 2] + m[m.size() / 2 - 1]) / 2.0;
    else
        mediana = m[m.size() / 2];
    return mediana;
}