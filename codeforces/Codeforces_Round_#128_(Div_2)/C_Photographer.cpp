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
    int n,d;
    int a,b;
    cin>>n>>d>>a>>b;
    vector<pair<int,int> > v;
    for(int c=0;c<n;c++)
    {
        int a1,b1;
        cin>>a1>>b1;
        v.push_back(make_pair(a*a1+b*b1,c+1));
    }
    sort(v.begin(),v.end());
    int indice=0;
    vector<int> res;
    while(indice<v.size())
    {
        pair<int,int> z=v[indice++];
        if(d>=z.first)
        {
            d-=z.first;
            res.push_back(z.second);
        }
        else
            break;
    }
    cout<<res.size()<<endl;
    for(int c=0;c<res.size();c++)
        cout<<res[c]<<" ";
}