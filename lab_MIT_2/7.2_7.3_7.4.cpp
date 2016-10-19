#include <iostream>

void swapRef(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapPtr(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int **a, int **b)
{
    int *temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int a = 1, b= 2;
    swapRef(a,b);
    swapPtr(&a,&b);
    std::cout << a << '\n';
    
    int x = 5, y = 6;
    int *ptr1 = &x, *ptr2 = &y;
    swap(&ptr1, &ptr2);
    std::cout << *ptr1 << ' ' <<*ptr2;
    
    return 0;
    
}
