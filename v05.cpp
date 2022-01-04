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
    int num_of_std; int budas; int st_kiekis=1000000; int paz_kiekis=4; int geri_kiekis=0; int blogi_kiekis=0; 
    string temp; 
    vector <duomenys> studentai;
    vector <duomenys> studentai_geri;
    vector <duomenys> studentai_blogi;

    // padalinam
    // nuskaitom failus

    generuoti_studentus(studentai, st_kiekis, paz_kiekis);
    irasyti_stud(studentai, st_kiekis, "visi1000k.txt");

    auto start_0 = chrono::high_resolution_clock::now();
    nuskaityti_is_failo(studentai, "visi1000k.txt", 0);
    auto end_0 = chrono::high_resolution_clock::now();
    chrono::duration<double> diff_0 = end_0 - start_0;
    cout << "1,000,000 studentų nuskaitymas iš failo užtruko: " << diff_0.count() << "s \n\n";

    auto start_1 = chrono::high_resolution_clock::now();
    padalinti(studentai_geri, studentai_blogi, studentai, st_kiekis, budas, geri_kiekis, blogi_kiekis);
    auto end_1 = chrono::high_resolution_clock::now();
    chrono::duration<double> diff_1 = end_1 - start_1;
    cout << "1,000,000 studentų padalinimas užtruko: " << diff_1.count() << "s \n\n";

    // print_result(studentai_geri, 100, 1);
    // irasyti_stud(studentai, studentai.size(), "visi_test.txt");
    // cout << "Iveskite 1, jei norite vidurkio, kita skaiciu (simboli), jei norite medianos \n";
    // cin >> budas;
    // budas = int(budas);
    // print_result(studentas, 10000, budas);
    // padalinti(studentai_geri, studentai_blogi, studentas, st_kiekis, budas, geri_kiekis, blogi_kiekis);
    // irasyti_stud(studentai_blogi, blogi_kiekis, "blogi.txt");
    // irasyti_stud(studentai_geri, geri_kiekis, "geri.txt");
    // print_result(studentai_geri, 100, budas);
    // nuskaityti_is_failo(studentai_test, "geri.txt", 0);
    // nuskaityti_is_failo(studentai_test, "blogi.txt", geri_kiekis);
    // print_result(studentai_test, 10000, budas);
    // irasyti_stud(studentai_test, st_kiekis, "visi.txt");
    // // print_result(studentai_blogi, 100, budas);

    return 0;
}