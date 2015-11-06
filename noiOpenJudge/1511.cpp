#include <iostream>
using namespace std;
int main() {
	int a, n;
	cin >> a >> n;
	int i;
	long long s = 1;
	for ( i = 0; i < n; i++ )
		s *= a;
	cout << s << endl;
	return 0;
}
