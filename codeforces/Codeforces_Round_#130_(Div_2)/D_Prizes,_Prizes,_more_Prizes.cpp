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
    int n;
    cin>>n;
    vector<long long int> v(n);
    for(int c=0;c<n;c++)
        cin>>v[c];
    vector<pair<long long int,int> > v2(5);
    for(int c=0;c<5;c++)
    {
        v2[c].second=c;
        cin>>v2[c].first;
    }
    sort(v2.begin(),v2.end());
    long long int res[5]={0};
    long long int act=0;
    for(int c=0;c<n;c++)
    {
        act+=v[c];
        int previous=4;
        while(v2[0].first<=act)
        {
            if(v2[previous].first>act)
                previous--;
            else
            {
                res[v2[previous].second]+=act/v2[previous].first;
                act%=v2[previous].first;
            }
        }
    }
    for(int c=0;c<5;c++)
        cout<<res[c]<<" ";
    cout<<endl<<act;
}