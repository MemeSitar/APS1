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
    int rez = 0;
    vector<int> stolpi;
    stack<int> stek;
    cin >> n;

    // nafilaj vektor
    for (int i = 0; i < n; i++){
        cin >> tmp;
        stolpi.push_back(tmp);
    }

    // loop iz leve strani
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
    
    // obrnemo stolpe in se enkrat konstruktamo (prazen) stek
    reverse(stolpi.begin(), stolpi.end());
    stek = stack<int>();

    // loop iz desne strani
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

    cout << rez << endl;
    return 0;
}