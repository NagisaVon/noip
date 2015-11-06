#include <iostream>
using namespace std;
int b[100];

void printbinary( int a ) {
    int d = 0, i;
    while ( a > 0 ) {
    	b[d++] = a % 2;
    	a /= 2;
    }
    for (i = d - 1; i >= 0; i--)
    	cout << b[i];
    cout << endl;
}

int main() {
	int n;
	cin >> n;
	printbinary(n);
	return 0;
}
