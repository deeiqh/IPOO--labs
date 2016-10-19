#include <iostream>

int sum(const int *arr, const int n)
{
    int sum = 0;
    for(int i = 0; i != n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(void)
{
    int arr[]={1,2,3,4,5,6};
    std::cout << sum(arr,6);
    
    return 0;
}

