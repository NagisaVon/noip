#include <iostream>
using namespace std;
long long a, b, x, y;

// Return the result of the simple gcd
long long extended_gcd( long long a, long long b, long long &x, long long &y ) {
	if ( b == 0 ) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		long long ans = extended_gcd( b, a % b, x, y );
		long long t=x; 
		x=y;
		y=t-(a/b)*y;
		return ans;
	}
} 

int main() {
	cin >> a >> b;
	extended_gcd( a, b, x, y );// return solve a pair of (x, y)
	
	x %= b;
	while( x < 0 )
		x += b;
	cout << x << endl;

	return 0;
}
