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
#define COUT(s) cout<<"-----"<<s<<endl;
#endif
 
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
using namespace std;
 
 
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
        ofstream out("output.txt");
    #endif
    int x,y,a,b;
    cin>>x>>y>>a>>b;
    bool zero=true;
    vector<pair<int,int> > res;
    for(int c=a;c<=x;c++)
        for(int c2=b;c2<=y;c2++)
            if(c>c2)
                res.push_back(make_pair(c,c2));
    cout<<res.size()<<endl;
    for(int c=0;c<res.size();c++)
        cout<<res[c].first<<" "<<res[c].second<<endl;
 
}