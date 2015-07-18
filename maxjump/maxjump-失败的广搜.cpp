// 6 * 6 的棋盘，马从 s( x, y ) 开始，问最多跳多少步 ？ 求路径和步数 （国际跳棋）
#include<iostream>
#include<queue>

using namespace std;

queue< pair<int, int> > q;
int len[10][10];
bool appeared[10][10];
bool can_go( pair<int, int> point ) {
    if( point.first > 0 && point.first <= 6 && point.second > 0 && point.second <= 6 )
        return true;
    else
        return false;
}

int main() {
    pair<int, int> go, now, s;
    int i, maxlen = 0;
    int d[8][2] = { -1, -2, -2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2 };
    cin >> s.first >> s.second;
    q.push( s );
    len[s.first][s.second] = 1;
    appeared[s.first][s.second] = true;
    while( !q.empty() ) {
        now = q.front();
        cout << "Now: " << now.first << ' ' << now.second << endl;
        for( i = 0; i < 8; i++ ) { 
            go.first = now.first + d[i][0];
            go.second = now.second + d[i][1];
            if( can_go( go ) && !appeared[go.first][go.second] ) {
                q.push( go );
                len[go.first][go.second] = len[now.first][now.second] + 1;
                maxlen = max( maxlen, len[go.first][go.second] );
                appeared[go.first][go.second] = true;
                cout << go.first << ' ' << go.second << endl; 
            }
        }
        q.pop();
        appeared[now.first][now.second] = false;
    }
    cout << maxlen << endl; 
    system("pause");
    return 0;
}
