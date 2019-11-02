#include <iostream>
using namespace std;
 
long long pgcd(long long int a,long long int b,long long int &count)
{
 
    if(a==0) return b;
    else
    {
        long long int newA = b%a;
        count += (b-newA)/a;
        return pgcd(newA,a,count);
    }
}
 
 
int main()
{
    long long a,b;
    cin>>a>>b;
    long long int count = 0;
    pgcd(a,b,count);
    cout<<count<<endl;
}