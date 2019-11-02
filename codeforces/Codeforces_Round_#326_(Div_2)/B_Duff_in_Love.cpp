#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
 
 
 
int main()
{
    long long n;
    cin>>n;
    vector<bool> isPrime(1000002,true);
    for(long long int c=2;c*c<=n && c<isPrime.size();c++)
    {
        if(!isPrime[c]) continue;
        while(n%(c*c) == 0) n/=c;
        for(int c2=c*2;c2<isPrime.size();c2+=c) isPrime[c2]=false;
    }
    cout<<n;
    return 0;
}