#include <iostream>

int main(void)
{
    char *oddOrEven = "Never odd or  even";

    char *nthCharPtr = &oddOrEven[5];
    std::cout << *nthCharPtr << '\n';
    
    nthCharPtr -= 2;
    std::cout << *nthCharPtr << '\n';
    
    char **pointerPtr = &nthCharPtr;
    
    std::cout << pointerPtr << '\n';
    
    std::cout << **pointerPtr << '\n';

    nthCharPtr++;
    
    std::cout << nthCharPtr - oddOrEven << '\n';
    
    return 0;
    
}
