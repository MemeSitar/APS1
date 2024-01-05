#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

void izpisiSezname(vector<vector<long>> seznami){
    for(vector<long> seznam : seznami){
        cout << "[";
        for(long stevilka : seznam){
            cout << stevilka << ", ";
        }
        cout << "]" << endl;
    }
}

long funkcija(int i, int x, int N){
    return static_cast<long>(x * pow(log2(x), (float) i/ (float)N));
}

int main(){

    int N, k;
    cin >> N >> k;
    vector<pair<int, int>> iksi = vector<pair<int, int>>(N, pair<int, int>(0, 0));
    vector<vector<long>> seznami = vector<vector<long>>(N);
    for(int i=0; i<N; i++){
        cin >> iksi[i].first >> iksi[i].second;
        seznami[i] = vector<long>(iksi[i].second - iksi[i].first + 1);
        int g = 0;
        for(int j=iksi[i].first; j<=iksi[i].second; j++){
            seznami[i][g] = funkcija(i + 1, j, N);
            g++;
        }
    }
    izpisiSezname(seznami);
}