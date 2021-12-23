#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>

using namespace std;
struct duomenys {
    string vardas, pavarde;
    int paz[4] = {0};
    float egzaminas;
    float vidurkis = 0;
    float mediana = 0;
};

void print_result(duomenys studentas[], int num_of_std, int budas)
{
    cout << "\n";
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


double gauti_mediana(int pazymiai[4]){
  int size = sizeof(pazymiai[4]);
  if (size == 0){
    return 0;
  }
  else{
    sort(pazymiai, pazymiai + (int)sizeof(pazymiai[4]), greater<int>());
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
    int pazymiu_sk = 4;
    int pazymio_vieta = 0;
    cout << "Iveskite studento egzamino rezultata: \n";
    cin >> studentas[i].egzaminas;
    if (studentas[i].egzaminas < 0 || studentas[i].egzaminas > 10){
        cout << "Ivestas netinkamas pazymys \n";
        exit (EXIT_FAILURE);
    }
    cout << "Iveskite 4 studento pazymius \n";
    while (pazymio_vieta < pazymiu_sk) {
        cin >> temp;
        temp = int(temp);
        if (temp > 10 || temp < 1){
            cout << "Ivestas netinkamas pazymys \n";
            exit (EXIT_FAILURE);
        }
        studentas[i].paz[pazymio_vieta] = temp;
        pazymio_vieta++;
    }
    studentas[i].vidurkis = accumulate(studentas[i].paz, studentas[i].paz+pazymiu_sk, 0); 
    studentas[i].vidurkis = (float)studentas[i].vidurkis / (float)pazymiu_sk;
    studentas[i].vidurkis = (float)studentas[i].vidurkis * 0.4 + 0.6 * (float)studentas[i].egzaminas;
    studentas[i].mediana = gauti_mediana(studentas[i].paz);
    studentas[i].mediana = (float)studentas[i].mediana * 0.4 + 0.6 *(float)studentas[i].egzaminas;
}

int ats_paz(){
    return rand() % 10 + 1;
}

void generuoti(duomenys studentas[], int i, int kiekis){
    studentas[i].egzaminas = ats_paz();
    for (int j = 0; j < kiekis; j++){
        studentas[i].paz[j] = ats_paz();
    }
    studentas[i].vidurkis = accumulate(studentas[i].paz, studentas[i].paz+kiekis, 0);
    studentas[i].vidurkis = (float)studentas[i].vidurkis / (float)sizeof(studentas[i].paz);
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
            generuoti(studentas, i, 4);
        }
    }
    cout << "Iveskite 1, jei norite vidurkio, kita skaiciu (simboli), jei norite medianos \n";
    cin >> budas;
    budas = int(budas);
    print_result(studentas, num_of_std, budas);
    return 0;
}
