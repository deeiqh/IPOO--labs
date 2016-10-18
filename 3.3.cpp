#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int cant = 0;

    if (n <= 2){
                cout << 1 <<"\n";
                cout << 2 <<"\n";
                cant += 2;
    }
    else{
        cout << 1 <<"\n";
        cout << 2 <<"\n";
        cant += 2;
        int i;
        for (i = 3; i != n+1; i++){
            int primo = 0;
            int j;
            for (j = 2; j != i; j++){
                    if (i%j == 0){
                        primo = 0;
                        break;
                    }else
                        primo = 1;
            }
            if (primo){
                      cant +=1;
                      cout << j <<"\n";
            }
        }
        cout<<"cantidad "<< cant;
    }
    return 0;

}

