#include <utility>
#include <iostream>

using namespace std;

int main() {
    int koordinataLuci = 0;
    int svetlost = 0;
    int stLuci = 0;
    int dolzina = 0;

    cin >> dolzina >> stLuci;
    int neosvetljene = dolzina;

    bool* ulica = (bool*) calloc(dolzina, 1);
    for (int i = 0; i < stLuci; i++){
        cin >> koordinataLuci >> svetlost;

        if (svetlost == 0)
            continue;
        
        for (int i = koordinataLuci - svetlost; i < koordinataLuci + svetlost; i++){
            if (i >= dolzina)
                break;
            if (i < 0)
                continue;
            if (ulica[i] == false){
                ulica[i] = true;
                neosvetljene--;
            }
        }
    }

    cout << neosvetljene << "\n";
}