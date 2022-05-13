#ifndef STUDENTAS_H
#define STUDENTAS_H

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
using std::istream;
using std::iter_swap;
using std::left;
using std::next;
using std::ofstream;
using std::ostream;
using std::setprecision;
using std::setw;
using std::string;
using std::stringstream;
using std::to_string;

class Zmogus
{
protected:
    string vardas_;
    string pavarde_;

public:
    inline void SetVardas(string var) { vardas_ = var; }
    inline void SetPavarde(string pav) { pavarde_ = pav; }
    virtual inline string Vardas() const = 0;
    virtual inline string Pavarde() const = 0;
};

class Studentas : public Zmogus
{
private:
    vector<int> nd_;
    int egzaminas_;
    double galutinis_vid_;
    double galutinis_med_;

public:
    static int pazymiu_kiekis;
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

    friend istream &operator>>(istream &in, Studentas &s)
    {
        in >> s.vardas_ >> s.pavarde_;
        for (int i = 0; i < s.pazymiu_kiekis; i++)
        {
            int paz;
            in >> paz;
            s.nd_.push_back(paz);
        };
        in >> s.egzaminas_;
        s.SetGalutinisVid(VidurkioApskaiciavimas(s.ND()) * 0.4 + s.Egzaminas() * 0.6);
        return in;
    }

    friend ostream &operator<<(ostream &out, Studentas const &s)
    {
        out << left << setw(15) << s.Pavarde() << setw(15) << s.Vardas() << setw(17) << fixed
            << setprecision(2) << s.GalutinisVid() << endl;
        return out;
    }

    // setters
    inline void SetEgzaminas(int egz) { egzaminas_ = egz; }
    inline void SetGalutinisVid(double vid) { galutinis_vid_ = vid; }
    inline void SetGalutinisMed(double med) { galutinis_med_ = med; }
    inline void PushToND(int paz) { nd_.push_back(paz); }
    inline void static SetPazKiek(int kiek) { pazymiu_kiekis = kiek; }
    // getters
    inline string Vardas() const { return vardas_; }
    inline string Pavarde() const { return pavarde_; }
    inline int Egzaminas() const { return egzaminas_; }
    inline double GalutinisVid() const { return galutinis_vid_; }
    inline double GalutinisMed() const { return galutinis_med_; }
    inline vector<int> ND() const { return nd_; }
    inline int ND(int i) const { return nd_[i]; }
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

#endif