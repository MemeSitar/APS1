#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

void print(vector<int> &sez){
    for (int stev : sez){
        cout << stev<< "\n";
    }
    cout.flush();
}

/*
V vsakem vozliscu:
Hranimo crko ki nas je do tega vozlisca pripeljala
Hranimo indeks na najbolj verjetno besedo iz slovarja
Hranimo prioriteto ?
Hranimo seznam vozlisc za vsako naslednjo crko; Ce poizvedba kaze na NULL vrnemo takoj 0.

*/
class trie{
public:
    node* arr[26];

    trie(){

    }

    void dodajBesedo(string beseda, int index, int prioriteta){

    }

    int isciBesedo(string beseda){

    }
};

class node{
public:
    node* arr[26] = {nullptr};
    char c;
    int prioriteta;
    int index;

    node(char c, int prioriteta, int index){
        this->c = c;
        this->prioriteta = prioriteta;
        this->index = index;
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