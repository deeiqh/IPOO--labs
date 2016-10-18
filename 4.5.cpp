#include <iostream>

using namespace std;

int main(void)
{
    short number;
    cout << "Enter a number: ";
    cin >> number;

    switch (number){
        case 1:  cout <<  "1\n";break;
        case 2:   cout <<  "2\n";break;
        case 3:   cout <<  "6\n";break;
        case 4:  cout <<  "24\n"; break;
        case 5:   cout <<  "120\n";break;
        case 6: cout <<  "720\n";break;
        case 7:
                int acumulador = 1;
                for(;number > 0; acumulador *= number--);
                cout << acumulador << "\n";
                break;
    }

    return 0;
}

