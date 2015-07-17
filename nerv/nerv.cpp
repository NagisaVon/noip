// 神经网络NOIPs 2003
#include<iostream>
#include<queue>
using namespace std;

int c[105];  // States
int u[105];  // 阀值
int a[105][105]; // 邻接矩阵
int out[105]; // 出度 
bool inq[105]; // 去重
int n, p; 
queue<int> q; 

void printc() {
     int i;
     for( i = 1; i <= n; i++ )
          cout << c[i] << ' ';
     cout << endl; 
}
 
void bfs() {
    int i, h;
    while( !q.empty() ) {
        h = q.front();
        q.pop();
        if( c[h] && out[h] ) 
            for( i = 1; i <= n; i++ ) 
                if( a[h][i] ) {
                    c[i] += a[h][i] * c[h]; // 根据公式，c[i] = 权值(j, i) * c[j] 的所有j的累加
                    //printc();
                    if ( !inq[i] ) {
                        q.push( i );
                        c[i] -= u[i]; // 在第一次进栈的时候把公式中的 阀值 减去 
                        inq[i] = true;
                    }
                }
    }
}

int main() {
    int i, j;
    int x, y, z;

    cin >> n >> p;
    for( i = 1; i <= n; i++ ) {
        cin >> c[i] >> u[i];
        if( c[i] ) {
            q.push( i );
            inq[i] = true;
        }
    }
    //printc();
    
    for( i = 0; i < p; i++ ) {
        cin >> x >> y >> z;
        a[x][y] = z;
        out[x]++;
    }
    
    bfs();
    
    bool flag = false;
    for( i = 1; i <= n; i++ )
        if( out[i] == 0 && c[i] != 0 ) {// is 输出层 && c[i] != 0
            cout << i << ' ' << c[i] << endl;
            flag = true;
        }
    if( !flag )
        cout << "NULL" << endl;
    
            
    system("pause"); 
    return 0;
}
/*
5 6
1 0
1 0
0 1
0 1
0 1
1 3 1
1 4 1
1 5 1
2 3 1
2 4 1
2 5 1

*/
