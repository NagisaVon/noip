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
        //���뻡���ۼ��ڽӼ����������ڽӼ�����
        cin >> b[i] >> c[i];
        a[b[i]].n++; // �ٽӼ�����
        a[c[i]].c++; // ���ڽӼ�����
    }
    for(i = 1; i <= n; i++)
    {
        //Ϊÿ���ڵ㿪���ʵ����ȵ�˳���ڽӱ������˶��г�ʼ��
        a[i].h = new int[a[i].n];  // ָ��h����������
        if(a[i].c == 0) //�������
            a[d[++w] = i].l = 1; //�������˼���
    }
    //��ʼ�����ڽӱ�
    for(i = 1; i <= m; i++)
        a[b[i]].h[a[b[i]].d++] = c[i]; //.d=size
    //��ʼ������˳����ʴ�ͼ
    int q, *p;
    do
    {
        q = d[t++]; //����ͷɾ��������q��
        for(p = a[q].h; p < a[q].h + a[q].n; p++)
        {
            a[*p].c--;//�����ڽӼ�����
            a[*p].l = max(a[*p].l, a[q].l); //��*p���з���
            if(a[*p].c == 0)
            {
                //����
                d[++w] = *p;
                l = max(l, ++(a[*p].l));
            }
        }
    }
    while(t <= w);
    cout << l << endl;
    return 0;
}
