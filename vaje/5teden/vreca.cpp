#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;


// vozlisce steje vse elemente med [[lMeja, dMeja))
class treeNode{
public:
    int lMeja;
    int dMeja;
    treeNode *levi;
    treeNode *desni;
    int stev;
    treeNode(int lMeja, int dMeja){
        this->lMeja = lMeja;
        this->dMeja = dMeja;
        stev = 0;
        if (dMeja - lMeja == 1){
            levi = NULL;
            desni = NULL;
        } else {
            int sredina = dMeja - ((dMeja - lMeja/2));
            levi = &treeNode(lMeja, sredina);
            desni = &treeNode(sredina , dMeja);
        }
    }

    void dodaj(int x){
        if ((x >= lMeja) && (x < dMeja)){
            stev++;
            if (levi){
                levi->dodaj(x);
            }
            if (desni){
                desni->dodaj(x);
            }
        }

    }

    void odstrani(int x){
        if ((x >= lMeja) && (x < dMeja)){
            if (stev > 0) stev--;
            if (levi){
                levi->dodaj(x);
            }
            if (desni){
                desni->dodaj(x);
            }
        }
    }


    int poizvedba(int a, int b){
        if ((a < lMeja) || (b >= dMeja)) return 0;
        if ((a == lMeja && b == dMeja)){
            return stev;
        }

    }
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
    long rez = 0;
    int n, s, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s >> x;
        if(s < 0){
            dodaj(arr, x);
        } else if (s == 0){
            odstrani(arr, x);
        } else {
            rez += poizvedba(arr, min(s, x), max(s, x) + 1);
        }
    }
    cout << rez << endl;
}