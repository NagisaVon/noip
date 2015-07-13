#include <iostream>
using namespace std;
int q[20005], p[205], s[20005];
bool appear[205];
int main()
{
    int n, a, b, i, min = 200000;
    /* INPUT */
    cin >> n >> a >> b;
    for ( i = 1; i <= n; ++i )
        cin >> p[i];
    /* BFS */
    q[1] = a;
    s[1] = 0;
    int h, r = 1, up, down;
    for ( h = 1; h <= r; ++h )
    {
        if ( q[h] == b )
            if ( s[h] < min ) 
                min = s[h];
        up = q[h] + p[q[h]];
        down = q[h] - p[q[h]];
        if ( up <= n && !appear[up]) {
            q[++r] = up;
            s[r] = s[h] + 1;
            appear[up] = true;
        }
        if ( down > 0 && !appear[down]) {
            q[++r] = down;
            s[r] = s[h] + 1;
            appear[down] = true;
        }
    }
    if ( min != 200000 )
        cout << min << endl;
    else
        cout << -1 << endl;
    return 0;
}
