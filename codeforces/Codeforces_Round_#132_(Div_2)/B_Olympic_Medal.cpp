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
    int n,m,k;
    cin>>n;
    vector<double> a(n);
    for(int c=0;c<n;c++)
        cin>>a[c];
    cin>>m;
    vector<double> b(m);
    for(int c=0;c<m;c++)
        cin>>b[c];
    cin>>k;
    vector<double> d(k);
    for(int c=0;c<k;c++)
        cin>>d[c];
    double A,B;
    cin>>A>>B;
    double maxi=0;
    double a2=-1,b2=-1,d2=10000000;
    for(int c=0;c<n;c++)
        a2=max(a[c],a2);
    for(int c=0;c<m;c++)
        b2=max(b[c],b2);
    for(int c=0;c<k;c++)
        d2=min(d[c],d2);
    double z=(a2*a2*b2*B)/(d2*A+b2*B);
    z=sqrt(z);
    cout<<fixed<<setprecision(12)<<z;
}