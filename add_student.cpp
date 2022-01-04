#include "struct.h"

void add_student(duomenys studentas[], int i){
    cout << "Iveskite duomenis apie " << i + 1 << " studenta: \n";
    cout << "Iveskite " << i + 1 << " studento varda: \n";
    cin >> studentas[i].vardas;

    cout << "Iveskite " << i + 1 << " studento pavarde: \n";
    cin >> studentas[i].pavarde;
    cout << endl;
}