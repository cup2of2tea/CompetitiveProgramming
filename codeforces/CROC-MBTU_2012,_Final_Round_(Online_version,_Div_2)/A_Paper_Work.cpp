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
#include <iomanip>
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
    int n;
    cin>>n;
    vector<int> v(n);
    int neg=0,fol=1;
    int act=0;
    vector<int> res;
    for(int c=0;c<n;c++)
    {
        cin>>v[c];
        act++;
        neg+=(v[c]<0?1:0);
        if(neg>2)
        {
            res.push_back(act-1);
            fol++;
            neg-=2;
            act=1;
        }
    }
    res.push_back(act);
    cout<<res.size()<<endl;
    for(int c=0;c<res.size();c++)
        cout<<res[c]<<" ";
}