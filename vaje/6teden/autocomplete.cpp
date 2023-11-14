#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

/*
V vsakem vozliscu:
Hranimo crko ki nas je do tega vozlisca pripeljala
Hranimo indeks na najbolj verjetno besedo iz slovarja
Hranimo prioriteto ?
Hranimo seznam vozlisc za vsako naslednjo crko; Ce poizvedba kaze na NULL vrnemo takoj 0.

*/
class node{
public:
    vector<node> arr;
    char c;
    int prioriteta;
    int index;

    node(char c, int prioriteta, int index){
        this->c = c;
        this->prioriteta = prioriteta;
        this->index = index;
    }
    void dodajBesedo(string beseda, int prioriteta, int index){
        if (beseda.length() == 0) return;
        dodajBesedo(beseda.erase(0,1), prioriteta, index);
    }
};

int main(){
    int stBesed, stPoizvedb;
    int tmp;
    string temp;

    vector<pair<string, int>> slovar;

    for (int i; i < stBesed; i++){
        cin >> temp >> tmp;
        slovar.push_back(pair(temp, tmp));
    }

    
}