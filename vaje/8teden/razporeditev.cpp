#include <iostream>
#include <vector>
using namespace std;
#define SEGS printf("%s:%d\n", __FILE__, __LINE__);

void print(vector<int> sez){
    for(int stev : sez){
        cout << stev << "\n";
    }
    cout.flush();
}

void izpisiSosede(vector<vector<int>> &sosedi){
    for(int i = 0; i < sosedi.size(); i++){
        cout << i + 1 << " -> ";
        for(int sosed : sosedi.at(i)){
            cout << sosed + 1 << ", ";
        }
        cout << endl;
    }
}

void izpisiSosedeBarve(vector<vector<int>> &sosedi, vector<int> &barve){
    for(int i = 0; i < sosedi.size(); i++){
        cout << i + 1 << "(" << barve[i] <<  ") -> ";
        for(int sosed : sosedi.at(i)){
            cout << sosed + 1 << "(" << barve[sosed] << "), ";
        }
        cout << endl;
    }
}

void inline dodaj(vector<vector<int>> &tabelaSosedov, int a, int b){
    tabelaSosedov[a - 1].push_back(b - 1);
    tabelaSosedov[b - 1].push_back(a - 1);
}

void farbej(vector<int> &barve, vector<vector<int>> &sosedi, int trenuten, int barva){
    int novaBarva;
    if(barve[trenuten] == 0){
        barve[trenuten] = barva;
        novaBarva = (barva == 1) ? 2 : 1;
        for(int sosed : sosedi[trenuten]){
            if(!(barve[sosed] == novaBarva)){
                farbej(barve, sosedi, sosed, novaBarva);
            }
        }
    } else if(barve[trenuten] == barva){
        return;
    } else {
        cout << -1 << endl;
        exit(0);
    }
}

int main(){
    int stOtrok, stVpisov;
    int tmp1, tmp2;
    cin >> stOtrok >> stVpisov;
    vector<vector<int>> sosedi(stOtrok);
    vector<int> barve(stOtrok);
    for(int i=0; i < stVpisov; i++){
        cin >> tmp1 >> tmp2;
        dodaj(sosedi, tmp1, tmp2);
    }

    /*for(int i=0; i < stOtrok; i++){
        if(barve[i] == 0 || barve[i] == 1){
            barve[i] = 1;
            for(int otrok : sosedi[i]){
                if(barve[otrok] == 0){
                    barve[otrok] = 2;
                } else if (barve[otrok] == 1){
                    cout << "-1" << endl;
                    exit(0);
                }
            }
        } else if(barve[i] == 2){
            for(int otrok : sosedi[i]){
                if(barve[otrok] == 0){
                    barve[otrok] = 1;
                } else if (barve[otrok] == 2){
                    cout << "-1" << endl;
                    exit(0);
                }
            }
        }

    }*/
    for(int i=0; i < stOtrok; i++){
        if(barve[i] == 0){
            farbej(barve, sosedi, i, 1);
        }
    }
    //izpisiSosedeBarve(sosedi, barve);

    print(barve);
    return 0;
}