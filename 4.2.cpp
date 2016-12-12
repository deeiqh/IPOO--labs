#include <iostream>

using namespace std;

int main(void)
{
    short number;
    cout << "Enter a numero: ";
    cin >> number;

    if (number <= 0)
        cout << "No existe";
    else{
        cout << "El factorial de " << number << " is ";
        int acumulador = 1;
        for(;number > 0; acumulador *= number--);
        cout << acumulador << ".\n";
    }
    return 0;
}

