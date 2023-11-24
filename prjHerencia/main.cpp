#include <iostream>

#include "EmployeeTemp.h"

using namespace std;

int main() {

    Employee *lola = new EmployeeTemp("343","Dolores Parra",1000000,"10/2/2021",MALE,"20/12/2022");

    cout<<lola->calcSalary()<<endl;

    cout<<*lola<<endl;

    delete(lola);

    return 0;
}
