#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct point {
	int x;
	int y;
}s, e;

int map[100][100], m, n;
int d[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
queue<point> Q;

void printRect() {
	int i, j;
	for ( i = 0; i <= m; i ++ ) {
		for ( j = 0 ; j <= n; j++ ) 
			cout << map[i][j] << ' ';
		cout << endl;
	}
}

int main() {
	int i, j;
	string t;
	cin >> m >> n;
	memset(map, -1, sizeof(map));
	for ( i = 1; i <= m; i++ ) {
		cin >> t;
		for ( j = 0; j < t.length(); j++ ) 
			switch( t[j] ) {
				case '.':
					map[i][j + 1] = 0;
					break;
				case '*':
					break;
				case 's':
					s.x = i;
					s.y = j+1;
					map[i][j + 1] = 0;
					break;
				case 'e':
					e.x = i;
					e.y = j+1;
					map[i][j + 1] = 0;
					break;
			}
	}

	//printRect();

	Q.push(s);
	//cout << Q.front().x << ' ' << Q.front().y << endl;
	point go, now;
	while (!Q.empty()) {
		now = Q.front();
		Q.pop();
		for ( i = 0; i < 4; i++ ) {
			go.x = now.x + d[i][0];
			go.y = now.y + d[i][1];
			if ( map[go.x][go.y] >= 0  ) {
				Q.push(go);
				map[go.x][go.y] = map[now.x][now.y] + 1;
			}
			if (go.x == e.x && go.y == e.y ) {
				cout << map[go.x][go.y] << endl;
				return 0;
			}
		}
	}
	//printRect();
	cout << -1 << endl;
	return 0;
}
