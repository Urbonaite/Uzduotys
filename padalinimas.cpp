#include <iostream>
#include <iomanip>
#include "struct.h"

using namespace std;

void padalinti(vector <duomenys> &studentai_blogi, 
               vector <duomenys> &studentai,
               int budas)
{
    duomenys studentas;
    if (budas == 1){
        for (int i = studentai.size()-1; i>=0; i--){
            studentas = studentai.at(i);
            if (studentas.vidurkis < 5){
                studentai_blogi.push_back(studentas);
                studentai.erase(studentai.begin() + i);
            }
        }
    }
    else{
        for (int i = studentai.size()-1; i>=0; i--){
            studentas = studentai.at(i);
            if (studentas.mediana < 5){
                studentai_blogi.push_back(studentas);
                studentai.erase(studentai.begin() + i);
            }
        }
    }
}
