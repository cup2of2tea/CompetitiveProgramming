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
 
 
typedef struct node
{
    vector<int> v;
    int cout;
};
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
        ofstream out("output.txt");
    #endif
    int n,m;
    cin>>n>>m;
    vector<set<int> > v(100001);
    vector<int> color(n);
    int indice_maxi=10000000;
    for(int c=0;c<n;c++)
    {
        cin>>color[c];
        indice_maxi=min(indice_maxi,color[c]);
    }
    for(int c=0;c<m;c++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        if(color[a]!=color[b])
        {
            v[color[a]].insert(color[b]);
            v[color[b]].insert(color[a]);
        }
    }
    for(int c=indice_maxi+1;c<100001;c++)
    {
        if(v[c].size()>v[indice_maxi].size())
            indice_maxi=c;
    }
    cout<<indice_maxi;
}