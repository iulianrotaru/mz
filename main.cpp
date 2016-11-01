#include <fstream>
#include <algorithm>
#include <cstring>
#define Xp 20012
using namespace std;
ifstream f("criptare2.in");
ofstream g("criptare2.out");
int i,n,dist,l,j,step,m,R[30],frec[30],Q[Xp][30],v[Xp];
char w[30];
bool cmp(int a,int b)
{
    if(Q[a][0]!=Q[b][0]) return Q[a][0]<Q[b][0];
    for(int jeg=1;jeg<=Q[a][0];++jeg)
        if(Q[a][jeg]!=Q[b][jeg]) return Q[a][jeg]<Q[b][jeg];
    return 0;
}
bool ver()
{
    if(Q[v[j+step]][0]!=R[0]) return Q[v[j+step]][0]<R[0];
    for(int jeg=1;jeg<=R[0];++jeg)
        if(R[jeg]!=Q[v[j+step]][jeg])
            return Q[v[j+step]][jeg]<R[jeg];
    return 1;
}
bool semn()
{
    for(int jeg=0;jeg<=R[0];++jeg)
        if(Q[v[j]][jeg]!=R[jeg]) return 0;
    return 1;
}
int main()
{
    f>>n;
    for(i=1;i<=n;++i)
    {
        f>>w;
        for(j=1;j<=26;++j) frec[j]=0;
        l=strlen(w);
        for(j=dist=0;j<l;++j)
        {
            if(!frec[w[j]-'a'+1])
            {
                Q[i][++Q[i][0]]=++dist;
                frec[w[j]-'a'+1]=dist;
            }
            else Q[i][++Q[i][0]]=frec[w[j]-'a'+1];
        }
        v[i]=i;
    }
    sort(v+1,v+n+1,cmp);
    f>>m;
    while(m--)
    {
        f>>w;
        for(j=1;j<=26;++j) frec[j]=0;
        l=strlen(w);
        for(j=dist=R[0]=0;j<l;++j)
        {
            if(!frec[w[j]-'a'+1])
            {
                R[++R[0]]=++dist;
                frec[w[j]-'a'+1]=dist;
            }
            else R[++R[0]]=frec[w[j]-'a'+1];
        }
        for(j=0,step=(1<<15);step;step>>=1)
            if(j+step<=n&&ver()) j+=step;
        g<<semn()<<'\n';
    }
    return 0;
}
