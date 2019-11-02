#include <iostream>
using namespace std;
 
long long int pgcd(long long int a,long long int b)
{   
    if(a==0) return b;
    return pgcd(b%a,a);
}
 
long long int ppcm(long long int a,long long int b)
{
    return a*b/pgcd(a,b);
}
 
 
int main()
{
    long long x,y,a,b;
    cin>>x>>y>>a>>b;
    int pp=ppcm(x,y);
    cout<<b/pp-(a-1)/pp;
}