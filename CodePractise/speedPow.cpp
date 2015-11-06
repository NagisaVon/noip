#include <iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	long long ans = 1, base = a;
	while( b > 0 ) {
		if ( b & 1 ) 
			ans *= base;
		base *= base;
		b >>= 1;
	}
	cout << ans << endl;

	return 0;
}
