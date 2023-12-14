#include <iostream>
#include <vector>
using namespace std;
#define SEGS printf("%s:%d\n", __FILE__, __LINE__);

void izpisiOtok(vector<vector<int>> &map, int v, int s){
    for(int i=0; i<v; i++){
        for(int j=0; j<s; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void vecprint(vector<int> &sez){
    for (int stevilka : sez){
        cout << stevilka << "\n";
    }
    cout.flush();
}

int preveriSosede(vector<vector<int>> &barve, int i, int j){
    // tukaj bo treba narediti bounds checking!!

    return -1;
}

int main(){
    int v, s, tmp;
    int naj = 0;
    cin >> v >> s;
    vector<vector<int>> map(v, vector<int>(s));
    // napolnimo 2d predstavitev in najdemo naj
    for(int i=0; i<v; i++){
        for(int j=0; j<s; j++){
            cin >> tmp;
            map[i][j] = tmp;
            naj = (tmp > naj) ? tmp : naj;
        }
    }
    // seznam za predstavitev s koordinatami
    vector<vector<pair<int, int>>> koordinate(naj + 1);
    for(int i=0; i<v; i++){
        for(int j=0; j<s; j++){
            // v zunanji vektor ki hrani za visino map[i][j] dodamo urejen par(i, j)
            koordinate[map[i][j]].push_back(pair(i, j));
        }
    }

    // seznam za izpis
    vector<int> sez(naj + 1);
    // barve sele tukaj postanejo vazne
    vector<vector<int>> barve(v, vector<int>(s));

    // spuscamo gladino vode (i) + se sprehodimo cez vse ki smo odkrili (koordinate[i])
    int stevecBarv = 1;
    for(int i=naj; i>0; i--){
        int stOtokov = 0;
        // za vse na tem nivoju preverimo, ce imajo sosede ki so ze pobarvani
        // ce ne, jih pobarvamo z novo barvo.
        for(pair<int, int> koord : koordinate[i]){
            int rez = preveriSosede(barve, koord.first, koord.second);
            if(rez == -1){
                barve[koord.first][koord.second] = stevecBarv;
                stevecBarv++;
            } else {
                barve[koord.first][koord.second] = rez;
            }
        }
        // tukaj prestejemo otoke??
        
        //izpisiOtok(barve, v, s);
        //cout << "-------------\n";
        sez[i] = stOtokov;
    }

    // konec
    vecprint(sez);
}