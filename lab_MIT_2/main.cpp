#include <iostream>
using namespace std;

void print_n_times(const char *, int n = 2);
void print(const int &);

int main(void)
{
    print_n_times("Lapadula\n");    
   
    for(char v: {'0','1','2','3','4'})
        cout << v;
    cout << "\n";
    int x = 5;
    print(x); // como el prototipo dice &, el paso es por referencia (el valor en si, no hay duplicado)
    
    return 0;
}

void print_n_times(const char* msg, int n)
{
    for(int i = 0; i != n; i++){
        cout << msg;
    }
}

void print(const int &x)
{
    cout << x <<"\n";
}