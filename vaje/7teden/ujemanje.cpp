#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define SEGS printf("%s:%d\n", __FILE__, __LINE__);

void print(vector<pair<int, int>> sez){
    for(pair<int, int> par : sez){
        if (par.first == -1){
            cout << par.first << "\n";
        } else {
            cout << par.first << " " << par.second << "\n";
        }
    }
    cout.flush();
}

vector<string> splitString(const string& input, char delimiter) {
    vector<string> result;
    size_t start = 0;
    size_t end = input.find(delimiter);
    string substr;

    while (end != string::npos) {
        substr = input.substr(start, end - start);
        if (substr.length() != 0) result.push_back(substr);
        start = end + 1;
        end = input.find(delimiter, start);
    }
    substr = input.substr(start);
    if (substr.length() != 0) result.push_back(substr);

    return result;
}

pair<int, int> ujemanjeBesed(string vzorec, string beseda){
    bool najdeno = true;
    for(int i = 0; i<beseda.length(); i++){
        najdeno = true;
        for(int j = 0; j<vzorec.length(); j++){
            if(!(beseda.at(i+j) == vzorec.at(j)) && !(vzorec.at(j) == '?')){
                najdeno = false;
                break;
            }
        }
        if (najdeno == true){
            return pair<int, int>(i, i+vzorec.length());
        }
    }
    return pair<int, int>(-1, 0);
}

pair<int, int> ujemanje(string vzorec, string beseda){
    vector<string> strv = splitString(vzorec, '*');
    pair<int, int> rez(0, 0);
    int dolzina = 0;

    for(string str : strv){
        
    }

    return rez;
}

int main(){
    vector<pair<int, int>> rez;
    int stNizov;
    string vzorec, beseda;

    cin >> stNizov;
    for(int i=0; i<stNizov; i++){
        cin >> vzorec >> beseda;
        rez.push_back(ujemanje(vzorec, beseda));
    }

    print(rez);
}