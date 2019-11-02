#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <list>
#include <stack>
#include <limits.h>
#define ll long long
using namespace std;
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
   int N;
   cin>>N;
   vector<int> primes;
   vector<bool> isPrime(1e5+1,true);
   for(int c=2;c<isPrime.size();c++)
   {
        if(!isPrime[c]) continue;
        primes.push_back(c);
        for(int c2=c+c;c2<isPrime.size();c2+=c)
            isPrime[c2]=false;
   }
   int c;
   for(c=N;;c--) {
        for(int c2 = 0; c2 <primes.size() && primes[c2]*primes[c2]<=c;c2++) {
            if(c%primes[c2] == 0)
                goto nop;
        }
        break;
        nop:;
   }
   vector<int> res;
   N-=c;
   res.push_back(c);
   if(N==0)
   {
       goto end;
   }
   if(isPrime[N])
   {
       res.push_back(N);
       goto end;
   }
   for(c=0;c<primes.size();c++)
   {
       if(isPrime[N-primes[c]])
       {
           res.push_back(primes[c]);
           res.push_back(N-primes[c]);
           goto end;
       }
   }
 
   end:
    cout<<res.size()<<endl;
    for(int c=0;c<res.size();c++)
    {
        cout<<res[c]<<" ";
    }
}