#include <iostream>

void print_array(const int *arr, const int n)
{
    for(int i = 0; i != n-1; i++)
        std::cout << arr[i] << ", ";
    std::cout << arr[n-1];
}

void reverse(int *arr, const int n)
{
    for(int i = 0; i != n/2; i++){
        int temp = *(arr+n-i-1);
        *(arr+n-i-1) = *(arr+i);
        *(arr+i) = temp;
    }
}

int main(void)
{
    int arr[]={0,1,2,3,4,5,6};
    reverse(arr,7);
    print_array(arr,7);

    
    return 0;
    
}
