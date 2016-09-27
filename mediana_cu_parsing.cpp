#include <fstream>
 
using namespace std;
class InParser {
private:
    FILE *fin;
    char *buff;
    int sp;
 
    char read_ch() {
        ++sp;
        if (sp == 4096) {
            sp = 0;
            fread(buff, 1, 4096, fin);
        }
        return buff[sp];
    }
 
public:
    InParser(const char* nume) {
        fin = fopen(nume, "r");
        buff = new char[4096]();
        sp = 4095;
    }
 
    InParser& operator >> (int &n) {
        char c;
        while (!isdigit(c = read_ch()) && c != '-');
        int sgn = 1;
        if (c == '-') {
            n = 0;
            sgn = -1;
        } else {
            n = c - '0';
        }
        while (isdigit(c = read_ch())) {
            n = 10 * n + c - '0';
        }
        n *= sgn;
        return *this;
    }
}f("mediana.in");
ofstream g("mediana.out");
int i,t,n,m,q,x_1,x_2,y_1,y_2,step,start,st,dr,a[1<<17],b[1<<17],da[1<<17],db[1<<17];
inline int aflua(int dist)
{
    step=1<<16;
    for(start=x_1;step;step>>=1)
        if(start+step<=x_2)
    {
        int num=start+step-x_1+1+min(max(da[start+step]-y_1+1,0),y_2-y_1+1);
        if(num<=dist) start+=step;
    }
    if(start-x_1+1+min(max(da[start]-y_1+1,0),y_2-y_1+1)==dist) return a[start];
    return 0;
}
inline int aflub(int dist)
{
    step=1<<16;
    for(start=y_1;step;step>>=1)
        if(start+step<=y_2)
    {
        int num=start+step-y_1+1+min(max(db[start+step]-x_1+1,0),x_2-x_1+1);
        if(num<=dist) start+=step;
    }
    if(start-y_1+1+min(max(db[start]-x_1+1,0),x_2-x_1+1)==dist) return b[start];
    return 0;
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
            x_1++;
            x_2++;
            y_1++;
            y_2++;
            g<<max(aflua((x_2-x_1+y_2-y_1+3)>>1),aflub((x_2-x_1+y_2-y_1+3)>>1))<<'\n';
        }
    }
    return 0;
}