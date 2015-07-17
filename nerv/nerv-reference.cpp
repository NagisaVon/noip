#include<iostream>
#include<cstdio>
using namespace std;
int n, m;
int q[201], u[201], a[201][201], c[201];
bool inq[201], flag = 0;
int f[201];
int t = 1, w = 0;
void bfs()
{
    int x;
    while(t <= w)
    {
        x = q[t];
        t++;
        if(f[x] > 0 && c[x])
        {
            for(int i = 1; i <= n; i++)
            {
                if(a[x][i])
                {
                    f[i] += a[x][i] * f[x];
                    if(!inq[i])
                    {
                        q[++w] = i;
                        f[i] -= u[i];
                        inq[i] = 1;
                    }
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    int x, y, z;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &f[i], &u[i]);
        if(f[i] != 0)
        {
            q[++w] = i;
            inq[i] = 1;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        c[x]++;
        a[x][y] = z;
    };
    bfs();
    for(int i = 1; i <= n; i++)
        if(!c[i] && f[i] > 0)
        {
            printf("%d %d\n", i, f[i]);
            flag = 1;
        }
    if(!flag)printf("NULL\n");
    return 0;
}