#include <iostream>


int sum(int *arr, int n)
{
    int suma;
    if (n==1)
        return arr[0];
    else               
        suma = arr[0] + sum(arr+1,n-1);
    return suma;
}

int main(void)
{
    int arr[]={1,2,3,4,5,6};
    std::cout << sum(arr,6);
    
    return 0;
}

