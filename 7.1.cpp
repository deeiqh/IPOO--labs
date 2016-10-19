#include <iostream>

int longitud(const char *arr)
{
    int lon = 0;
    for(;*arr != '\0';arr++)
        lon++;
    return lon;
}

int main(void)
{
    char arr[] = "holax";
    std::cout << longitud(arr);
    
    return 0;
    
}
