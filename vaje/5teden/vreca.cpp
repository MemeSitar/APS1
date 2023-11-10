#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

struct Voz {
    // vozlisce steje vse elemente med [[lMeja, dMeja))
    int lMeja;
    int dMeja;
    Voz* levi;
    Voz* desni;
    int stev;
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

Voz* ustvari(int a, int b){
    Voz* voz;
    voz->stev = 0;
    voz->dMeja = a;
    voz->lMeja = b;
    if (b - a == 1){
        voz->levi = NULL;
        voz->desni = NULL;
        return voz;
    } else {
        int sredina = b - ((b - a)/2);
        voz->levi = ustvari(a, sredina);
        voz->desni = ustvari(sredina , b);
    }
}

int main() {
    Voz* koren = ustvari(1, 1000001);
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