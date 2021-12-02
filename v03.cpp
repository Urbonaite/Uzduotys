#include "mediana.h"
#include "struct.h"
#include "print_result.h"
#include "count_from_input.h"
#include "nuskaitymas.h"

using namespace std;



int main(){
    int num_of_std; int budas; string temp; duomenys studentas[11000];
    nuskaityti_is_failo(studentas);
    cout << "Iveskite 1, jei norite vidurkio, kita skaiciu (simboli), jei norite medianos \n";
    cin >> budas;
    budas = int(budas);
    print_result(studentas, 100, budas);
    return 0;
}