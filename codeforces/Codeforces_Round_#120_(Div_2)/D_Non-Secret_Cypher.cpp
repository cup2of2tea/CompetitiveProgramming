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
#include <stack>
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
 
#ifdef LOCAL
#define cin in
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
 
 
using namespace std;
 
 
double distance(int x1,int y1,int x2,int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    map<long long,int> m;
    int n,k;
    cin>>n>>k;
    vector<long long> v(n);
    for(int c=0;c<n;c++)
        cin>>v[c];
    int precedent=0;
    long long res=0;
    for(int c=0;c<n;c++)
    {
        m[v[c]]++;
        while(m[v[c]]>=k)
        {
            res+=n-c;
            m[v[precedent]]--;
            precedent++;
        }
    }
    cout<<res;
 
}