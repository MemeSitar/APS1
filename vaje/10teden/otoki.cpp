#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define SEGS printf("%s:%d\n", __FILE__, __LINE__);

class DisjointSet2 {  // Union-Find
public:
    vector<vector<int>> size;
    vector<vector<pair<int, int>>> parent;

    DisjointSet2(int x, int y) {
        parent = vector<vector<pair<int, int>>>(x, vector<pair<int, int>>(y, pair<int, int>(0, 0)));    
        size = vector<vector<int>>(x, vector<int>(y, 1));
        for (int i=0;i<x;i++) {
            for (int j=0;j<y;j++){
                parent[i][j] = {i, j}; // we do not need to set the size, it's already default 1.
            }
        }
    }
    
    pair<int, int> root(pair<int, int> k) {  // find
        if (parent[k.first][k.second] == pair<int, int>(k.first, k.second)) return parent[k.first][k.second];  // reached the root        
        pair<int, int> r = root(parent[k.first][k.second]);
        parent[k.first][k.second] = r;  // path compression
        return r;
    }

    int join(pair<int, int> x, pair<int, int> y) {  // union by size
        x=root(x); y=root(y);  // replace by roots
        if (x==y) return 0;
        if (size[x.first][x.second]>size[y.first][y.second]) swap(x,y);  // make x smaller
        parent[x.first][x.second] = y;  // attach to larger root
        size[y.first][y.second] += size[x.first][x.second];
        return -1;
    }
};

void izpisiOtok(vector<vector<int>> &map, int v, int s){
    for(int i=0; i<v; i++){
        for(int j=0; j<s; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void vecprint(vector<int> &sez){
    int i = 0;
    for (int stevilka : sez){
        cout << stevilka << "\n";
    }
    cout.flush();
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
            koordinate[map[i][j]].push_back({i, j});
        }
    }

    DisjointSet2 set(v, s);

    // seznam za izpis
    vector<int> sez(naj + 1);

    // spuscamo gladino vode (i) + se sprehodimo cez vse ki smo odkrili (koordinate[i])

    int stOtokov = 0;
    for(int i=naj; i>0; i--){
        for(auto koord : koordinate[i]){
            stOtokov++;
            if(koord.first + 1 < v && map[koord.first + 1][koord.second] >= i){
                stOtokov += set.join(koord, {koord.first + 1, koord.second});
            }
            if(koord.first - 1 >= 0 && map[koord.first - 1][koord.second] >= i){
                stOtokov += set.join(koord, {koord.first - 1, koord.second});
            }
            if(koord.second + 1 < s && map[koord.first][koord.second + 1] >= i){
                stOtokov += set.join(koord, {koord.first, koord.second + 1});
            }
            if(koord.second - 1 >= 0 && map[koord.first][koord.second - 1] >= i){
                stOtokov += set.join(koord, {koord.first, koord.second - 1});
            }
        }
        sez[i - 1] = stOtokov;
    }

    // konec
    vecprint(sez);
}