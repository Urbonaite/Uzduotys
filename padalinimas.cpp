#include <iostream>
#include <iomanip>
#include "struct.h"

using namespace std;

void padalinti(duomenys studentai_geri[], duomenys studentai_blogi[], duomenys studentas[],
                  int st_kiekis, int budas, int &geri_dydis, int &blogi_dydis)
{
    if (budas == 1){
        for (int i = 0; i<st_kiekis; i++){
            if (studentas[i].vidurkis >= 5){
                studentai_geri[geri_dydis++] = studentas[i];
            }
            else{
                studentai_blogi[blogi_dydis++] = studentas[i];
            }
        }
    }
    else{
        for (int i = 0; i<st_kiekis; i++){
            if (studentas[i].mediana >= 5){
                studentai_geri[geri_dydis++] = studentas[i];
            }
            else{
                studentai_blogi[blogi_dydis++] = studentas[i];
            }
        }
    }
}