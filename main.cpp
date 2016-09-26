#include <bits/stdc++.h>
using namespace std;
ifstream f("baloane.in");
ofstream g("baloane.out");
int n,m,t,i,j,k,v[20];
double dp[52][52],P[52][15];
int main()
{
    f>>t;
    while(t--)
    {
        f>>n>>m;
        for(i=1;i<=m;++i) f>>v[i];
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                f>>P[i][j];
                P[i][j]/=100.0;
            }
        double sol=1;
        for(i=1;i<=m;++i)
        {
            for(j=1;j<=n;++j)
                for(k=1;k<=n;++k) dp[j][k]=0;
            dp[1][0]=1.0-P[1][i];
            dp[1][1]=P[1][i];
            for(j=2;j<=n;++j)
            {
                dp[j][0]=dp[j-1][0]*(1.0-P[j][i]);
                for(k=1;k<=j;++k)
                    dp[j][k]=dp[j-1][k]*(1.0-P[j][i])+dp[j-1][k-1]*P[j][i];
            }
            double s=0;
            for(j=0;j<=v[i];++j) s+=dp[n][j];
            sol*=s;
        }
        g<<fixed<<setprecision(4)<<sol*100.0<<'\n';
    }
    return 0;
}
