#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

void print(vector<int> &sez){
    for (int stevilka : sez){
        cout << stevilka << endl;
    }
}

int main(){
    int stElementov = 0, stCet = 0, stKorakov = 0;
    vector<int> seznam;
    cin >> stElementov >> stCet >> stKorakov;
    int tmp = 0;

    for (int i = 0; i < stElementov; i++){
        cin >> tmp;
        seznam.push_back(tmp);
    }
    // i -> iterator z vector.begin() + i
    for (int i = 0; i < stKorakov && !is_sorted(seznam.begin(), seznam.end()); i++){
        int j = 0;
        while(j < stElementov){
            int cete = 0;
            int zacetek = j;
            while(cete < stCet && j < stElementov){
                if (seznam[j] > seznam[j+1]){
                    cete++;
                }
                j++;
            }
            sort(seznam.begin() + zacetek, seznam.begin() + j);
        }
    }
    print(seznam);
    return 0;
}