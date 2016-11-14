///Complexitate O(n)
#include <fstream>
using namespace std;
ifstream f("a.in");
ofstream g("a.out");
int n,m,x,i,nr,sol,v[1<<17],y[1<<10],fr[1<<10];
int main()
{
    f>>n; /// 1<=n<=100000
    for(i=1;i<=n;++i) f>>v[i];
    /// n>m
    /// y sirul frecventelor
    f>>m; /// 1<=m<=1000
    for(i=1;i<=m;++i)
    {
        f>>x;
        /// 1<=x<=1000
        y[x]++;
    }
    for(i=1;i<=m;++i)
    {
        /// fr sirul frecventelor pentru o secventa de lungime m
        fr[v[i]]++;
        if(fr[v[i]]>y[v[i]]) ++nr;
    }
    ///incrementez solutia
    if(!nr) sol++;
    for(i=m+1;i<=n;++i)
    {
        /// scot al i-m numar din sir
        if(fr[v[i-m]]>y[v[i-m]]) --nr;
        fr[v[i-m]]--;
        /// adaug al i numar din sir
        fr[v[i]]++;
        if(fr[v[i]]>y[v[i]]) ++nr;
        ///incrementez solutia
        if(!nr) sol++;
    }
    g<<sol; /// 0<=sol<=n-m+1
    return 0;
}
