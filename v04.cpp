#include "mediana.h"
#include "struct.h"
#include "print_result.h"
#include "count_from_input.h"
#include "nuskaitymas.h"
#include "generavimas.h"
#include "padalinimas.h" 
#include "irasyti_faila.h"
#include <chrono>

using namespace std;



int main(){
    int num_of_std; int budas; int st_kiekis=10000; int paz_kiekis=4; int geri_kiekis=0; int blogi_kiekis=0; 
    string temp; 
    duomenys studentas[10000], studentai_geri[10000], studentai_blogi[10000], studentai_test[10000];

    auto start_0 = chrono::high_resolution_clock::now();
    generuoti_studentus(studentas, st_kiekis, paz_kiekis);
    irasyti_stud(studentas, st_kiekis, "visi1k.txt");
    auto end_0 = chrono::high_resolution_clock::now();
    chrono::duration<double> diff_0 = end_0 - start_0;
    cout << "1000 studentų generavimas ir įrašymas į failą užtruko: " << diff_0.count() << "s \n\n";
    // cout << "Iveskite 1, jei norite vidurkio, kita skaiciu (simboli), jei norite medianos \n";
    // cin >> budas;

    auto start_1 = chrono::high_resolution_clock::now();
    budas = 1;
    padalinti(studentai_geri, studentai_blogi, studentas, st_kiekis, budas, geri_kiekis, blogi_kiekis);
    auto end_1 = chrono::high_resolution_clock::now();
    chrono::duration<double> diff_1 = end_1 - start_1;
    cout << "1000 studentų padalijimas užtruko: " << diff_1.count() << "s \n\n";

    auto start_2 = chrono::high_resolution_clock::now();
    irasyti_stud(studentai_blogi, blogi_kiekis, "blogi1k.txt");
    auto end_2 = chrono::high_resolution_clock::now();
    chrono::duration<double> diff_2 = end_2 - start_2;
    cout << "1000 įrašų įrašymas į blogų failą užtruko: " << diff_2.count() << "s \n\n";

    auto start_3 = chrono::high_resolution_clock::now();
    irasyti_stud(studentai_geri, geri_kiekis, "geri1k.txt");
    auto end_3 = chrono::high_resolution_clock::now();
    chrono::duration<double> diff_3 = end_3 - start_3;
    cout << "1000 įrašų įrašymas į gerų failą užtruko:  " << diff_3.count() << "s \n\n";

    auto start_4 = chrono::high_resolution_clock::now();
    nuskaityti_is_failo(studentai_test, "geri1k.txt", 0);
    nuskaityti_is_failo(studentai_test, "blogi1k.txt", geri_kiekis);
    auto end_4 = chrono::high_resolution_clock::now();
    chrono::duration<double> diff_4 = end_4 - start_4;
    cout << "1000 įrašų nuskaitymas iš failo užtruko:  " << diff_4.count() << "s \n\n";

    // nuskaityti_is_failo(studentai_test, "studentai10000.txt", geri_kiekis);
    // print_result(studentai_test, 10000, budas);

    // print_result(studentai_test, 10000, budas);
    // irasyti_stud(studentai_test, st_kiekis, "visi10.txt");
    // print_result(studentai_blogi, 100, budas);
    return 0;
}