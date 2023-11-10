#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

struct Voz {
    int leva;
    int desna;
    Voz* levi;
    Voz* desni;
};

void dodaj(int* arr, int x){
    arr[x]++;
}

void odstrani(int* arr, int x){
    if (arr[x] > 0){
        arr[x]--;
    }
}

int poizvedba(int* arr, int a, int b){
    int rez = 0;
    for(int i = a; i <= b; i++){
        rez += arr[i];
    }
    return rez;
}

int main() {
    int* arr = (int*)calloc(1000000, sizeof(int));
    int rez = 0;
    int n, s, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s >> x;
        if(s < 0){
            dodaj(arr, x);
        } else if (s == 0){
            odstrani(arr, x);
        } else {
            rez += poizvedba(arr, min(s, x), max(s, x));
        }
    }
    cout << rez << endl;
}