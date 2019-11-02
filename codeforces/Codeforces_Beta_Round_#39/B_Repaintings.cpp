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
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    int n,m;
    int x;
    cin>>n>>m>>x;
    x--;
    cout<<(max(0,n-2*x)*max(0,m-2*x)-max(0,n-2*x)*max(0,m-2*x)/2)-(max(0,n-2*(x+1))*max(0,m-2*(x+1))-max(0,n-2*(x+1))*max(0,m-2*(x+1))/2);
}