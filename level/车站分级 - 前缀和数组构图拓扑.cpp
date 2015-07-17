//最慢183ms
#include<fstream>
using namespace std;
ifstream cin("level.in");
ofstream cout("level.out");
int a[1001][1001], b[1001], f[1001], g[1001][1001], n, m;
void puta(int h, int c, int d, int j)
{
    for(int i = c; i <= d; i++)
        a[h][i] = j;
}
int pd(int h1, int c1, int d1, int h2, int c2, int d2)
{
    if(d1 <= c2 || d2 <= c1)
        return 0;
    int c = max(c1, c2), d = min(d1, d2);
    if(a[h1][d] - a[h1][c - 1] > a[h2][d] - a[h2][c - 1])
        return 1;
    else if (a[h1][d] - a[h1][c - 1] < a[h2][d] - a[h2][c - 1])
        return -1;
    return 0;
}
main()
{
    int i, j, k, c, d = 0, s[1001], e[1001], tt = clock();
    cin >> n >> m;
    int l = n, r = 1;
    bool t[1001] = {}, p;
    for(i = 1; i <= m; i++)
    {
        cin >> k >> c;
        l = min(l, c);
        t[c] = 1;
        s[i] = c;
        for(j = 1; j < k; j++)
        {
            cin >> d;
            t[d] = 1;
            puta(i, c, d - 1, a[i][c - 1] + 1);
            c = d;
        }
        r = max(r, c);
        e[i] = c;
        puta(i, c, n, a[i][c - 1] + 1);
        for(j = 1; j < i; j++)
            switch(pd(i, s[i], e[i], j, s[j], e[j]))
            {
            case 1:
                g[i][j] = 1;
                b[j]++;
                break;
            case -1:
                g[j][i] = 1;
                b[i]++;
            }
    }
    k = j = 0; //设定栈指针与最终结果的初值
    p = count(t + l, t + r + 1, 1) < r - l + 1;
    for(i = 1; i <= m; i++)
        if(b[i] == 0)
        {
            s[++k] = i;
            f[i] = 1; //不超过i的等级数
        }
    do
    {
        c = s[k--]; //用栈顶弹出的c拓扑访问邻接的点d
        for(d = 1; d <= m; d++)
            if(g[c][d] == 1)
            {
                f[d] = max(f[d], f[c]);
                if(--b[d] == 0)
                    f[s[++k] = d]++;
            }
        j = max(j, f[c]);
    }
    while(k > 0);
    cout << j + p << endl << clock() - tt;
}