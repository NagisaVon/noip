#include <iostream>
#include <cmath>
using namespace std;
int main() {
	float a, b, c;
	cin >> a >> b >> c;
	float ans = ( -b + sqrt( b*b - 4 * a * c ) ) / 2;
	float ans2 = ( -b - sqrt( b*b - 4 * a * c ) ) / 2;
	cout << "x1 = " << ans << endl << "x2 = " << ans2 << endl;
	return 0;
}
