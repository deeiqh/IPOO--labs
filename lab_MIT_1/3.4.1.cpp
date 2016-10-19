#include <iostream>

using namespace std;

int main(void)
{
    while (true){
        int n;
        cin >> n;
        (n%5 == 0)? (cout << n/5): cout << -1;
    }

    return 0;
}

