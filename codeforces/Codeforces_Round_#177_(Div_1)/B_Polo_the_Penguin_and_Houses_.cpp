#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <istream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <list>
#include <cstdio>
#include <set>
#include <iomanip>
#include <stack>
#include <ctime>
#include <climits>
#include <iterator>
#define LOCAL
#ifdef ONLINE_JUDGE
#define COUT(s)
#undef LOCAL
#endif
#ifdef LOCAL
#define COUT(s) cout<<"-----"<<s<<"-----"<<endl;
#endif
 
using namespace std;
 
const long long MOD=1000000007;
 
long long powm(long long a,long long b)
{
    return (b==0?1LL:(a%MOD)*(powm(a,b-1)%MOD))%MOD;
}
 
long long pow2(long long a,long long b)
{
    return (b==0?1LL:(a)*(powm(a,b-1)));
}
 
 
 
long long int precalc[8]={1,2,9,64,625, 7776, 117649,2097152};
int main(int argc,char **argv)
{
#ifdef LOCAL
    ifstream in("input.txt");
    ofstream out("output2.txt");
#endif
    int n,k;
    cin>>n>>k;
    cout<<((long long)precalc[min(k,8)-1]*powm(n-k,n-k))%MOD;
}