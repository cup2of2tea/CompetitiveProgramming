#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdio>
#include <set>
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
#define cin in
//#define cout out
#define COUT(s) cout<<"-----"<<s<<endl;
#endif
#define MOD 10000009
 
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
using namespace std;
 
long long sum(long long n)
{
    long long res=0;
    while(n!=0)
    {
        res+=n%10;
        n/=10;
    }
    return res;
}
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
        ofstream out("output.txt");
    #endif
    long long n;
    cin>>n;
    long long gauche=0,droite=sqrt(n)+1;
    while(abs(gauche-droite)>1)
    {
        long long mid=(gauche+droite)/2;
        if(mid*mid+mid*9*(log(mid)+1)>n)
        {
            droite=mid;
        }
        else gauche=mid;
    }
    for(long long c=max(gauche-1,static_cast<long long>(1));c*c<=n;c++)
    {
        if(c*c+sum(c)*c==n)
        {
            cout<<c;
            return 0;
        }
    }
    cout<<-1;
}