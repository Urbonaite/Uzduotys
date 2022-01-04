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

void nuskaityti_is_failo(duomenys studentas[], string failo_pav, int stud){
    int egz, pazim, check = 0, index = 0;
    char c;
    string eilute, pavadinimai, irasas;
    ifstream rezultatai(failo_pav);
    vector <string> zodziai;
    getline(rezultatai, pavadinimai);
    pavadinimai = regex_replace(pavadinimai, regex("[' ']{2,}"), ",");
    SplitString(pavadinimai, zodziai);
    zodziai = {};
    while (getline(rezultatai, eilute)){
        eilute = regex_replace(eilute, regex("[' ']{2,}"), ",");
        SplitString(eilute, zodziai);
        studentas[stud].vardas = zodziai.at(0);
        studentas[stud].pavarde = zodziai.at(1);
        for (int i = 2; i < zodziai.size()-1; i++) {
            pazim = stoi(zodziai.at(i));
            studentas[stud].paz.push_back(pazim);
        }
        egz = stoi(zodziai.at(zodziai.size()-1));
        studentas[stud].egzaminas = egz;
        studentas[stud].vidurkis = (float)accumulate(studentas[stud].paz.begin(),studentas[stud].paz.end(),0.0);
        studentas[stud].vidurkis = (float)studentas[stud].vidurkis / (float)(studentas[stud].paz.size());
        studentas[stud].vidurkis = (float)studentas[stud].vidurkis * 0.4 + 0.6 * (float)studentas[stud].egzaminas;
        studentas[stud].mediana = gauti_mediana(studentas[stud].paz);
        studentas[stud].mediana = (float)studentas[stud].mediana * 0.4 + 0.6 * (float)studentas[stud].egzaminas;
        zodziai = {};
        stud++;
    }
}
 