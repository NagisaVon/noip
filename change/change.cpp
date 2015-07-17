// noip2002 字串变换
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

struct node {
    int step;
    string str;
};

queue<node> q;
string from[7], to[7], s, t;
bool appear[1000005];
int n;

bool meet( string s, int pos, int plan ) {
     for( int i = 0; i < from[plan].length(); i++ )
          if( s[pos + i] != from[plan][i] )
              return false;
     return true;
}
bool never_appeared( string s ) {
    int v = 0;
    int l = s.length();
    for( int i = 0; i < l; i++ )
        v += (int)s[i] * i;
    if( appear[v] )
        return false;
    else
        appear[v] = true;
    return true;
}

int dfs() {
    int pos, plan;
    string cur;
    node k;
    while( !q.empty() ) {
        if( q.front().step > 10 )
            return -1;
        cur = q.front().str;
        for( pos = 0; pos < cur.length(); pos++ )
            for( plan = 0; plan < n; plan++ )
                if( meet( cur, pos, plan ) ) {
                    k.str = cur.substr( 0, pos   );
                    k.str += to[plan];
                    k.str += cur.substr( pos + from[plan].length() );
                    k.step = q.front().step + 1;
                    if( never_appeared( k.str ) )
                        q.push( k );
                    if( k.str == t )
                        return k.step;
                    cout << cur << endl;
                    cout << "Pos : " << pos << "  plan : " << plan << endl;
                    cout << k.str << " " << k.step << endl << endl;
                }
        q.pop();
   }
   return -1;
}
int main() {
    node k;
    cin >> s >> t;
    k.step = 0;
    k.str = s;
    q.push( k );
    while ( cin >> from[n] >> to[n] )
        n++;

    int result = dfs();
    if ( result == -1 )
        cout << "NO ANSWER!" << endl;
    else
        cout << result << endl;

    return 0;
}
/*
abcd xyz
abc xu
ud y
y yz
*/
