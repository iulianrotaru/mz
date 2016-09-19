#include <fstream>
#define Xp 1000000000
using namespace std;
ifstream f("recurenta.in");
ofstream g("recurenta.out");
int n,k,i,v[10001][400];
void add(int C[],int A[],int B[])
{
      int i,t=0;
      for(i=1;i<=A[0]||i<=B[0]||t;i++,t/=Xp)
      {
          t+=A[i]+B[i];
          C[i]=(t>=Xp?t-Xp:t);
      }
      C[0]=i-1;
}
void scad(int A[],int B[])
{
      int i,t=0;
      for(i=1;i<=A[0];i++)
      {
          A[i]-=((i<=B[0])?B[i]:0)+t;
          A[i]+=(t=A[i]<0)*Xp;
      }
      for(;A[0]>1&&!A[A[0]];A[0]--);
}
int main()
{
    f>>n>>k;
    for(i=0;i<k;++i) v[i][0]=v[i][1]=1;
    v[k][0]=1;
    v[k][1]=k;
    for(i=k+1;i<=n;++i)
    {
        add(v[i],v[i-1],v[i-1]);
        scad(v[i],v[i-k-1]);
    }
    g<<v[n][v[n][0]];
    for(i=v[n][0]-1;i;--i)
    {
        int x=Xp/10;
        while(v[n][i]<x) g<<0,x/=10;
        g<<v[n][i];
    }
    return 0;
}
