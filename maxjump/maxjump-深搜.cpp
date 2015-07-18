// 6 * 6 的棋盘，马从 s( x, y ) 开始，问最多跳多少步 ？ 求路径和步数 （国际跳棋）
#include<iostream>

using namespace std;

int l[10][10];
pair<int, int> road[40];
bool appeared[10][10], win;
int d[8][2] = { -1, -2, -2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2 };
bool can_go( pair<int, int> point ) {
    if( point.first > 0 && point.first <= 6 && point.second > 0 && point.second <= 6 )
        return true;
    else
        return false;
}
void go( pair<int, int> now, int len ) {

    if( len == 36 ) {
        win = true;
        road[len] = now;
    }
    
    if( win )
        return;
    else
        road[len] = now;

    int i;
    pair<int, int> r;
    for( i = 0; i < 8; i++ ) {
         r.first = now.first + d[i][0];
         r.second = now.second + d[i][1];
         if( can_go( r ) && !appeared[r.first][r.second] ) {
             appeared[r.first][r.second] = true;
             go( r, len + 1 );
             appeared[r.first][r.second] = false;
         }
    }
    return;
}

int main() {
    pair<int, int> s;
    int i, maxlen = 0;

    cin >> s.first >> s.second;
    l[s.first][s.second] = 1;
    road[1] = s;
    appeared[s.first][s.second] = true;

    go( s, 1 );

    for( i = 1; i <= 36; i++ )
        cout << road[i].first << ' ' << road[i].second << endl;
    return 0;
}
