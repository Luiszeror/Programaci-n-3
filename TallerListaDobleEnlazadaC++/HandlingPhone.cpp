//
// Created by Esteban on 4/12/2023.
//

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include "HandlingPhone.h"
#include "LinkedDouble.h"

HandlingPhone::HandlingPhone() {}


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
            std::cerr << "Error: Año no válido o igual a cero." << std::endl;
            return 0.0;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Conversión de string a número fallida." << std::endl;
        return 0.0;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Valor fuera de rango." << std::endl;
        return 0.0;
    }
}














