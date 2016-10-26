#include <iostream>

using namespace std;

int main(void)
{
    while (true){
        int n;
        cin >> n;
        if (n<0){
            cout << "Goodbye!";
            break;
        }
        else {
            if (n%5 == 0)
                cout << n/5;
            else
                continue;
        }

    }
    return 0;
}

