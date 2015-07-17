//最慢7.in0.28",输入与构图约占80%
#include<fstream>
#include<cmath>
#include<bitset>
#include<stack>
#include<algorithm>
using namespace std;
ifstream cin("level.in");
ofstream cout("level.out");
int f[1001], e[1001], d[1001]; //目标函数、拓扑逆邻接计数器、停车站位序列
bitset<1001>g[1001];
stack<int> s;//拓扑集合
int main()
{
    int n, m, i, j, q, k = 0, t = clock();
    cin >> n >> m;
    for(i = 1; i <= m; i++)
    {
        g[0].reset();
        cin >> q;
        for(j = 0; j < q; j++)
        {
            //读入停车站序列d并构图g
            cin >> d[j];
            g[0][d[j]] = 1;
        }
        for(j = d[0]; j <= d[q - 1]; j++)
            if(g[0][j] == 0) g[j] |= g[0];
    }
    int t1 = clock();
    for(i = 1; i <= n; i++)
    {
        //求逆邻接表e并做拓扑初始化
        for(j = 1; j <= n; j++)
            e[i] += g[j][i];
        if(e[i] == 0)
        {
            //无入度点进栈
            f[i] = 1;
            s.push(i);
        }
    }
    while(!s.empty())
    {
        //开始拓扑
        q = s.top();
        s.pop();
        for(i = 1; i <= n; i++)
            if(g[q][i] > 0)
            {
                //用q拓扑访问i
                if(f[q] > f[i])
                    f[i] = f[q];
                if(--e[i] == 0)
                {
                    f[i]++;
                    s.push(i);
                }
            }
        k = max(k, f[q]);
    }
    cout << k << endl;
    cout << t1 - t << ' ' << clock() - t;
}
