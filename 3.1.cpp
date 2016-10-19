#include <iostream>

void print_num(int);
void print_num2(int number)
{
    std::cout << number;
}

int main(void)
{
    print_num(35);
    std::cout << "\n";
    print_num2(70);
}

void print_num(int number)
{
    std::cout << number;
}