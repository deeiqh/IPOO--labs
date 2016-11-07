#include <iostream>
#include <string>

using namespace std;
const string VOWELS = "aeiou";

string pigLatinify(string);

int main()
{
    string cad;
    cin >> cad;
    cout << pigLatinify(cad);

    return 0;
}

string pigLatinify(string cad)
{
    if (VOWELS.find(cad[0]) == string::npos) {//primera consonante
        if (cad[0] == 'q'){
            return cad.substr(2) + "-" + cad[0] + "uay";
        }
        else{
            return cad.substr(1) + "-" + cad[0] + "ay";
        }
    }
    else{
        return cad + "way";
    }
}
