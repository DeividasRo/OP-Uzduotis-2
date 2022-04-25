#ifndef SKAICIAVIMAI_H
#define SKAICIAVIMAI_H

#include <random>
#include <chrono>
#include <numeric>
#include <vector>
#include <algorithm>
#include <list>

using namespace ::std::chrono;
using std::advance;
using std::list;
using std::mt19937;
using std::uniform_int_distribution;
using std::vector;

int GeneruotiPazymi();
double VidurkioApskaiciavimas(list<int>);
double MedianosApskaiciavimas(list<int>);

#endif