#include<iostream>

using namespace std;

int never_appeared( string s ) {
    int v = 0;
    int l = s.length();
    for( int i = 0; i < l; i++ )
        v += (int)s[i];
    return v;
}
int main() {
    string s;
    cin >> s;
    cout << never_appeared( s ) << endl;

    return 0;
}
