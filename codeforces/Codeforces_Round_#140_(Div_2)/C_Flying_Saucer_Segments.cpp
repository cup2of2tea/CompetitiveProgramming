#include <iostream>
 
using namespace std;
 
long long exponentiation_rapide(long long a,long long b,long long mod)
{
        if(b==0)
                return 1;
        if(b==1) return a;
        long long temp=exponentiation_rapide(a,b/2,mod)%mod;
        temp*=temp;
        temp%=mod;
        if(b%2==1)
                temp*=a;
        temp%=mod;
        return temp;
}
 
 
int main()
{
        long long int n,m;
        cin>>n>>m;
        cout<<(exponentiation_rapide(3,n,m)+m-1)%m;
} 
 