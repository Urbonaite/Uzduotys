#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>
#include <fstream>
#include <regex>

using namespace std;
struct duomenys {
    string vardas, pavarde;
    vector <int> paz = {};
    float egzaminas;
    float vidurkis = 0;
    float mediana = 0;
};


void print_result(duomenys studentas[], int num_of_std, int budas)
{
    cout << "\n";
    cout << "Vardas ";
    cout << "Pavarde ";
    cout << "Rezultatas \n";
    for (int i = 0; i < num_of_std; i++)
    {
        cout << studentas[i].vardas << " ";
        cout << studentas[i].pavarde << " ";
        if (budas == 1){
            cout << setprecision(2) << fixed << studentas[i].vidurkis << "\n";
        }
        else{
            cout << setprecision(2) << fixed << studentas[i].mediana << "\n";
        }
    }
    cout << "\n";
}


double gauti_mediana(vector<int> pazymiai){
  int size = pazymiai.size();
  if (size == 0){
    return 0;
  }
  else{
    sort(pazymiai.begin(), pazymiai.end());
    if (size % 2 == 0){
      return ((float)pazymiai[size / 2 - 1] + (float)pazymiai[size / 2]) / 2;
    }
    else {
      return pazymiai[size / 2];
    }
  }
}

void count_from_input(duomenys studentas[], int i)
{
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

int ats_paz(){
    //srand(time(NULL));
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

void SplitString(string s, vector<string> &v){
	
	string temp = "";
	for(int i=0;i<s.length();++i){
		
		if(s[i]==' '){
			v.push_back(temp);
			temp = "";
		}
		else{
			temp.push_back(s[i]);
		}
		
	}
	v.push_back(temp);
	
}

void nuskaityti_is_failo(duomenys studentas[]){
    int egz, pazim, stud = 0, check = 0, index = 0;
    char c;
    string eilute, pavadinimai, irasas;
    ifstream rezultatai("studentai10000.txt");
    vector <string> zodziai;
    getline(rezultatai, pavadinimai);
    pavadinimai = regex_replace(pavadinimai, regex("[' ']{2,}"), " ");
    SplitString(pavadinimai, zodziai);
    zodziai = {};
    while (getline(rezultatai, eilute)){
    //     eilute = regex_replace(eilute, regex("[' ']{2,}"), " ");
    //     SplitString(eilute, zodziai);
    //     for (int i = 2; i < zodziai.size(); i++) {
    //         irasas = zodziai.at(i);
    //         cout << "\n";
    //         cout << stoi(irasas) << "\n";
    //     }
    //     zodziai = {};
    // }
        eilute = regex_replace(eilute, regex("[' ']{2,}"), " ");
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
    // }
    // for (int i = 2; i < zodziai.size()-1; i++) {
    //     cout << "\n";
    //     cout << zodziai.at(i) << ' ';
    // }
}
 


void add_student(duomenys studentas[], int i){
    cout << "Iveskite duomenis apie " << i + 1 << " studenta: \n";
    cout << "Iveskite " << i + 1 << " studento varda: \n";
    cin >> studentas[i].vardas;

    cout << "Iveskite " << i + 1 << " studento pavarde: \n";
    cin >> studentas[i].pavarde;
    cout << endl;
}


int main(){
    int num_of_std; int budas; string temp; duomenys studentas[11000];
    nuskaityti_is_failo(studentas);
    cout << "Iveskite 1, jei norite vidurkio, kita skaiciu (simboli), jei norite medianos \n";
    cin >> budas;
    budas = int(budas);
    print_result(studentas, 100, budas);
    return 0;
}


