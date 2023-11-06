#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main() {
    int n, tmp;
    vector<int> vec;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> tmp;
        vec.push_back(tmp);
        sort(vec.begin(), vec.end());
        cout << vec[(vec.size() - 1)/2] << "\n";
    }
    return 0;
}