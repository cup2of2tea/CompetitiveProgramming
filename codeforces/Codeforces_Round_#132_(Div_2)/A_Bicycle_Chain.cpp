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
#define COUT(s) cout<<"----"<<s<<"----"<<endl
#endif
#ifndef LOCAL
#define COUT(s);
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
 
using namespace std;
 
 
 
int main()
{
#ifdef LOCAL
    ifstream cin("input.txt");
#endif
    int n,m;
    cin>>n;
    vector<int> a(n);
    for(int c=0;c<n;c++)
        cin>>a[c];
    cin>>m;
    vector<int> b(m);
    for(int c=0;c<m;c++)
        cin>>b[c];
    int maxi=0;
    for(int c=0;c<n;c++)
        for(int c2=0;c2<m;c2++)
            if(b[c2]%a[c]==0)
                maxi=max(maxi,b[c2]/a[c]);
    int res=0;
    for(int c=0;c<n;c++)
        for(int c2=0;c2<m;c2++)
            if(b[c2]%a[c]==0&&maxi==b[c2]/a[c])
                res++;
    cout<<res;
 
}