#include <iostream>
#include <vector>

using namespace std;

vector<int> v[2000005];

int main()
{
    int i, x, y, n, m, s, t;  // N--point  M--side

    // Input
    cin >> n >> m;
    for ( i = 0; i < m; ++i ) {
        cin >> x >> y;
        //v[x].push_back( y );
        
    }
    cin >> s >> t;

    // DFS

    // Print vector
    /*
    for ( i = 1; i <= n; ++i ) {
        for ( int j = 0; j < v[i].size( ); ++j )
            cout << v[i][j] << ' ';
        cout << endl;
    }
    */
    return 0;
}
