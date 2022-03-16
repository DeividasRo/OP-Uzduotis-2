#include "skaiciavimai.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::ifstream;
using std::left;
using std::ofstream;
using std::setprecision;
using std::setw;
using std::string;
using std::stringstream;
using std::to_string;
using std::vector;

struct Studentas
{
    string vardas, pavarde;
    vector<int> nd;
    int egz = 0;
    double galutinis_vid = 0;
    double galutinis_med = 0;
};

bool YraSveikasisSkaicius(string);
int TinkamoSveikojoSkaiciausIvedimas();
bool LygintiPagalPavardeDidejanciai(Studentas, Studentas);
void RusiuotiStudentusPagalPavarde(vector<Studentas> &);
void IsvedimasIKonsole(vector<Studentas>, string);
void IsvedimasIFaila(vector<Studentas> &, string);
void StudentoIvedimas(Studentas &);
void SkaitymasIsFailo(vector<Studentas> &, string);
void RankinisIvedimas(vector<Studentas> &);
void GeneruotiDuomenuFaila(int, int);
void PadalintiStudentusKategorijomis(vector<Studentas> &, vector<Studentas> &, vector<Studentas> &);