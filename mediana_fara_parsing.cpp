#include <fstream>
 
using namespace std;
ifstream f("mediana.in");
ofstream g("mediana.out");
int i,t,n,m,q,x_1,x_2,y_1,y_2,step,start,st,dr,a[1<<17],b[1<<17],da[1<<17],db[1<<17];
inline int aflua(int dist)
{
    step=1<<16;
    for(start=x_1;step;step>>=1)
        if(start+step<=x_2)
    {
        int num=step+1+da[start+step]-max(y_1-1,da[x_1]);
        if(num<0) continue;
        if(num<=dist) start+=step;
    }
    if(start-x_1+1+da[start]-max(y_1-1,da[x_1])==dist) return a[start];
}
inline int aflub(int dist)
{
    step=1<<16;
    for(start=y_1;step;step>>=1)
        if(start+step<=y_2)
    {
        int num=step+2+db[start+step]-x_1;
        if(num<0) continue;
        if(num<=dist) start+=step;
    }
    if(start-y_1+2+db[start]-x_1==dist) return b[start];
}
int main()
{
    f>>t;
    while(t--)
    {
        f>>n>>m>>q;
        for(i=1;i<=n;++i) f>>a[i];
        for(i=1;i<=m;++i) f>>b[i];
        st=dr=1;
        while(st<=n&&dr<=m)
        {
            if(a[st]<=b[dr])
            {
                da[st]=dr-1;
                ++st;
            }
            else
            {
                db[dr]=st-1;
                ++dr;
            }
        }
        for(;st<=n;++st) da[st]=m;
        for(;dr<=m;++dr) db[dr]=n;
        while(q--)
        {
            f>>x_1>>x_2>>y_1>>y_2;
            g<<max(aflua((x_2-x_1+y_2-y_1+3)/2),aflub((x_2-x_1+y_2-y_1+3)/2))<<'\n';
        }
    }
    return 0;
}