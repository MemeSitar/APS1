#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <utility>
using namespace std;

class HashTable {
public:
    vector<vector<pair<int,int>>> t;
    int size, capacity;

    HashTable() {
        size = 0;
        capacity = 1;
        t.resize(capacity);
    }

    int hash(int x) {
        return x % capacity;
    }

    void insert(int k, int v) {
        if (size > capacity){
            rehash();
        }
        int h = hash(k);
        for(auto& [key, value] : t[h]){
            if (key == k){
                value = v; 
                return;
            }
        }
        t[h].push_back({k,v});
        size++;
    }

    int get(int k){
        int h = hash(k);
        for(auto& [key, value] : t[h]){
            if (key == k){
                return value;
            }
        }
        return -1;
    }

    void rehash() { // O(size + capacity)
        capacity *= 2;
        vector<vector<pair<int,int>>> t2(capacity);
        for (int h=0; h<t.size(); h++){
            for (auto& [key, value] : t[h]){
                int h2=hash(key);
                t2[h2].push_back({key, value});
            }
        }
        t = t2;
    }
};

int main(){
    default_random_engine rnd(1234);
    HashTable ht;
    int n=1500;
    for (int i=0; i < n; i++){
        ht.insert(rnd()%n, 1);
    }
    cout << ht.size << " " << ht.capacity << endl;
    double sum = 0;
    int m = 0;
    for (int h=0; h<ht.capacity; h++){
        sum += ht.t[h].size();
        m = max((size_t) m, ht.t[h].size());
    }
    cout << sum/ht.capacity << " " << m << endl;
    return 0;
}