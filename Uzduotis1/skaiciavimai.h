#ifndef SKAICIAVIMAI_H
#define SKAICIAVIMAI_H

#include <random>
#include <chrono>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace ::std::chrono;
using std::mt19937;
using std::uniform_int_distribution;
using std::vector;

int GeneruotiPazymi();
double VidurkioApskaiciavimas(vector<int>);
double MedianosApskaiciavimas(vector<int>);

#endif