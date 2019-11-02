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
 
 
long long MOD = 1e9+7;
long long powMod(long long N,long long t)
{
    if(t==0) return 1;
    if(t%2==0)
    {
        long long tmp = powMod(N,t/2);
        return (tmp*tmp)%MOD;
    }
    else {
        long long tmp = powMod(N,t/2);
        return (N*((tmp*tmp)%MOD))%MOD;
    }
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    long long N;
    cin>>N;
    cout<<(MOD*2+powMod(27,N)-powMod(7,N))%MOD;
}