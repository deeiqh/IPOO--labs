#include <iostream>

int sum_int(const int a, const int b){ return a+b;};
int sum_int(const int a, const int b, const int c){ return a+b+c;};
int sum_int(const int a, const int b, const int c, const int d){ return a+b+c+d;};
double sum_do(const double a, const double b){ return a+b;};

int main(void)
{
    std::cout << sum_int(1,2,3) << '\n';
    std::cout << sum_do(1.0,2.0);
}
