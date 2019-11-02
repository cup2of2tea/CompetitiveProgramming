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
 
using namespace std;
 
 
int main()
{
#ifdef LOCAL
    ifstream cin("input.txt");
#endif
    int x,t,a,b,da,db;
    cin>>x>>t>>a>>b>>da>>db;
    if(x==0)
    {
        cout<<"YES";
        return 0;
    }
    for(int c=0;c<t;c++)
    {
        for(int c2=0;c2<t;c2++)
        {
            if(x==a-c*da||x==a-c*da+b-c2*db||x==b-c2*db)
            {
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
}