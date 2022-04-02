#include "skaiciavimai.h"

uniform_int_distribution<int> dist(0, 10);
mt19937 mt(static_cast<long unsigned int>(high_resolution_clock::now().time_since_epoch().count()));

int GeneruotiPazymi()
{
    return dist(mt);
}

double VidurkioApskaiciavimas(vector<int> m)
{
    return accumulate(m.begin(), m.end(), 0) / m.size();
}

double MedianosApskaiciavimas(vector<int> m)
{
    sort(m.begin(), m.end());
    if (m.size() % 2 == 0)
        return (m[m.size() / 2] + m[m.size() / 2 - 1]) / 2.0;
    else
        return m[m.size() / 2];
}