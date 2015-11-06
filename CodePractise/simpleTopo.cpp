#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> a[100];
queue<int> Q;
int countBack[100], nv, ne;

void printCountBack() {
	int i;
	for ( i = 1; i <= nv; i++ ) 
		cout << countBack[i] << ' ';
	cout << endl;
}

int main() {
	int i, t, tt;
	cin >> nv >> ne;
	for ( i = 0; i < ne; i++ ) {
		cin >> t >> tt;
		a[t].push_back(tt);
		countBack[tt] ++;
	}
	for ( i = 1; i <= nv; i++ ) {
		if ( countBack[i] == 0 ) 
			Q.push(i);
	}

	int fr, now;
	while ( !Q.empty() ) {
		fr = Q.front();
		Q.pop();
		for ( i = 0; i < a[fr].size(); i++ ) {
			now = a[fr][i];
			if ( --countBack[now] == 0 )
				Q.push(now);
		}
		cout << fr << ' ';
	}
	cout << endl;
	return 0;
}
