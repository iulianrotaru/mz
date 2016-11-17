#include <fstream>
using namespace std;
ifstream f("sobo.in");
ofstream g("sobo.out");
int n,m,i,j,cost[1<<10],comb[1<<10],dp[1<<15];
char v[16][1<<10];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;++i) f>>(v[i]+1);
    for(i=1;i<=m;++i) f>>cost[i];
    for(j=1;j<=n;++j)
        for(i=1;i<=m;++i) comb[i]|=((v[j][i]>'0')<<(j-1));
    for(i=3;i<(1<<n);++i)
        if(i&(i-1))
        {
            dp[i]=1<<30;
            for(j=1;j<=m;++j)
            {
                int a=(i&comb[j]);
                int b=i^a;
                if(a&&b) dp[i]=min(dp[i],max(dp[a],dp[b])+cost[j]);
            }
        }
    g<<dp[(1<<n)-1];
    return 0;
}
