#include <iostream>
#include <iomanip>
#include "struct.h"

using namespace std;

void print_result(vector <duomenys> studentai, int num_of_std, int budas)
{
    duomenys studentas;
    cout << "\n";
    cout << "Vardas ";
    cout << "Pavarde ";
    cout << "Rezultatas \n";
    for (int i = 0; i < num_of_std; i++)
    {
        studentas = studentai[i];
        cout << studentas.vardas << " ";
        cout << studentas.pavarde << " ";
        for (int j=0; j<4; j++){
            cout << studentas.paz.at(j) << " ";
        }
        cout << studentas.egzaminas << " ";
        if (budas == 1){
            cout << setprecision(2) << fixed << studentas.vidurkis << "\n";
        }
        else{
            cout << setprecision(2) << fixed << studentas.mediana << "\n";
        }
    }
    cout << "\n";
}
