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
    Dijkstra(graf, 0, dist, prev);
    vector<int> pot;
    int x = prev.size() - 1;
    while(x != 0){
        pot.push_back(prev.at(x));
        x = prev.at(x);
    }

    // gremo cez vse povezave po poti, in jih poskusimo odstraniti.



    return 0;
}