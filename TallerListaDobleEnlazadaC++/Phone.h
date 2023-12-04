//
// Created by Esteban on 2/12/2023.
//

#ifndef TALLERLISTADOBLEENLAZADAC___PHONE_H
#define TALLERLISTADOBLEENLAZADAC___PHONE_H

#include <string>
#include <ostream>

using namespace std;


class Phone {

public:
    Phone();

    Phone(const string &id, const string &markName, const string &ram, const string &rom, bool is5G,
          const string &battery, const string &year, double utilLife);

    const string &getId() const;

    void setId(const string &id);

    const string &getMarkName() const;

    void setMarkName(const string &markName);

    const string &getRam() const;

    void setRam(const string &ram);

    const string &getRom() const;

    void setRom(const string &rom);

    bool isIs5G() const;

    void setIs5G(bool is5G);

    const string &getBattery() const;

    void setBattery(const string &battery);

    const string &getYear() const;

    void setYear(const string &year);

    double getUtilLife() const;

    void setUtilLife(double utilLife);

    friend ostream &operator<<(ostream &os, const Phone &phone);

    virtual ~Phone();

private:

    string id;
    string markName;
    string RAM;
    string ROM;
    bool is5G;
    string battery;
    string year;
    double utilLife;


};


#endif //TALLERLISTADOBLEENLAZADAC___PHONE_H
