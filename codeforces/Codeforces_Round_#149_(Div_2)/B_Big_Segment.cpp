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
    int n;
    cin>>n;
    vector<pair<long long int,long long int> > v(n);
    long long int mini=1000000001,maxi=0;
    for(int c=0;c<n;c++){ cin>>v[c].first>>v[c].second;mini=min(mini,v[c].first);maxi=max(maxi,v[c].second);}
    for(int c=0;c<n;c++) if(v[c].first==mini&&v[c].second==maxi) {cout<<c+1;return 0;}
    cout<<-1;
}