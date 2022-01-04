#include <fstream>
#include <iostream>
#include <string>
#include "struct.h"

using namespace std;

void irasyti_stud(duomenys studentas[], int st_kiekis, string pavadinimas){
    string eilute = "";
    vector <int> paz = {};
    ofstream myfile;
    
    eilute = "Vardas,Pavardė,";
    for (int i = 1; i <= studentas[0].paz.size(); i++){
        eilute += "ND" + to_string(i) + ",";
    }
    eilute += "Egz. \n";
    for (int i = 0; i < st_kiekis; i++){
        eilute += studentas[i].vardas + "," + studentas[i].pavarde + ",";
        paz = studentas[i].paz;
        for (int j = 0; j < paz.size(); j++){
            eilute += to_string(paz[j]) + ",";
        }
        eilute += to_string(studentas[i].egzaminas) + " \n" ;
    }
    myfile.open (pavadinimas, ofstream::trunc);
    myfile << eilute;
    myfile.close();
}