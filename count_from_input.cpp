#include <iostream>
#include <iomanip>
#include <numeric>
#include "struct.h"
#include "mediana.h"

using namespace std;

void count_from_input(duomenys studentas[], int i){
    int temp;
    cout << "Iveskite studento egzamino rezultata: \n";
    cin >> studentas[i].egzaminas;
    if (studentas[i].egzaminas < 0 || studentas[i].egzaminas > 10){
        cout << "Ivestas netinkamas pazymys \n";
        exit (EXIT_FAILURE);
    }
    cout << "Iveskite studento pazymius, norint baigti iveskite pazymi mazesni uz 1: \n";
    temp = 1;
    while (temp > 0) {
        cin >> temp;
        temp = int(temp);
        if (temp > 10){
            cout << "Ivestas netinkamas pazymys \n";
            exit (EXIT_FAILURE);
        }
        studentas[i].paz.push_back(temp);
    }
    studentas[i].paz.erase(studentas[i].paz.begin());
    studentas[i].paz.erase(studentas[i].paz.end()-1);
    studentas[i].vidurkis = accumulate(studentas[i].paz.begin(),studentas[i].paz.end(),0.0);
    studentas[i].vidurkis = (float)studentas[i].vidurkis / (float)studentas[i].paz.size();
    studentas[i].vidurkis = (float)studentas[i].vidurkis * 0.4 + 0.6 * (float)studentas[i].egzaminas;
    studentas[i].mediana = gauti_mediana(studentas[i].paz);
    studentas[i].mediana = (float)studentas[i].mediana * 0.4 + 0.6 *(float)studentas[i].egzaminas;
}