#include <iostream>
#include <limits>
#include "Phone.h"
#include "HandlingPhone.h"
#include "LinkedDouble.h"



using namespace std;

Phone createObject();


int main() {
    int op=0, op3=0;
    Phone myPhone;
    HandlingPhone hP;
    string find, delet;
    LinkedDouble<Phone>* linkedDouble= new LinkedDouble<Phone>();


    cout << "-------------------------------------------------------\n"
            "Bienvenido al sistema de gestion de telefonos celulares\n";

    while (op != 5) {
        cout <<"-------------------------------------------------------\n"
        "Digite una opcion:\n1. Agregar Telefono\n2. Ver Telefonos\n3. Buscar Telefono\n4. Eliminar Telefono\n5. Salir";

        try {
            cin >> op;

            if (cin.fail()) {
                throw runtime_error("Error: Entrada no valida. Ingrese un numero.");
            }
            int op2=0;

            switch (op) {
                case 1:
                    cout << "\nDigite una opcion para agregar telefono: "
                         << "\n1. Agregar primero\n2. Agregar ultimo\n3. Agregar antes de un telefono"
                         << "\n4. Agregar despues de un telefono\n5. Agregar en orden\n6. Volver";

                    try {
                        cin >> op2;

                        if (cin.fail()) {
                            throw runtime_error("Error: Entrada no valida. Ingrese un numero.");
                        }

                        switch (op2) {
                            case 1:

                                cout <<"\nAgregar Primero: ";
                                myPhone=createObject();
                                cout<< myPhone;

                                break;
                            case 2:
                                cout << "\nAgregar Ultimo: ";
                                myPhone = createObject();
                                cout << myPhone;
                                break;

                                break;
                            case 3:
                                cout <<"\nAgregar antes de: ";
                                myPhone=createObject();
                                cout<< myPhone;
                                break;
                            case 4:
                                cout <<"\nAgregar despues de: ";
                                myPhone=createObject();
                                cout<< myPhone;
                                break;
                            case 5:
                                cout <<"\nAgregar Primero: ";
                                myPhone=createObject();
                                cout<< myPhone;
                                break;
                            case 6:
                                // Volver
                                continue;
                            default:
                                cout << "Digite una opcion valida" << endl;
                        }
                    } catch (const exception& e) {
                        cout << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    break;
                case 2:

                    cout << "Seleccione una opcion: \n1. Ver primero\n2. Ver Ultimo\n3. Ver Lista descendente\n4. Ver lista ascendete\n5. Volver";
                    try {
                        cin >> op3;

                        if (cin.fail()) {
                            throw runtime_error("Error: Entrada no valida. Ingrese un numero.");
                        }

                        switch(op3){

                            case 1:

                                cout << "Ver Primero: ";

                                break;

                            case 2:
                                cout << "Ver Ultimo: ";

                                break;

                            case 3:
                                cout << "Ver Lista descendente: ";

                                break;

                            case 4:
                                cout << "Ver Lista ascendente: ";

                                break;

                            case 5:
                                continue;


                            default:
                                cout <<"Ingrese un valor valido";

                        }

                    } catch (const exception& e) {
                        cout << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    break;
                case 3:

                    cout <<"Buscar telefono:\nIngrese el id del telefono a buscar:";
                    cin >> find;

                    break;
                case 4:
                    cout <<"Eliminar telefono:\nIngrese el id del telefono a eliminar:";
                    cin >> delet;

                    break;
                case 5:

                    cout << "Hasta la proxima :)";

                    break;
                default:
                    cout << "Digite una opcion valida" << endl;
                    getchar();getchar();
            }
        } catch (const exception& e) {
            cout << "Asegurese de ingresar un valor numero relacionado a las opciones" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getchar();
        }
    }



    return 0;
}

Phone createObject() {
    Phone phone;
    HandlingPhone hP;


    string id, markName, RAM, ROM, battery, year;
    bool is5G;
    double utillife;

    cout <<"\nIngrese el ID del telefono: ";

    while (!(cin >> id) || !hP.twoDigits(id)) {
        cout << "Ingrese un ID valido (valor numerico): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    id=(id);

    cout <<"\nIngrese el nombre de la marca del telefono: ";
    while (!(cin >> markName) || !hP.isDigit(markName)) {
        cout << "Ingrese una marca valida (Sin numeros o simbolos): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    markName=(markName);

    cout <<"\nIngrese la memoria RAM del telefono: ";
    while (!(cin >> RAM) || !hP.twoDigits(RAM)) {
        cout << "Ingrese una RAM valida (valor numerico en GBs): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    RAM=(RAM);

    cout <<"\nIngrese la capacidad de almacenamiento (ROM) del telefono: ";
    while (!(cin >> ROM) || !hP.twoDigits(ROM)) {
        cout << "Ingrese una ROM valida (valor numerico en GBS): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    ROM=(ROM);


    cout <<"\nEl telefono tiene compatibilidad en 5G?:\n1.Si\n2.No ";
    string G5;
    while (!(cin >> G5) || (G5 != "1" && G5 != "2")) {
        cout << "Entrada no valida. Por favor, ingrese 1 o 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if(G5=="Si") {
        is5G=(true);
    }else{
        is5G=(false);
    }

    cout <<"\nIngrese la capacidad de bateria del telefono (mAh): ";
    while (!(cin >> battery) || !hP.twoDigits(battery)) {
        cout << "Ingrese una capacidad valida (valor numerico en mAh): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    battery=(battery);

    cout <<"\nIngrese el anio de lanzamiento del telefono: ";
    while (!(cin >> year) || !hP.isYear(year)) {
        cout << "Ingrese un anio valido (Ejemplo: 2002): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    year=(year);

    utillife=( hP.utilLife(year, battery));



    return phone;
}
