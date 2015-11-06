#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
string M, C, key;
bool oLower[1005];
int findIndex( char charK, char charC ) {
	int k = charK - 65, c = charC - 65 + 1;
	int pos = c - k;
	if(pos <= 0) 
		pos += 26;
	return pos - 1;
}
int main ( int argc, char *argv[] )
{
	//char a, b;
	//cin >> a >> b;
	//cout << findIndex( a, b );

	cin >> key >> C;
	int i, keyLength = key.length();

	for ( i = 0 ; i < keyLength; i++ )
		if (key[i] >= 'a' )
			key[i] -= 32;
	for ( i = 0 ; i < C.length(); i++ )
		if ( C[i] >= 'a' ) {
			oLower[i] = true;
			C[i] -= 32;
		}
	int j = 0;
	char k, t;
	for ( i = 0; i < C.length(); i++) {
		k = key[j];
		if ( ++j > keyLength - 1 )
			j = 0;
		M += findIndex( k, C[i] ) + 'A';
		if( oLower[i] )
			M[i] += 32;
	}
	cout << M << endl;
	return EXIT_SUCCESS;
}		
