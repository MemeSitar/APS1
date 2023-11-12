#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <random>
#include <queue>
using namespace std;

#define SEGS printf("%s:%d\n", __FILE__, __LINE__);

void print(vector<int> &sez){
    for (int stevilka : sez){
        cout << stevilka << "\n";
    }
}

int main() {
    int n, tmp;
    int mediana = -1;
    vector<int> vec;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;

    // Vse kar je vecje od mediane gre v minheap
    // vse kar je manjse gre v maxheap
    for (int i = 0; i < n; i++){
        cin >> tmp;
        if (tmp >= mediana){
            minHeap.push(tmp);
        } else if (tmp < mediana){
            maxHeap.push(tmp);
        }
        // rebalance
        if (((int)minHeap.size() - (int)maxHeap.size()) >= 2){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else if (((int) maxHeap.size() - (int)minHeap.size()) >= 2){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // izbira mediane
        if (((int)minHeap.size() - (int)maxHeap.size()) >= 1){
            mediana = minHeap.top();
        } else if ((int) maxHeap.size() - (int)minHeap.size() >= 0){
            mediana = maxHeap.top();
        }
        vec.push_back(mediana);
    }
    print(vec);
    cout.flush();
    return 0;
}