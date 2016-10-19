#include <iostream>

void print_array(const int *arr, const int n)
{
    for(int i = 0; i != n-1; i++)
        std::cout << arr[i] << ", ";
    std::cout << arr[n-1];
}

int main(void)
{
    int arr[]={0,1,2,3,4,5};
    print_array(arr,6);
    
    return 0;
    
}
