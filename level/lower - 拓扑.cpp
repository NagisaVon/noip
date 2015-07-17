/* in Mr.Zhu's script */
#include<iostream>
using namespace std;
int n, m, b[100001], c[100001], d[100001], t = 1, w, l;
struct gongxu
{
    int c, *h, n, l, d;
};
gongxu a[100001] = {};
int main()
{
    int i;
    cin >> n >> m;
    for(i = 1; i <= m; i++)
    {
        //输入弧并累加邻接计数器和逆邻接计数器
        cin >> b[i] >> c[i];
        a[b[i]].n++; // 临接计数器
        a[c[i]].c++; // 逆邻接计数器
    }
    for(i = 1; i <= n; i++)
    {
        //为每个节点开辟适当长度的顺序邻接表并对拓扑队列初始化
        a[i].h = new int[a[i].n];  // 指针h被用作数组
        if(a[i].c == 0) //逆邻域空
            a[d[++w] = i].l = 1; //进入拓扑集合
    }
    //开始构造邻接表
    for(i = 1; i <= m; i++)
        a[b[i]].h[a[b[i]].d++] = c[i]; //.d=size
    //开始按拓扑顺序访问此图
    int q, *p;
    do
    {
        q = d[t++]; //将队头删除并移入q中
        for(p = a[q].h; p < a[q].h + a[q].n; p++)
        {
            a[*p].c--;//减逆邻接计数器
            a[*p].l = max(a[*p].l, a[q].l); //对*p进行访问
            if(a[*p].c == 0)
            {
                //进队
                d[++w] = *p;
                l = max(l, ++(a[*p].l));
            }
        }
    }
    while(t <= w);
    cout << l << endl;
    return 0;
}
