#include <iostream>

void doble_number(int &num) {num *= 2; }

int main(void)
{
    int num = 35;
    doble_number(num);
    std::cout << num;
    
    return 0;
}

