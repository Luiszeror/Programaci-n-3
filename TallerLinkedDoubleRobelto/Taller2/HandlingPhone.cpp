//
// Created by Esteban on 4/12/2023.
//

#include <string>
#include <iostream>
#include "HandlingPhone.h"
#include "LinkedDouble.h"
#include "Phone.h"

HandlingPhone::HandlingPhone():LinkedDouble<Phone>(){

}


bool HandlingPhone::twoDigits(std::string input) {
    if (input.empty()) {
        return false;
    }

    int digitCount = 0;

    for (char c : input) {
        if (isdigit(c)) {
            digitCount++;

            if (digitCount == 2) {
                return true;
            }
        } else if (isalpha(c)) {
            return false;
        } else {
            digitCount++;
        }
    }

    return digitCount == 1 || digitCount == 2;
}

bool HandlingPhone::isDigit(std::string input) {
    for (char c : input) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

bool HandlingPhone::isYear(std::string input) {
    if (input.length() != 4) {
        return false;
    }

    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

double HandlingPhone::utilLife(std::string year, std::string battery) {
    try {
        int yearValue = std::stoi(year);
        double batteryValue = std::stod(battery);

        if (yearValue > 0) {
            return batteryValue / yearValue;

        } else {
            std::cerr << "Error: Anio no válido o igual a cero." << std::endl;
            return 0.0;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Conversion de string a número fallida." << std::endl;
        return 0.0;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Valor fuera de rango." << std::endl;
        return 0.0;
    }
}

std::vector<Phone> HandlingPhone::getPhones(bool sw) {
    if (getList(sw).empty()) {

    } else {

        return getList(sw);
    }

}

void HandlingPhone::addPhone(Phone phone, int op) {
    if (findInfo(phone.getId()) != nullptr) {
        std::cerr << "\nEl telefono con ese  ID " << phone.getId() << " ya existe." << std::endl;
    } else {
        if(op==1){
            addNodeFirst(phone);
        }else if(op==2){
            addNodeLast(phone);
        }else if(op==3){
            addNodeSorted(phone);
        }
    }
}

bool HandlingPhone::findPhone(const string encontrar, Phone phone, int orden) {

    if(findInfo(encontrar) != nullptr){
        if(orden==1){
            addNodeBeforeTo(findNode(encontrar), phone);

        }else if(orden ==2){
            addAfterTo(findNode(encontrar), phone);

        }
    }else{
        cerr<<"\nEl id no corresponde a ningun dispositivo\n";
    }

    return false;
}

bool HandlingPhone::getFirstLast(int op) {

    if(getList(true).empty()){
        cerr <<"\nLa lista esta vacia";
    }else{
        if(op==1){
            cout<<getFirst();
        }else{
            cout<<getLast();
        }

    }

    return false;
}

void HandlingPhone::showPhone(const string encontrar) {

    if(findInfo(encontrar) != nullptr){

        cout<<getObjectById(encontrar);
    }else{
        cerr<<"\nEl id no corresponde a ningun dispositivo\n";
    }

}

void HandlingPhone::deletePhone(const string encontrar) {

    if(findInfo(encontrar) != nullptr){

        deleteNodeById(encontrar);
        cout<<"\nDispositivo eliminado exitosamente"<<endl;
    }else{
        cerr<<"\nEl id no corresponde a ningun dispositivo\n";
    }

}

int HandlingPhone::sizePhone() {
    return getSize();
}

HandlingPhone::~HandlingPhone() {

}
