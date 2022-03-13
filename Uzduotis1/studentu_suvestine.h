#include "skaiciavimai.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <fstream>
using namespace std;

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
void Isvedimas(vector<Studentas>, string);
void StudentoIvedimas(Studentas &);
void SkaitymasIsFailo(vector<Studentas> &, string);
void RankinisIvedimas(vector<Studentas> &);
void GeneruotiDuomenuFaila(int, int);