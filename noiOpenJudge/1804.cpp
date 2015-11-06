#include <iostream>
using namespace std;
int n, x[101], y[101];
int main() {
	
	cin >> n;
	int i, j, t;
	for ( i = 0; i < n; i++ ) {
		for( j = 0; j < n; j++ ) {
			cin >> t;
			if ( t == 1 ) {
				x[i]++;
				y[j]++;
			}
		}
	}
	int jsx = 0, jsy = 0, errx, erry;
	for ( i = 0; i < n; i++ ) {
		if ( x[i] % 2 != 0) {
			jsx ++;
			errx = i;
		}
		if ( y[i] % 2 != 0) {
			jsy ++;
			erry = i;
		}
	}
	if ( jsx == 0 && jsy == 0 ) {
		cout << "OK" << endl;
		return 0;
	}
	if ( jsx > 1 || jsy > 1 ) {
		cout << "Corrupt" << endl;
		return 0;
	}
	cout << errx + 1 << ' ' << erry + 1 << endl;
	return 0;
}
