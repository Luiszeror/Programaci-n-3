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
                                hP.addPhone(myPhone, 1);

                                break;
                            case 2:
                                cout << "\nAgregar Ultimo: ";
                                myPhone=createObject();
                                hP.addPhone(myPhone, 2);
                                break;

                                break;
                            case 3:
                                cout <<"\nAgregar antes de: ";
                                cout<<"Ingrese el id del telefono al cual quiere agregar antes: ";
                                cin>>find;
                                hP.findPhone(find,createObject(),1);

                                break;
                            case 4:
                                cout <<"\nAgregar despues de: ";
                                cout<<"Ingrese el id del telefono al cual quiere agregar despues: ";
                                cin>>find;
                                hP.findPhone(find,createObject(),2);
                                break;
                            case 5:
                                cout <<"\nAgregar Ordenadamente: ";
                                myPhone=createObject();
                                hP.addPhone(myPhone, 3);
                                break;
                            case 6:
                                // Volver
                                continue;
                            default:
                                cerr << "Digite una opcion valida" << endl;
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

                                cout << "\nVer Primero: ";
                                hP.getFirstLast(1);

                                break;

                            case 2:
                                cout << "Ver Ultimo: ";
                                hP.getFirstLast(2);

                                break;

                            case 3:
                                cout << "\nVer Lista primero-ultimo : \n";



                                if(hP.sizePhone()==0){
                                    cerr <<"\nLa lista esta vacia";
                                }
                                else {
                                    for (Phone c: hP.getPhones(true)) {
                                        cout << c << endl;
                                    }
                                }

                                break;

                            case 4:
                                cout << "\nVer Lista ultimo-primero: \n";

                                if(hP.sizePhone()==0){
                                    cerr <<"\nLa lista esta vacia";
                                }
                                else {
                                    for (Phone c: hP.getPhones(false)) {
                                        cout << c << endl;
                                    }
                                }
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

                    cout <<"\nBuscar telefono:\nIngrese el id del telefono a buscar:";
                    cin >> find;
                    hP.showPhone(find);


                    break;
                case 4:
                    cout <<"Eliminar telefono:\nIngrese el id del telefono a eliminar:";
                    cin >> delet;
                    hP.deletePhone(delet);

                    break;
                case 5:

                    cout << "Hasta la proxima :)";

                    break;
                default:
                    cerr << "Digite una opcion valida" << endl;
                    getchar();getchar();
            }
        } catch (const exception& e) {
            cerr << "Asegurese de ingresar un valor numero relacionado a las opciones" << endl;
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
        cerr << "Ingrese un ID valido (valor numerico): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    phone.setId(id);

    cout <<"\nIngrese el nombre de la marca del telefono: ";
    while (!(cin >> markName) || !hP.isDigit(markName)) {
        cerr << "Ingrese una marca valida (Sin numeros o simbolos): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    phone.setMarkName(markName);

    cout <<"\nIngrese la memoria RAM del telefono: ";
    while (!(cin >> RAM) || !hP.twoDigits(RAM)) {
        cerr << "Ingrese una RAM valida (valor numerico en GBs): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    phone.setRam(RAM);

    cout <<"\nIngrese la capacidad de almacenamiento (ROM) del telefono: ";
    while (!(cin >> ROM) || !hP.twoDigits(ROM)) {
        cerr << "Ingrese una ROM valida (valor numerico en GBS): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    phone.setRom(ROM);


    cout <<"\nEl telefono tiene compatibilidad en 5G?:\n1.Si\n2.No ";
    string G5;
    while (!(cin >> G5) || (G5 != "1" && G5 != "2")) {
        cerr << "Entrada no valida. Por favor, ingrese 1 o 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if(G5=="Si") {
        is5G=(true);
    }else{
        is5G=(false);
    }
    phone.setIs5G(is5G);

    cout <<"\nIngrese la capacidad de bateria del telefono (mAh): ";
    while (!(cin >> battery) || !hP.twoDigits(battery)) {
        cerr << "Ingrese una capacidad valida (valor numerico en mAh): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    phone.setBattery(battery);

    cout <<"\nIngrese el anio de lanzamiento del telefono: ";
    while (!(cin >> year) || !hP.isYear(year)) {
        cerr << "Ingrese un anio valido (Ejemplo: 2002): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    phone.setYear(year);

    phone.setUtilLife( hP.utilLife(year, battery));

    return phone;

}
