#include <iostream>
#define LENGTH 4
#define WIDTH 4

void transpuesta(const int input[][LENGTH],int output[][WIDTH])
{
    for(int i = 0; i != WIDTH; i++)
        for(int j = 0; j != LENGTH; ++j)
            output[j][i] = input [i][j];
}

int main(void)
{
    
    
    return 0;
}
