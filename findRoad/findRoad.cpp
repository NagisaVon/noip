#include < iostream >
#include < vector >
#include < queue >

using namespace std;

int n, m, s, t;
vector < int > v[ 2000005 ];
vector < int > rv[ 2000005 ];
bool reachable[ 2000005 ];

int dfs_check_reachable ( ) {
    int j, f;
    queue < int > q;
    q.push ( t );
    reachable[ t ] = true;
    while ( !q.empty ( ) ) {
        j = q.top( );
        for ( int i = 0; i < rv[j].size( ); i++ ) {
            q.push( rv[j][i] );
            
    }


}

int dfs ( ) {
}


int main ( ) {
    int i, x, y;  // N--point  M--side

    // Input
    cin >> n >> m;
    for ( i = 0; i < m; ++i ) {
        cin >> x >> y;
        if ( x == y )
            continue;
        v[ x ].push_back( y );
        rv[ y ].push_back( x );
    }
    cin >> s >> t;

    
    // DFS
    
    dfs_check_reachable ( );
    dfs ( );
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
