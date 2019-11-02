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
 
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
        ofstream out("output.txt");
    #endif
 
    long long int s,n;
    cin>>s>>n;
     vector<pair<int,int> >v(n);
     for(int c=0;c<n;c++)
        cin>>v[c].first>>v[c].second;
    sort(v.begin(),v.end());
    for(int c=0;c<n;c++)
    {
        if(v[c].first>=s)
        {
            cout<<"NO";
            return 0;
        }
        s+=v[c].second;
    }
    cout<<"YES";
}