#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int num;
    cin >> num;
    int min = num;
    int max = num;
    int sum = num;

    for (int i = 1; i != n; i++){
        cin >> num;
        if (num < min)
            min = num;
        else if( num > max)
            max = num;
        sum += num;
    }
    double mean = double (sum)/n;
    int range = max-min;

    cout<<"Mean: "<<mean<<"\n";
    cout<<"Max: "<<max<<"\n";
    cout<<"Min: "<<min<<"\n";
    cout<<"Range: "<<range<<"\n";


	return 0;
}

