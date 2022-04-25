#include "skaiciavimai.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <stdlib.h>
#include <fstream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::ifstream;
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
    list<int> nd;
    int egz = 0;
    double galutinis_vid = 0;
    double galutinis_med = 0;
};

bool YraSveikasisSkaicius(string);
int TinkamoSveikojoSkaiciausIvedimas();
void RusiuotiPagalPavardeDidejanciai(list<Studentas> &);
void RusiuotiPagalVidurkiDidejanciai(list<Studentas> &);
void RusiuotiPagalVidurkiMazejanciai(list<Studentas> &);
void IsvedimasIKonsole(list<Studentas>, string);
void IsvedimasIFaila(list<Studentas> &, string);
void StudentoIvedimas(Studentas &);
void SkaitymasIsFailo(list<Studentas> &, string);
void RankinisIvedimas(list<Studentas> &);
void GeneruotiDuomenuFaila(int, int);
void PadalintiStudentusKategorijomis(list<Studentas> &, list<Studentas> &, list<Studentas> &);