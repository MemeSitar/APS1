#include <map>
#include <set>
#include <algorithm>
#include <random>
#include <iostream>
using namespace std;

void print(vector<int> sez){
    for (int x : sez) cout << x << " ";
    cout << endl;
}

void selection_sort(vector<int> &sez) {
    int n=sez.size();
    for (int i=0; i<n; i++){
        int m=i;
        for (int j=i; j<n; j++){
            if (sez[j] <sez[m]){
                m = j;
            }
        }
        swap(sez[i], sez[m]);
    }
}

void insertion_sort(vector<int> &sez) {
    int n=sez.size();
    for (int i=0; i<n; i++){
        int x=sez[i];
        int j=i-1;
        while (j>=0 && sez[j]>x){
            sez[j+1] = sez[j];
            j--;
        }
        sez[j+1] = x;
    }
}

void bubble_sort(vector<int> &sez) {
    int n=sez.size();
    bool change=true;
    while (change) {
        change = false;
        for (int i=0; i+1<n; i++){
            if (sez[i] > sez[i+1]){
                swap(sez[i], sez[i+1]);
                change = true;
            }
        }
    }
}

int main() {
    vector<int> sez = {9,4,2,8,7,5};
    print(sez);
    bubble_sort(sez);
    print(sez);
    return 0;
}