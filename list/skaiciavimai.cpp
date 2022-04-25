#include "skaiciavimai.h"

uniform_int_distribution<int> dist(0, 10);
mt19937 mt(static_cast<long unsigned int>(high_resolution_clock::now().time_since_epoch().count()));

int GeneruotiPazymi()
{
    return dist(mt);
}

double VidurkioApskaiciavimas(list<int> m)
{
    return accumulate(m.begin(), m.end(), 0) / m.size();
}

double MedianosApskaiciavimas(list<int> m)
{
    m.sort();
    std::list<int>::iterator it = m.begin();
    advance(it, m.size() / 2);
    if (m.size() % 2 == 0)
        return (*it + *(--it)) / 2.0;
    else
        return *it;
}