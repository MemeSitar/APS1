#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

/*
Tale program da bi se sam implementiral merge sort, ampak glede na to da std::sort dela...
*/

void print(vector<int> &sez){
    for (int stevilka : sez){
        cout << stevilka << endl;
    }
}

// debug print
void printVec(vector<vector<int>> &sez){
    for (vector<int> seznamcek : sez){
        cout << "[";
        for (int stevilka : seznamcek){
            cout << stevilka << ",";
        }
        cout << "]\n";
    }
}

vector<int> merge_sort(int k){
    vector<int> rezultat;
    for (int i = 0; i < k; i++){

    }
}

int main(){
    int stElementov = 0, stCet = 0, stKorakov = 0;
    vector<vector<int>> seznam;
    cin >> stElementov >> stCet >> stKorakov;
    int tmp = 0, prejsnji = 0, noCete = 0;

    for (int i = 0; i < stElementov; i++){
        cin >> tmp;
        if (seznam.size() == 0){
            seznam.push_back(vector<int>());
            prejsnji = tmp;
        }
        if (tmp < prejsnji){
            seznam.push_back(vector<int>());
            noCete++;
        }
        seznam[noCete].push_back(tmp);
        prejsnji = tmp;
    }

    printVec(seznam);
    // i -> iterator z vector.begin() + i
    /*for (int i = 0; i < stKorakov && !is_sorted(seznam.begin(), seznam.end()); i++){
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
    }*/

    //print(seznam[0]);
    return 0;
}