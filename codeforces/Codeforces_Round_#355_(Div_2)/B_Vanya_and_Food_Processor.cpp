#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
#ifndef ONLINE_JUDGE
//    #define cin in
//    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    long long int n,h,k;
    cin>>n>>h>>k;
    long long int act = 0;
    long long int res = 0;
    for(int c=0;c<n;c++) {
        long long int z;
        cin>>z;
        long long int toremove = max(0LL,act-(h-z));
        long long int secs = (toremove+k-1)/k;
        res += secs;
        act -= k*secs;
        act = max(act,0LL);
        act += z;
    }
    res += (act+k-1)/k;
    cout<<res;
}