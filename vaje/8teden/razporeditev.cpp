#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define SEGS printf("%s:%d\n", __FILE__, __LINE__);

void print(vector<int> sez){
    for(int stev : sez){
        cout << stev << "\n";
    }
    cout.flush();
}

void dodaj(vector<vector<int>> &tabelaSosedov, int a, int b){
    tabelaSosedov[a - 1].push_back(b - 1);
    tabelaSosedov[b - 1].push_back(a - 1);
}

int main(){
    vector<int> rez;
    int stOtrok, stVpisov;
    int tmp1, tmp2;
    cin >> stOtrok, stVpisov;
    vector<vector<int>> sosedi(stOtrok);
    vector<int> barve(stOtrok);
    for(int i=0; i < stVpisov; i++){
        cin >> tmp1 >> tmp2;
        dodaj(sosedi, tmp1, tmp2);
    }

    return 0;
}