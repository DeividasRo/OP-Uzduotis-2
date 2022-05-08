#include "skaiciavimai.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <algorithm>

using std::cin;
using std::cout;
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

class Studentas
{
private:
    string vardas_;
    string pavarde_;
    vector<int> nd_;
    int egzaminas_;
    double galutinis_vid_;
    double galutinis_med_;

public:
    Studentas() : egzaminas_(0), galutinis_vid_(0), galutinis_med_(0) {}

    // copy constructor
    Studentas(const Studentas &s)
    {
        vardas_ = s.vardas_;
        pavarde_ = s.pavarde_;
        galutinis_med_ = s.galutinis_med_;
        galutinis_vid_ = s.galutinis_vid_;
        egzaminas_ = s.egzaminas_;
        nd_ = s.nd_;
    }

    // assignment constructor
    Studentas operator=(const Studentas &s)
    {
        if (this == &s)
            return *this;
        vardas_ = s.vardas_;
        pavarde_ = s.pavarde_;
        galutinis_med_ = s.galutinis_med_;
        galutinis_vid_ = s.galutinis_vid_;
        egzaminas_ = s.egzaminas_;
        nd_ = s.nd_;
        return *this;
    }

    // destructor
    ~Studentas()
    {
        nd_.clear();
        nd_.shrink_to_fit();
    }

    void ReadData(stringstream &buffer, int paz_kiek)
    {
        string vardas, pavarde;
        int pazymys;
        buffer >> vardas >> pavarde;
        SetVardas(vardas);
        SetPavarde(pavarde);
        for (int i = 0; i < paz_kiek; i++)
        {
            buffer >> pazymys;
            PushToND(pazymys);
        }
        buffer >> pazymys;
        SetEgzaminas(pazymys);
        SetGalutinisVid(VidurkioApskaiciavimas(ND()) * 0.4 + Egzaminas() * 0.6);
    }

    // setters
    inline void SetVardas(string var) { vardas_ = var; }
    inline void SetPavarde(string pav) { pavarde_ = pav; }
    inline void SetEgzaminas(int egz) { egzaminas_ = egz; }
    inline double SetGalutinisVid(double vid) { return galutinis_vid_ = vid; }
    inline double SetGalutinisMed(double med) { return galutinis_med_ = med; }
    inline void PushToND(int paz) { return nd_.push_back(paz); }
    // getters
    inline string Vardas() const { return vardas_; }
    inline string Pavarde() const { return pavarde_; }
    inline int Egzaminas() const { return egzaminas_; }
    inline double GalutinisVid() const { return galutinis_vid_; }
    inline double GalutinisMed() const { return galutinis_med_; }
    inline vector<int> ND() const { return nd_; }
};

bool YraSveikasisSkaicius(string);
int TinkamoSveikojoSkaiciausIvedimas();
void RusiuotiPagalPavardeDidejanciai(vector<Studentas> &);
void RusiuotiPagalVidurkiDidejanciai(vector<Studentas> &);
void RusiuotiPagalVidurkiMazejanciai(vector<Studentas> &);
void IsvedimasIKonsole(vector<Studentas>, string);
void IsvedimasIFaila(vector<Studentas> &, string);
void StudentoIvedimas(Studentas &);
void SkaitymasIsFailo(vector<Studentas> &, string);
void RankinisIvedimas(vector<Studentas> &);
void GeneruotiDuomenuFaila(int, int);
void PadalintiStudentusKategorijomis(vector<Studentas> &, vector<Studentas> &, vector<Studentas> &);