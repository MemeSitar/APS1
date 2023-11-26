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

int main(){
    vector<pair<int, int>> graf;
    vector<int> rez;
    int stOtrok, stVpisov;
    int tmp1, tmp2;

    cin >> stOtrok, stVpisov;
    for(int i=0; i < stVpisov; i++){
        cin >> tmp1 >> tmp2;
        graf.push_back(pair(tmp1, tmp2));
    }

    return 0;
}