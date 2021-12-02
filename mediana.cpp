#include <iostream>
#include <vector>

using namespace std;

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