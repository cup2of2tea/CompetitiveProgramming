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
#include <limits>
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
 
const long long INFLL=numeric_limits<long long int>::max();
const int INF=numeric_limits<int>::max();
 
class comparaison1
{
    public:
    comparaison1(){}
    bool operator()(const int &a,const int &b)
    {
        return a>b;
    }
};
 
class comparaison2
{
    public:
    comparaison2(){}
    bool operator()(const int &a,const int &b)
    {
        return b>a;
    }
};
 
 
int main()
{
#ifdef LOCAL
    ifstream cin("input.txt");
#endif
    int n,m;
    cin>>n>>m;
    priority_queue<int,vector<int>,comparaison1> p1;
    priority_queue<int,vector<int>,comparaison2> p2;
    for(int c=0;c<m;c++)
    {
        int z;
        cin>>z;
        p1.push(z);
        p2.push(z);
    }
    int res1=0,res2=0;
    for(int c=0;c<n;c++)
    {
        int a=p1.top(),b=p2.top();
        p1.pop();
        p2.pop();
        res1+=a;
        res2+=b;
        if(a>1)
            p1.push(a-1);
        if(b>1)
            p2.push(b-1);
    }
    cout<<res2<<" "<<res1;
}