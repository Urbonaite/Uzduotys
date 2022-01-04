#include <iostream>
#include <iomanip>
#include "struct.h"

using namespace std;

void padalinti(vector <duomenys> &studentai_geri, 
               vector <duomenys> &studentai_blogi, 
               vector <duomenys> &studentai,
               int st_kiekis, int budas, int &geri_dydis, int &blogi_dydis)
{
    duomenys studentas;
    if (budas == 1){
        for (int i = 0; i<studentai.size(); i++){
            studentas = studentai.at(i);
            if (studentas.vidurkis >= 5){
                studentai_geri.push_back(studentas);
            }
            else{
                studentai_blogi.push_back(studentas);
            }
        }
    }
    else{
        for (int i = 0; i<studentai.size(); i++){
            studentas = studentai.at(i);
            if (studentas.mediana >= 5){
                studentai_geri.push_back(studentas);
            }
            else{
                studentai_blogi.push_back(studentas);
            }
        }
    }
}