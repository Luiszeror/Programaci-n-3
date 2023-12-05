//
// Created by Esteban on 4/12/2023.
//

#ifndef TALLERLISTADOBLEENLAZADAC___HANDLINGPHONE_H
#define TALLERLISTADOBLEENLAZADAC___HANDLINGPHONE_H
#include "Phone.h"
#include "LinkedDouble.cpp"


class HandlingPhone {

public:

    HandlingPhone();
    bool twoDigits(std::string);
    bool isDigit(std::string);
    bool isYear(std:: string);
    double utilLife(std:: string, std:: string );

private:

    LinkedDouble<Phone> linkedPhones;


};


#endif //TALLERLISTADOBLEENLAZADAC___HANDLINGPHONE_H
