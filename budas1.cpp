#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>

using namespace std;
struct duomenys {
    string vardas, pavarde;
    vector <int> paz = {0};
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


void add_student(duomenys studentas[], int i){
    cout << "Iveskite duomenis apie " << i + 1 << " studenta: \n";
    cout << "Iveskite " << i + 1 << " studento varda: \n";
    cin >> studentas[i].vardas;

    cout << "Iveskite " << i + 1 << " studento pavarde: \n";
    cin >> studentas[i].pavarde;
    cout << endl;
}


int main(){
    int num_of_std; int budas; string temp; duomenys studentas[100];
    cout << "Iveskite studentu kieki: \n";
    cin >> num_of_std;
    if (int(num_of_std) <= 0){
        cout << "Ivestas neteisingas skaicius \n";
        return 0;
    }
    cout << "Iveskite 1, jei pazymius suvesite patys, kita skaiciu (simboli), kitu atveju \n";
    cin >> budas;
    if (int(budas) == 1){
        for (int i = 0; i < num_of_std; i++){
            add_student(studentas, i);
            count_from_input(studentas, i);
        }
    }
    else{
        for (int i = 0; i < num_of_std; i++){
            add_student(studentas, i);
            generuoti(studentas, i, 10);
        }
    }
    cout << "Iveskite 1, jei norite vidurkio, kita skaiciu (simboli), jei norite medianos \n";
    cin >> budas;
    budas = int(budas);
    print_result(studentas, num_of_std, budas);
    return 0;
}


