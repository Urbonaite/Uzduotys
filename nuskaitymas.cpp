#include <iostream>
#include <iomanip>
#include <numeric>
#include <regex>
#include <fstream>
#include "struct.h"
#include "mediana.h"


using namespace std;


void SplitString(string s, vector<string> &v){
	
	string temp = "";
	for(int i=0;i<s.length();++i){
		
		if(s[i]==','){
			v.push_back(temp);
			temp = "";
		}
		else{
			temp.push_back(s[i]);
		}
		
	}
	v.push_back(temp);
	
}

void nuskaityti_is_failo(vector <duomenys> &studentai, string failo_pav, int stud){
    int egz, pazim, check = 0, index = 0;
    char c;
    string eilute, pavadinimai, irasas;
    ifstream rezultatai(failo_pav);
    vector <string> zodziai;
    vector <int> pazymiai;
    duomenys studentas;
    getline(rezultatai, pavadinimai);
    pavadinimai = regex_replace(pavadinimai, regex("[' ']{2,}"), ",");
    SplitString(pavadinimai, zodziai);
    zodziai = {};
    while (getline(rezultatai, eilute)){
        eilute = regex_replace(eilute, regex("[' ']{2,}"), ",");
        SplitString(eilute, zodziai);
        studentas.vardas = zodziai.at(0);
        studentas.pavarde = zodziai.at(1);
        for (int i = 2; i < zodziai.size()-1; i++) {
            pazim = stoi(zodziai.at(i));
            pazymiai.push_back(pazim);
        }
        studentas.paz = pazymiai;
        egz = stoi(zodziai.at(zodziai.size()-1));
        studentas.egzaminas = egz;
        studentas.vidurkis = (float)accumulate(studentas.paz.begin(),studentas.paz.end(),0.0);
        studentas.vidurkis = (float)studentas.vidurkis / (float)(studentas.paz.size());
        studentas.vidurkis = (float)studentas.vidurkis * 0.4 + 0.6 * (float)studentas.egzaminas;
        studentas.mediana = gauti_mediana(studentas.paz);
        studentas.mediana = (float)studentas.mediana * 0.4 + 0.6 * (float)studentas.egzaminas;
        zodziai = {};
        pazymiai = {};
        studentai.push_back(studentas);
        duomenys studentas;
        stud++;
    }
}
 