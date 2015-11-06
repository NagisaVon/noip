#include <iostream>
using namespace std;

void printbinary( int a ) {
    int d = 0, i, b[100];
    while ( a > 0 ) {
    	b[d++] = a % 2;
    	a /= 2;
    }
    for (i = d - 1; i >= 0; i--)
    	cout << b[i];
    cout << endl;
}


int main() {

	int a;
	cin >> a;
	/*  printbinary( a );
	
	while ( a > 0 ) {
		cout << (a & 1) << endl;
		a >>= 1;
		//printbinary( a );
	} */
	a >>= 1;
	cout << a << endl;
	a >>= 1;
	cout << a << endl;

	return 0;
}
