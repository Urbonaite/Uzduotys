#include <fstream>
#include <iostream>
#include <string>
#include "struct.h"

using namespace std;

void irasyti_stud(vector <duomenys> studentai, int st_kiekis, string pavadinimas){
    string eilute = "";
    vector <int> paz = {};
    ofstream myfile;
    
    paz = studentai[0].paz;
    eilute = "Vardas,Pavardė,";
    for (int i = 1; i <= paz.size(); i++){
        eilute += "ND" + to_string(i) + ",";
    }
    eilute += "Egz. \n";
    for (int i = 0; i < st_kiekis; i++){
        eilute += studentai[i].vardas + "," + studentai[i].pavarde + ",";
        paz = studentai[i].paz;
        for (int j = 0; j < paz.size(); j++){
            eilute += to_string(paz[j]) + ",";
        }
        eilute += to_string(studentai[i].egzaminas) + " \n" ;
    }
    myfile.open (pavadinimas, ofstream::trunc);
    myfile << eilute;
    myfile.close();
}