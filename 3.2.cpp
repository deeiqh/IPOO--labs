#include <iostream>

int number = 35;

void print_num() {std::cout << number; };
void print_num2(int number2) //mejor opcion, no considera la variable global
{
    std::cout << number2;
}

int main(void)
{
    
    print_num();
    std::cout << "\n";
    int number2 = 70;
    print_num2(number2);
    
    return 0;
}

