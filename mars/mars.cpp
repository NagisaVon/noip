#include <iostream>
#include <algorithm>

using namespace std;

int a[10005];
int main()
{
    
    int i, n, m;
    cin >> n >> m;

    for ( i = 0; i < n; i++ )
        cin >> a[i];

    for ( i = 0; i < m; i++ )
        next_permutation( a, a + n );

    for ( i = 0; i < n; i++ )
        cout << a[i] << ' ';
    cout << endl;
    return 0;

}
