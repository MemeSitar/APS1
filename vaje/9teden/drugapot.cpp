#include <iostream>
#include <vector>
using namespace std;
typedef vector<pair<int,int>> VII;

// iz predavanj
void Dijkstra(vector<VII> &adjw, int start, vector<int> &dist, vector<int> &prev) {
    int n=adjw.size();
    dist=vector<int>(n,-1); prev=vector<int>(n,-1);
    vector<int> p(n,-1);  // provisional distance (-1=unvisited, -2=done)
    p[start]=0;
    while (1) {
        int x=-1;  // smallest provisional
        for (int i=0;i<n;i++) if (p[i]>=0) {
            if (x==-1 || p[i]<p[x]) x=i;
        }
        if (x==-1) break;
        dist[x]=p[x]; p[x]=-2;
        for (auto [y,w] : adjw[x]) {  // update neighbors
            int d=dist[x]+w;
            if (p[y]==-1 || (p[y]>=0 && d<p[y])) { 
                p[y]=d; prev[y]=x; 
            }
        }
    }
}

int main(){
    vector<int> dist, prev;
    int stVozl, stPovez;
    int n1, n2, w;
    cin >> stVozl >> stPovez;
    vector<VII> graf(stVozl);
    // napolnimo graf z vhodom
    for(int i=0; i<stPovez; i++){
        cin >> n1 >> n2 >> w;
        graf[n1].push_back({n2, w});
        graf[n2].push_back({n1, w});
    }

    // poiscemo najkrajso pot, od zadaj naprej.
    int najkrajsa;
    Dijkstra(graf, 0, dist, prev);
    najkrajsa = dist.back();
    vector<int> pot;
    int x = prev.size() - 1;
    while(x != 0){
        pot.push_back(prev.at(x));
        x = prev.at(x);
    }

    // gremo cez vse povezave po poti, in jih poskusimo odstraniti.
    int utez = 0;
    int tmp = __INT_MAX__;
    bool niDruge = true;
    for(int i=0;i<pot.size()-1;i++){
        n1 = pot.at(i);
        n2 = pot.at(i+1);

        // najprej odstrani to povezavo, pri obeh
        for(int j=0; j<graf[n1].size(); j++){
            if(graf[n1][j].first == n2){
                utez = graf[n1][j].second;
                graf[n1].erase(graf[n1].begin() + j);
                break;
            }
        }
        for(int j=0; j<graf[n2].size(); j++){
            if(graf[n2][j].first == n1){
                graf[n2].erase(graf[n2].begin() + j);
                break;
            }
        }

        // potem izvedi dijkstra
        dist.clear();
        prev.clear();
        Dijkstra(graf, 0, dist, prev);
        if(dist.back() == najkrajsa || dist.back() == najkrajsa + 1){
            cout << dist.back() << endl;
            exit(0);
        } else if(dist.back() != -1 && dist.back() < tmp){
            niDruge = false;
            tmp = dist.back();
        }

        // potem dodaj to povezavo nazaj in pojdi na naslednjo.
        graf[n1].push_back({n2, utez});
        graf[n2].push_back({n1, utez});
    }
    if(niDruge){
        cout << "-1" << endl;
    } else {
        cout << tmp << endl;
    }


    return 0;
}