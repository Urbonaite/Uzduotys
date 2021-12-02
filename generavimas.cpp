#include <numeric>
#include "struct.h"
#include "mediana.h"

int ats_paz(){
    return rand() % 10 + 1;
}

void generuoti(duomenys studentas[], int i, int kiekis){
    studentas[i].egzaminas = ats_paz();
    for (int j = 0; j < kiekis; j++){
        studentas[i].paz.push_back(ats_paz());
    }
    studentas[i].paz.erase(studentas[i].paz.begin());
    studentas[i].vidurkis = (float)accumulate(studentas[i].paz.begin(),studentas[i].paz.end(),0.0);
    studentas[i].vidurkis = (float)studentas[i].vidurkis / (float)studentas[i].paz.size();
    studentas[i].vidurkis = (float)studentas[i].vidurkis * 0.4 + 0.6 * (float)studentas[i].egzaminas;
    studentas[i].mediana = gauti_mediana(studentas[i].paz);
    studentas[i].mediana = (float)studentas[i].mediana * 0.4 + 0.6 * (float)studentas[i].egzaminas;
}