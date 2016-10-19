#include <iostream>
#include <cstdlib>

int difference(const int x, const int y)
{
    return abs(x-y);
}

int main(void)
{
    std::cout << difference(24, 1238);
    return 0;
}