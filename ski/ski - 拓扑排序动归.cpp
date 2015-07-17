// in Mr.Zhu's script
#include<fstream>
using namespace std;
ifstream fin("hx.in");
ofstream fout("hx.out");
int a[502][502], f[502][502], r[502][502];
int main()
{
    int i, j, n, z = 0, b[100001], c[100001], x, y, s, t, max = 0, u[4] = { -1, 1, 0, 0}, v[4] = {0, 0, -1, 1};
    fin >> n;
    memset(r, 1, sizeof(r));
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            fin >> a[i][j];
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            r[i][j] = (a[i + 1][j] > a[i][j]) + (a[i - 1][j] > a[i][j]) + (a[i][j + 1] > a[i][j]) + (a[i][j - 1] > a[i][j]);
            if(r[i][j] == 0)
            {
                z++;
                b[z] = i;
                c[z] = j; // b & c use to analog stack
            }
        }
    }
    while(z > 0) //开始拓扑
    {
        x = b[z];
        y = c[z];
        z--;//以栈作为拓扑集合
        for(i = 0; i < 4; i++)
        {
            s = x + u[i];
            t = y + v[i];
            if(a[x][y] > a[s][t])
            {
                r[s][t]--;
                if(f[x][y] >= f[s][t])
                    f[s][t] = f[x][y] + 1;
                if(r[s][t] == 0)
                {
                    z++;
                    b[z] = s;
                    c[z] = t;
                    if(f[s][t] > max)
                        max = f[s][t];
                }
            }
        }
    }
    fout << max + 1 << endl;
    return 0;
}