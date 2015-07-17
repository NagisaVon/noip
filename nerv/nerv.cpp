// ������NOIPs 2003
#include<iostream>
#include<queue>
using namespace std;

int c[105];  // States
int u[105];  // ��ֵ
int a[105][105]; // �ڽӾ���
int out[105]; // ���� 
bool inq[105]; // ȥ��
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
                    c[i] += a[h][i] * c[h]; // ���ݹ�ʽ��c[i] = Ȩֵ(j, i) * c[j] ������j���ۼ�
                    //printc();
                    if ( !inq[i] ) {
                        q.push( i );
                        c[i] -= u[i]; // �ڵ�һ�ν�ջ��ʱ��ѹ�ʽ�е� ��ֵ ��ȥ 
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
        if( out[i] == 0 && c[i] != 0 ) {// is ����� && c[i] != 0
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
