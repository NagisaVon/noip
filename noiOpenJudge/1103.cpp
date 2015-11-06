#include <iostream>
#include <cstdio>
using namespace std;

/*  
int getLength( int t ) {
	int ans = 0;
	if ( t < 0 )
		ans = 1;

	do
	{
		t /= 10;
		ans ++;
	}while( t > 0 );
	return ans;
}

void printItEightDigit( int k ) {
	int l;
	l = getLength( k );
	if ( l < 8 ) {
		int e = 8 - l;
		for ( int i = 0; i < e; i++ )
			cout << ' ' ;
		cout << k << ' ';
	}
	else
		cout << k << ' ';
}
int main() {
	int t, l;
	for ( int i = 0; i < 2; i++ ) {
		cin >> t;
		l = getLength( t );
		if ( l < 8 ) {
			int e = 8 - l;
			for ( int i = 0; i < e; i++ )
				cout << ' ' ;
			cout << t << ' ';
		}
		else
			cout << t << ' ';
	}
	cin >> t;
	l = getLength( t );
	if ( l < 8 ) {
		int e = 8 - l;
		for ( int i = 0; i < e; i++ )
			cout << ' ' ;
		cout << t;
	}
	else
		cout << t;
	cout << endl;
	return 0;
}*/

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	printf("%8d %8d %8d", t);
	return 0;
}
