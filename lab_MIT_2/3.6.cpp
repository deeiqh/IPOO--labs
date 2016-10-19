#include <iostream>
const int ARRAY_LEN = 10;

int main(void)
{
    int arr[ARRAY_LEN] = {10};
    int  *dir_x = arr, *dir_y = arr + ARRAY_LEN -1;
    std::cout << *dir_x << " " << *dir_y;
    return 0;
    
}