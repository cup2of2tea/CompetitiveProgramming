#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <set>
#include <ctime>
#include <queue>
#include <climits>
#include <iomanip>
#include <iterator>
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
 
#ifdef LOCAL
#define cin in
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
 
#define MOD 1000000007
 
using namespace std;
 
long long truc(long long n)
{
    if(n==0)
        return 1;
    long long res=truc(n/2)%MOD;
    res*=res;
    res%=MOD;
    if(n%2==1)
        res*=2;
    return res%MOD;
}
 
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
   long long n;
   cin>>n;
   if(n==0)
    {
        cout<<1;
    }
    else cout<<(truc(2*n-1)+truc(n-1))%MOD;
}