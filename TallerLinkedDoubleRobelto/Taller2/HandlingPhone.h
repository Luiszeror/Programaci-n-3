//
// Created by Esteban on 4/12/2023.
//

#ifndef TALLERLISTADOBLEENLAZADAC___HANDLINGPHONE_H
#define TALLERLISTADOBLEENLAZADAC___HANDLINGPHONE_H
#include "Phone.h"
#include "LinkedDouble.cpp"


class HandlingPhone : LinkedDouble<Phone>{

public:

    HandlingPhone();
    bool twoDigits(std::string);
    bool isDigit(std::string);
    bool isYear(std:: string);
    double utilLife(std:: string, std:: string );
    void addPhone(Phone phone, int op);
    bool findPhone(const string, Phone phone, int orden);
    bool getFirstLast(int op);
    void showPhone(const string);
    void deletePhone(const string);
    int sizePhone();
    std::vector<Phone> getPhones(bool sw);

    ~HandlingPhone() override;

private:

    LinkedDouble<Phone> linkedPhones;


};


#endif //TALLERLISTADOBLEENLAZADAC___HANDLINGPHONE_H
