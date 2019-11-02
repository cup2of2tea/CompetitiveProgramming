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
    int m,n;
    cin>>n>>m;
    if(m!=0&&n==0)
    {
        cout<<"Impossible";
        return 0;
    }
    cout<<n+(max(m-n,0))<<" "<<n+(max(0,m-1));
}