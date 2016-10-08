#include <fstream>
using namespace std;
ifstream f("bitonic.in");
ofstream g("bitonic.out");
int n,t,sol,i,poz,a[1<<10],B[1<<10],D[1<<10],S[1<<10],T[1<<10];
int search_bin(int val)
{
    int j,step;
    for(j=0,step=1<<10;step;step>>=1)
        if(j+step<=B[0]&&B[j+step]<val) j+=step;
    return j;
}
int search_bin_(int val)
{
    int j,step;
    for(j=0,step=1<<10;step;step>>=1)
        if(j+step<=D[0]&&D[j+step]>val) j+=step;
    return j;
}
int main()
{
    f>>t;
    while(t--)
    {
        f>>n>>a[1];
        B[1]=a[1];
        D[1]=a[1];
        B[0]=D[0]=1;
        for(i=2;i<=n;++i)
        {
            f>>a[i];
            poz=search_bin(a[i]);
            if(poz==B[0]) ++B[0];
            B[poz+1]=a[i];
            S[i]=poz+1;
            poz=search_bin_(a[i]);
            if(poz==D[0]) ++D[0];
            D[poz+1]=a[i];
            T[i]=poz+1;
        }
        sol=max(S[n],T[n]);
        B[1]=a[n];
        D[1]=a[n];
        B[0]=D[0]=1;
        for(i=n-1;i>0;--i)
        {
            poz=search_bin(a[i]);
            if(poz==B[0]) ++B[0];
            B[poz+1]=a[i];
            sol=max(sol,S[i]+poz);
            poz=search_bin_(a[i]);
            if(poz==D[0]) ++D[0];
            D[poz+1]=a[i];
            sol=max(sol,T[i]+poz);
        }
        g<<sol<<'\n';
    }
    return 0;
}
