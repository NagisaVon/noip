#include <iostream>
using namespace std;
int q[20005];
int main()
{
    int n, i, s = 1;
    /* INPUT */
    cin >> n;
    /* BFS */
    q[1] = 1;
    cout << "1 ";
    int h, r = 1, a, b;
    for ( h = 1; h <= r; ++h ) {
        a = q[h] * 3 + 1;
        b = q[h] * 4 + 1;
        if ( a <= n ) {
            q[++r] = a;
            cout << a << ' ';
            ++s;
        }
        else
            break;
        if ( b <= n ) {
            q[++r] = b;
            cout << b << ' ';
            ++s;
        }
        else
            break;
    }
    cout << endl << s << endl;
    return 0;
}
