#include "skaiciavimai.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <deque>

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::fixed;
using std::ifstream;
using std::iter_swap;
using std::left;
using std::next;
using std::ofstream;
using std::setprecision;
using std::setw;
using std::string;
using std::stringstream;
using std::to_string;

struct Studentas
{
    string vardas, pavarde;
    deque<int> nd;
    int egz = 0;
    double galutinis_vid = 0;
    double galutinis_med = 0;
};

bool YraSveikasisSkaicius(string);
int TinkamoSveikojoSkaiciausIvedimas();
void RusiuotiPagalPavardeDidejanciai(deque<Studentas> &);
void RusiuotiPagalVidurkiDidejanciai(deque<Studentas> &);
void RusiuotiPagalVidurkiMazejanciai(deque<Studentas> &);
void IsvedimasIKonsole(deque<Studentas>, string);
void IsvedimasIFaila(deque<Studentas> &, string);
void StudentoIvedimas(Studentas &);
void SkaitymasIsFailo(deque<Studentas> &, string);
void RankinisIvedimas(deque<Studentas> &);
void GeneruotiDuomenuFaila(int, int);
void PadalintiStudentusKategorijomis(deque<Studentas> &, deque<Studentas> &, deque<Studentas> &);