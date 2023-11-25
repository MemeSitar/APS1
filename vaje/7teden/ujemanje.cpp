#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define SEGS printf("%s:%d\n", __FILE__, __LINE__);

void print(vector<pair<int, int>> sez){
    for(pair<int, int> par : sez){
        if (par.first == -1){
            cout << par.first << "\n";
        } else {
            cout << par.first << " " << par.second << "\n";
        }
    }
    cout.flush();
}

pair<int, int> ujemanje(string vzorec, string beseda){
    pair<int, int> rez(0, 0);

    return rez;
}

int main(){
    vector<pair<int, int>> rez;
    int stNizov;
    string vzorec, beseda;

    cin >> stNizov;
    for(int i=0; i<stNizov; i++){
        cin >> vzorec >> beseda;
        rez.push_back(ujemanje(vzorec, beseda));
    }

    print(rez);
}