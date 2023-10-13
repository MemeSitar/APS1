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
    for (int j=0; j<n; j++) {
        for (int i=0; i+1<n; i++){
            if (sez[i] > sez[i+1]){
                swap(sez[i], sez[i+1]);
            }
        }
    }
}

vector<int> merge(vector<int> &a, vector<int> &b) {
    int i=0, j=0;
    vector<int> c;

    while (i<a.size() || j<b.size()) {
        if (i<a.size() && j<b.size()) {
            if (a[i]<b[j]) c.push_back(a[i++]);
            else c.push_back(b[j++]);
        } else if (i<a.size()) c.push_back(a[i++]);
        else c.push_back(b[i++]);
    }
    return c;
}

vector<int> merge_sort(vector<int> &sez) {
    int n=sez.size();
    if (n<=1) return sez;
    vector<int> levo(sez.begin(), sez.begin()+n/2);
    vector<int> desno(sez.begin()+n/2, sez.end());
    levo = merge_sort(levo);
    desno = merge_sort(desno);
    return merge(levo, desno);
}

int main() {
    //vector<int> sez = {9,4,2,8,7,5};
    //print(sez);
    //sez = merge_sort(sez);
    //print(sez);

    vector<int> sez;
    default_random_engine rnd(123);
    for(int i = 0;i<10000; i++) sez.push_back(rnd()%1000000);
    sez = merge_sort(sez);
    return 0;
}