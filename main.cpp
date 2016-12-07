#include<fstream>
using namespace std;
ifstream f("lant.in");
ofstream g("lant.out");
int n,m,p,q,i,j,a[21][21],b[22],viz[22];
void back(int k)
{
    if(b[k-1]==q)
    {
        for(int i=1;i<k;++i) g<<b[i]<<' ';
        g<<'\n';
        return ;
    }
    for(int i=1;i<=n;i++)
        if(a[b[k-1]][i]==1&&!viz[i])
        {
            viz[i]=1;
            b[k]=i;
            back(k+1);
            viz[i]=0;
        }
}
int main()
{
    f>>n>>m;
    while(m--) {f>>i>>j;a[i][j]=a[j][i]=1;}
    f>>p>>q;
    b[1]=p;
    viz[p]=1;
    back(2);
    return 0;
}
#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("izolate.in");
ofstream g("izolate.out");
int n,m,r[101],a[102][102];
int main()
{
    f>>n;
    int x,y,i,j;
    while(f>>x>>y) a[x][y]=a[y][x]=1;
    for(i=1;i<=n;i++)
    {
        int s=0;
        for(j=1;j<=n;j++)
            s+=a[i][j];
        if(!s) r[++m]=i;
    }
    g<<m<<' ';
    sort(r+1,r+m+1);
    for(i=1;i<=m;i++) g<<r[i]<<' ';
    g.close();
    return 0;
}
// asta e copac
#include <iostream>
using namespace std;
long long n,i,a,b,c,A,B,C;
int main()
{
    cin>>n;
    n+=3;
    A=B=C=1;
    for(i=2;i<=n;++i)
    {
        a=A+B;
        b=A+C;
        c=A+B+C;
        A=a;
        B=b;
        C=c;
    }
    cout<<A<<' '<<B<<' '<<C;
    return 0;
}
