#include <iostream>

using namespace std;

int main(void)
{
	const char *hw = "Hola, mund";
	int n;
	cin >> n;
	int i;
	for (i = 0; i != n; i++){
		cout << hw <<"\n";
	}
	i=0;
	while (i != n){
        cout << hw <<"\n";
        i++;
	}
	i=0;
	do{
        cout << hw <<"\n";
        i++;
	} while (i<n);

	return 0;
}

