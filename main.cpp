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
//produs cartezian
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long n,i,j,a,b,y,sol=1;
char x,q,dp[50][50];
int main()
{
    cin>>a>>n;
    cout<<'{';
    for(i=1;i<=a;++i)
        for(j=1;j<=n;++j)
    {
        cout<<'('<<i<<','<<j<<')';
        if(i!=a||j!=n) cout<<',';
    }
    cout<<'}';
    return 0;
}
//produs cartezian 1
#include <fstream>
using namespace std;
ifstream f("produscartezian1.in");
ofstream g("produscartezian1.out");
int n,m,k,x[10];
void afis()
{
    for(int i=1;i<=m;i++)
        g<<x[i]<<' ';
    g<<'\n';
}
void back()
{
    k=1;x[1]=0;
    do
    {
        while(x[k]<n)
        {
            x[k]++;
            if(k==m) afis();
            else {k++;x[k]=0;}
        }
        k--;
    }while(k);
}
int main()
{
    f>>n>>m;
    back();
    return 0;
}
#include <fstream>
using namespace std;
ifstream f("cladire.in");
ofstream g("cladire.out");
int x,y;
unsigned long long a[2009][2009];
int main()
{
    f>>x>>y;
    for(int i=1;i<=x;i++) a[i][1]=1;
    for(int j=1;j<=y;j++) a[1][j]=1;
    for(int i=2;i<=x;i++)
        for(int j=2;j<=y;j++)
            a[i][j]=(a[i-1][j]+a[i][j-1])%9901;
    g<<a[x][y]%9901;
    return 0;
}
