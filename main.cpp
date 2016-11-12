#include <fstream>
using namespace std;
ifstream f("div3.in");
ofstream g("div3.out");
int n,i,nr;
int suma_cifre(int x)
{
    int sum=0;
    while(x)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}
int main()
{
    f>>n;
    for(i=1;i<=n;++i)
    {
        f>>nr;
        if(suma_cifre(nr)%3==0) g<<nr<<' ';
    }
    return 0;
}
