//
// Created by Esteban on 2/12/2023.
//

#include "Phone.h"

Phone::Phone() {}

Phone::Phone(const string &id, const string &markName, const string &ram, const string &rom, bool is5G,
             const string &battery, const string &year, double utilLife) : id(id), markName(markName), RAM(ram),
                                                                           ROM(rom), is5G(is5G), battery(battery),
                                                                           year(year), utilLife(utilLife) {}

const string &Phone::getId() const {
    return id;
}

void Phone::setId(const string &id) {
    Phone::id = id;
}

const string &Phone::getMarkName() const {
    return markName;
}

void Phone::setMarkName(const string &markName) {
    Phone::markName = markName;
}

const string &Phone::getRam() const {
    return RAM;
}

void Phone::setRam(const string &ram) {
    RAM = ram;
}

const string &Phone::getRom() const {
    return ROM;
}

void Phone::setRom(const string &rom) {
    ROM = rom;
}

bool Phone::isIs5G() const {
    return is5G;
}

void Phone::setIs5G(bool is5G) {
    Phone::is5G = is5G;
}

const string &Phone::getBattery() const {
    return battery;
}

void Phone::setBattery(const string &battery) {
    Phone::battery = battery;
}

const string &Phone::getYear() const {
    return year;
}

void Phone::setYear(const string &year) {
    Phone::year = year;
}

double Phone::getUtilLife() const {
    return utilLife;
}

void Phone::setUtilLife(double utilLife) {
    Phone::utilLife = utilLife;
}

ostream &operator<<(ostream &os, const Phone &phone) {
    string a;
    if(phone.is5G==true){
        a="Si";
    }else{
        a="No";
    }
    os <<"\n------------------------------------------"
         "\nLas Especificaciones del telefono son: \n"
       <<"Id del telefono: " << phone.id<<"\n"
       <<"Nombre de la marca: " << phone.markName<<"\n"
       <<"Memoria RAM: " << phone.RAM <<"GBs\n"
       <<"Almacenamiento (ROM): " << phone.ROM<<"GBs\n"
       <<"Compabilidad 5G: " << a <<"\n"
       <<"Capacidad de la bateria: " << phone.battery <<"mAh\n"
       <<"Anio de lanzamiento: " << phone.year<<"\n"
       <<"Vida util de la bateria: "<< phone.utilLife<<" anio(s)\n"
       <<"\n------------------------------------------";
    return os;
}

Phone::~Phone() {

}
