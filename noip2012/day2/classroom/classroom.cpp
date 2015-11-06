//30分
#include <iostream>
using namespace std;
int day[100005], n, m;
void outputState() {
    for ( int i = 1; i <= n; i++ )
        cout << day[i] << ' ';
    cout << endl;
}
int main() {
    int i, k, s, e, j, f;
    bool flag = false;
    cin >> n >> m ;
    for ( i = 1; i <= n; i++ )
        cin >> day[i];
    for ( i = 1; i <= m; i++ ) {
        cin >> k >> s >> e;
        for ( j = s; j <= e; j++ ) {
            day[j] -= k;
            if ( day[j] < 0 ) {
                flag = true;
                break;
            }
        }
        //outputState();
        if ( flag )
            break;
    }
    if ( flag )
        cout << -1 << endl << i << endl;
    else
        cout << 0 << endl;
    return 0;
}
