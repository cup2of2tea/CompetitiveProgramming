#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<int> primes;
    vector<bool> isPrime(1e4,true);
    isPrime[0]=isPrime[1]=false;
    for(int c=2;c<isPrime.size();c++)
    {
        if(isPrime[c]) {
            primes.push_back(c);
            for(int c2=c;c2<isPrime.size();c2+=c) {
                isPrime[c2] = false;
            }
        }
    }
    vector<int> res;
    for(int c=0;c<primes.size();c++)
    {
        int act = primes[c];
        while(act <= N) {
            res.push_back(act);
            act*=primes[c];
        }
    }
    cout<<res.size()<<endl;
    for(int c=0;c<res.size();c++) cout<<res[c]<<" ";
 
}