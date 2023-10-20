#include <vector>
#include <iostream>
#include <utility>
#include <array>
#include <random>
using namespace std;

void print(vector<int> sez){
    for (int x : sez) cout << x << " ";
    cout << endl;
}

array<vector<int>, 3> partition(vector<int> sez) {
    int izbran = sez[0];
    vector<int> majhni, enaki, veliki;
    for (int x : sez){
        if (x == izbran){
            enaki.push_back(x);
        } else if (x < izbran){
            majhni.push_back(x);
        } else if (x > izbran){
            veliki.push_back(x);
        }
    }
    return {majhni, enaki, veliki};
}

vector<int> quicksort(vector<int> sez) {
    if (sez.size()<=1) return sez;
    auto [majhni, enaki, veliki] = partition(sez);
    auto urejeni_majhni = quicksort(majhni);
    auto urejeni_veliki = quicksort(veliki);
    vector<int> rez;
    for (int x : urejeni_majhni) rez.push_back(x);
    for (int x : enaki) rez.push_back(x);
    for (int x : urejeni_veliki) rez.push_back(x);
    return rez;
}

// binary search
int bisekcija(vector<int> &sez, int x){
    int l = -1, r=sez.size();

    // r in l se priblizujeta.
    while(r-l>1){
        int m = (l+r)/2;
        if (x < sez[m]) r=m;
        else l=m;
    }
    return r;
}

class DynamicArray {
private:
    int *t, size, capacity;

public:
    DynamicArray() {
        size=0;
        capacity=1;
        t = (int*) malloc(sizeof(int));
    }

    // destruktor
    ~DynamicArray() {
        free(t);
    }

    int get(int i){
        return t[i];
    }

    void add(int x){
        if (size == capacity){
            capacity *= 2;
            t = (int*) realloc(t, capacity*sizeof(int));
        }
        
        t[size++] = x;
    }
};


int main() {
    DynamicArray testiranje;
    testiranje.add(5);
    testiranje.add(3);
    testiranje.add(12);
    cout << testiranje.get(1) << endl;
    /*vector<int> sez = {9,4,2,8,7,5};
    print(sez);
    sez = quicksort(sez);
    print(sez);
    */

    /*vector<int> sez={2, 3, 3, 3, 5, 6, 8, 9, 39, 100};
    cout << bisekcija(sez, 7) << endl;
    */
    /*vector<int> sez;
    default_random_engine rnd(123);
    for(int i = 0;i<10000; i++) sez.push_back(rnd()%1000000);
    sez = quicksort(sez);*/
    return 0;
}