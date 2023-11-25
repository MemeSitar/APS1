#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define SEGS printf("%s:%d\n", __FILE__, __LINE__);

void print(vector<int> &sez){
    for (int stev : sez){
        cout << stev<< "\n";
    }
    cout.flush();
}

class node{
public:
    node* arr[26] = {nullptr};
    char c;
    int prioriteta;
    int index;

    node(char c, int index, int prioriteta){
        this->c = c;
        this->prioriteta = prioriteta;
        this->index = index;
    }
};

/*
V vsakem vozliscu:
Hranimo crko ki nas je do tega vozlisca pripeljala
Hranimo indeks na najbolj verjetno besedo iz slovarja
Hranimo prioriteto ?
Hranimo seznam vozlisc za vsako naslednjo crko; Ce poizvedba kaze na NULL vrnemo takoj 0.

*/
class trie{
public:
    node* arr[26] = {nullptr};
    node* root;

    trie(){
        root = new node('\0', 0, 0);
    }

    void dodajBesedo(string beseda, int index, int prioriteta){
        node* vozl = root;
        int crka;
        for(int i = 0; i < beseda.length(); i++){
            crka = (int) beseda.at(i) - 'a';
            // ce ne obstaja
            if(vozl->arr[crka] == nullptr){
                vozl->arr[crka] = new node(beseda.at(i), index, prioriteta);
            }

            vozl = vozl->arr[crka];

            if (vozl->prioriteta < prioriteta){
                vozl->prioriteta = prioriteta;
                vozl->index = index;
            }
        }
    }

    int isciBesedo(string beseda){
        node* vozl = root;
        int crka;
        int rez;
        for (int i = 0; i < beseda.length(); i++){
            crka = (int) beseda.at(i) - 'a';
            if (vozl->arr[crka] == nullptr){
                return 0;
            }
            vozl = vozl->arr[crka];
            rez = vozl->index;
        }
        return rez;
    }
};

int main(){
    vector<int> rez;
    int stBesed, stPoizvedb;
    int tmp;
    string temp;
    trie drevo = trie();
    cin >> stBesed;

    for(int i=0; i < stBesed; i++){
        cin >> temp >> tmp;
        drevo.dodajBesedo(temp, i+1, tmp);
    }

    cin >> stPoizvedb;

    for(int i=0; i < stPoizvedb; i++){
        cin >> temp;
        rez.push_back(drevo.isciBesedo(temp));
    }

    print(rez);
}