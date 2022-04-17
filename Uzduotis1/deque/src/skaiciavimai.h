#ifndef SKAICIAVIMAI_H
#define SKAICIAVIMAI_H

#include <random>
#include <chrono>
#include <numeric>
#include <deque>
#include <algorithm>

using namespace ::std::chrono;
using std::deque;
using std::mt19937;
using std::uniform_int_distribution;

int GeneruotiPazymi();
double VidurkioApskaiciavimas(deque<int>);
double MedianosApskaiciavimas(deque<int>);

#endif