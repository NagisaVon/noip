#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if ( a % b == 0 )
        return b;
    else
        return gcd( b, a % b );
    return;
}

int main() {
    int a, b, t;
    cin >> a >> b;
    if ( a < b ) {
        t = a;
        a = b;
        b = t;
    }
    cout << gcd( a, b ) << endl;
    return 0;
}
