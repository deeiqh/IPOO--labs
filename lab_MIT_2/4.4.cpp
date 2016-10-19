#include <iostream>

int sum(const int a,const int b,const int c = 0,const int d = 0){return a+b+c+d;};

int main(void)
{
    std::cout << sum(1,2,3);
    
    return 0;
}
