#include <iostream>
#include <iomanip>
#include "struct.h"

using namespace std;

void print_result(duomenys studentas[], int num_of_std, int budas)
{
    cout << "\n";
    cout << "Vardas ";
    cout << "Pavarde ";
    cout << "Rezultatas \n";
    for (int i = 0; i < num_of_std; i++)
    {
        cout << studentas[i].vardas << " ";
        cout << studentas[i].pavarde << " ";
        if (budas == 1){
            cout << setprecision(2) << fixed << studentas[i].vidurkis << "\n";
        }
        else{
            cout << setprecision(2) << fixed << studentas[i].mediana << "\n";
        }
    }
    cout << "\n";
}
