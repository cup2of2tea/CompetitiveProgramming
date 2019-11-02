#include <bits/stdc++.h>
 
using namespace std;
 
long long calculate(long long a, long long n) {
    // Number of multiples
    long long int m = n / a;
 
    // sum of first m natural numbers
    long long int sum = (m) * (m - 1) / 2;
 
    // sum of multiples
    long long int ans = a * sum + m;
 
    return ans;
 
}
set<long long> go(long long N) {
    set<long long> res;
    res.insert(1);
    res.insert((N*(N+1))/2LL);
    for(long long int c=2;c*c<=N;c++) {
        if(N%c==0) {
            long long z1 = calculate(c,N-1);
            long long z2 = calculate(N/c,N-1);
            res.insert(calculate(c,N));
            res.insert(calculate(N/c,N));
        }
    }
    return res;
}
 
 
int main(int argc, char **argv)
{
  long long N;
  cin>>N;
  for(long long int c=2;c*c<=N;c++) {
 
  }
        set<long long int> s2 = go(N);
        for(auto z:s2) {
            cout<<z<<" ";
        }
}