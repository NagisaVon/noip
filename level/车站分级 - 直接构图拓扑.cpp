#include<iostream>
#include<cstdlib>
#include<memory.h>
using namespace std;

int a[502][502], f[502][502], u[4] = { -1, 1, 0, 0}, v[4] = {0, 0, -1, 1};
int F(int x, int y)
{
    if(f[x][y] > 0)
        return f[x][y];
    int i, s, t;
    for(i = 0; i <= 3; i++)
    {
        s = x + u[i];
        t = y + v[i];
        if(a[x][y] > a[s][t])
            f[x][y] = max(f[x][y], F(s, t));
    }
    return ++f[x][y];
}
int main()
{
    int i, j, n, l = 0, t;
    cin >> n;
    memset(a, 1, sizeof(a)); //设一圈边界最高（超1千万）
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            cin >> a[i][j];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            t = F(i, j);
            if(t > l)
                l = t;
        }
    cout << l << endl;
    return 0;
}