#include <iostream>
#include <utility>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define SEGS printf("%s:%d\n", __FILE__, __LINE__);

void vecprint(vector<int> &sez){
    // se malo razhroscevanja
    for (int stevilka : sez){
        cout << stevilka << "\n";
    }
}

void stackprint(stack<int> st){
    // razhroscevalna funkcija
    cout << "----------------DEBUG----------------\n";
    while(st.size()){
        cout << st.top() << "\n";
        st.pop();
    }
    cout << "----------------DEBUG----------------\n";
}

int main(){
    int n, tmp;
    unsigned long rez = 0;
    vector<int> stolpi;
    stack<int> stek;
    cin >> n;

    // nafilaj vektor
    for (int i = 0; i < n; i++){
        cin >> tmp;
        stolpi.push_back(tmp);
    }


    for (int j = 0; j < 2; j++){
        for (int i = 0; i < n; i++){
            if(stek.empty()){
                stek.push(stolpi[i]);
            } else if (stolpi[i] <= stek.top()){
                rez += stek.size();
                stek.push(stolpi[i]);
            } else if (stolpi[i] > stek.top()){
                while(!stek.empty() && stolpi[i] > stek.top()){
                    stek.pop();
                }
                rez += stek.size();
                stek.push(stolpi[i]);
            }
        }    
        if (j == 0){
            stek = stack<int>();
            reverse(stolpi.begin(), stolpi.end());
        }
    }
    cout << rez << endl;
    return 0;
}