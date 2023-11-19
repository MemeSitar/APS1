#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;


// vozlisce steje vse elemente med [[lMeja, dMeja))
class staticTree{
public:
    int lMeja;
    int dMeja;
    staticTree *levi;
    staticTree *desni;
    long stev;

    /* (rekurzivna) funkcija prijazno izgradi drevo sledece:
        - vzame lMeja in dMeja, ju nastavi.
        - ce sta enaka je to singleton, nima otrok
        - ce sta razlicna, ustvari dva otroka L in D, kjer so njihove meje sledece:
            (najprej poiscemo kako dolg je interval in sredino intervala)
            length = dMeja - lMeja
            sredina = length/2 (zaokrozeno NAVZDOL)
            [L->lMeja = lMeja,          L->dMeja = lMeja + sredina]
            [D->lMeja = lMeja + sredina + 1,  D->dMeja = dMeja]
    */
    staticTree(int lMeja, int dMeja){
        this->lMeja = lMeja;
        this->dMeja = dMeja;
        stev = 0;
        if (lMeja == dMeja){
            levi = NULL;
            desni = NULL;
        } else {
            int sredina = lMeja + (dMeja - lMeja)/2;
            levi = new staticTree(lMeja, sredina);
            desni = new staticTree(sredina + 1, dMeja);
        }
    }

    void dodaj(int x){
        if ((x >= lMeja) && (x <= dMeja)){
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
        if ((x >= lMeja) && (x <= dMeja)){
            if (stev > 0) stev--;
            if (levi){
                levi->odstrani(x);
            }
            if (desni){
                desni->odstrani(x);
            }
        }
    }


    long poizvedba(int a, int b){
        // tocen match ALI vsebovanje
        long rez = 0;
        if ((a <= lMeja && b >= dMeja)){
            return stev;
        } else {
            if (levi) rez += levi->poizvedba(a, b); 
            if (desni) rez+= desni->poizvedba(a, b);
            return rez;
        }

    }
};

int main() {
    staticTree drevo = staticTree(1, 1000000);
    long rez = 0;
    int n, s, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s >> x;
        if(s < 0){
            drevo.dodaj(x);
        } else if (s == 0){
            drevo.odstrani(x);
        } else {
            rez += drevo.poizvedba(min(s, x), max(s, x));
        }
    }
    cout << rez << endl;
}