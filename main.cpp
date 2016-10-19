#include <bits/stdc++.h>
using namespace std;
ifstream f("provacanta.in");
ofstream g("provacanta.out");
int t,i,j,l,k,n,m,timp,bani,sol,dp[102][102],a[1002][102],b[1002][102];
int main()
{
    f>>t;
    ///dp i elemente din a cu j elemente din b
    for(i=1;i<=100;++i)
        for(j=1,dp[i][0]=i*(i-1)/2;j<=100;++j)
    {
        dp[i][j]=1<<30;
        for(k=0;k<=i;++k)
            dp[i][j]=min(dp[i][j],dp[k][j-1]+(i-k)*(i-k-1)/2);
    }
    while(t--)
    {
        f>>n>>m>>k;
        for(i=0;i<=k;++i)
            for(j=0;j<=100;++j) a[i][j]=b[i][j]=-(1<<29);
        a[0][0]=b[0][0]=sol=0;
        ///time obiecte
        for(i=1;i<=n;++i)
        {
            f>>timp>>bani;
            for(j=k-timp;j>=0;--j)
                for(l=i-1;l>=0;--l)
                    a[j+timp][l+1]=max(bani+a[j][l],a[j+timp][l+1]);
        }
        for(i=1;i<=m;++i)
        {
            f>>timp>>bani;
            for(j=k-timp;j>=0;--j)
                for(l=i-1;l>=0;--l)
                    b[j+timp][l+1]=max(bani+b[j][l],b[j+timp][l+1]);
        }
        for(i=1;i<=k;++i)
            for(j=0;j<=m;++j)
                b[i][j]=max(b[i][j],b[i-1][j]);
        for(i=0;i<=n;++i)
            for(j=0;j<=m;++j)
                for(l=0;l<=k-dp[i][j];++l)
                    sol=max(sol,a[l][i]+b[k-dp[i][j]-l][j]);
        g<<sol<<'\n';
    }
    return 0;
}
