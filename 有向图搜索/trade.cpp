#include <iostream>
#include <stack>
using namespace std;
struct node {
	int data;
	node *next;
};
node *h[100001], *p;
int g[100001], inv[100001], f[100001];
// g for lowest price at i 
// f for highest earn from 1 to i
stack<int> s;
int main() {
	int n, m, i, x, y, z, start, p, dest;
	cin >> n >> m;
	for ( i = 0; i < n; ++i )
		cin >> g[i]; // init lowest price
	for ( i = 0; i < m; ++i ) {
		cin >> x >> y >> z;
		p = new node;
		p->data = y;
		p->next = h[x];
		h[x] = p;
		inv[x]++;
	}
	s.push(1);
	do {
		start = s.top();
		s.pop();
		p = h[start];// p is temp node,goes every destination
		while(!p) {
			dest = p->data;
			if(g[dest] < g[start])
				g[dest] = g[start];
			// if can buy at lower price on the road , than change the g value
			if(f[dest] > f[start])
				f[dest]	
		}
	}while(!s.empty());	
		
	return 0;
} 
