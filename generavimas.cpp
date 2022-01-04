#include <numeric>
#include "struct.h"
#include "mediana.h"
#include <iostream>

int ats_paz(){
    return rand() % 10 + 1;
}

void generuoti(duomenys &studentas, int i, int kiekis){
    vector <int> paz = {};
    int egzaminas=0;
    studentas.egzaminas = ats_paz();
    for (int j = 0; j < kiekis; j++){
        paz.push_back(ats_paz());
    }
    studentas.paz = paz;
    studentas.vidurkis = (float)accumulate(studentas.paz.begin(),studentas.paz.end(),0.0);
    studentas.vidurkis = (float)studentas.vidurkis / (float)studentas.paz.size();
    studentas.vidurkis = (float)studentas.vidurkis * 0.4 + 0.6 * (float)studentas.egzaminas;
    studentas.mediana = gauti_mediana(studentas.paz);
    studentas.mediana = (float)studentas.mediana * 0.4 + 0.6 * (float)studentas.egzaminas;
}

void generuoti_studentus(vector <duomenys> &studentai, int studentu_kiekis, int kiekis){
    duomenys studentas;
    for (int i = 0; i<studentu_kiekis; i++){
        studentas.vardas = "Vardas" + to_string(i);
        studentas.pavarde = "Pavarde" + to_string(i);
        generuoti(studentas, i, kiekis);
        studentai.push_back(studentas);
    }
}