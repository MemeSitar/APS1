#include <utility>
#include <iostream>
#include <vector>

using namespace std;

void print(vector<pair<int, int>> &sez){
    for (pair<int, int> luc : sez){
        cout << luc.first << " " << luc.second << endl;
    }
}

int main() {
    int stLuci = 0, dolzina = 0;
    int koordinataLuci = 0, svetlost = 0;
    int leva = 0, desna = 0;
    vector<pair<int, int>> intervali;
    vector<pair<int, int>> luci;

    cin >> dolzina >> stLuci;
    int neosvetljene = dolzina;

    // Zapolni celoten array z lucmi in jih uredi.
    for (int i = 0; i < stLuci; i++){
        cin >> koordinataLuci >> svetlost;
        if (svetlost == 0)
            continue;

        if (luci.size() == 0){
            luci.push_back(pair<int, int>(koordinataLuci, svetlost));
        } else if ((luci.end()-1)->first < koordinataLuci){
            luci.push_back(pair<int, int>(koordinataLuci, svetlost));
        } else {
            for (auto iter = luci.begin(); iter != luci.end(); ++iter){
                if (iter->first == koordinataLuci){
                    if (iter->second < svetlost){
                        iter->second = svetlost;
                    }
                    break;
                }
                if (iter->first > koordinataLuci){
                    luci.insert(iter, pair<int, int>(koordinataLuci, svetlost));
                    break;
                }
            }
        }
    }
    printf("-------------------\n");
    print(luci);
    printf("-------------------\n");

    for (pair<int, int> luc : luci){
        leva = max(luc.first - luc.second, 0);
        desna = min(luc.first + luc.second, dolzina - 1);
        if (intervali.size() == 0){
            intervali.push_back(pair<int, int>(leva, desna));
        } else if ((intervali.end()-1)->second < leva){
            intervali.push_back(pair<int, int>(leva, desna));
        } else {
            for (auto iter = intervali.begin(); iter != intervali.end(); ++iter){
                if (iter->first > leva){
                    luci.insert(iter, pair<int, int>(leva, desna));
                    break;
                }
            }
        }
    }

    print(intervali);
    printf("mjau\n");
    // Prestej neosvetljene dele
    for (pair<int, int> interval : intervali){
        neosvetljene -= interval.second - interval.first;
    }

    cout << neosvetljene << endl;
}