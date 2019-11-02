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
    int m,k;
    cin>>m>>k;
    vector<int> d(m);
    vector<int> s(m);
    for(int c=0;c<m;c++)
        cin>>d[c];
    for(int c=0;c<m;c++)
        cin>>s[c];
    int act=0;
    int temps_tot=0;
    int zone_act=0;
    while(zone_act!=m)
    {
        act+=s[zone_act];
        int zone=zone_act+1;
        int distance=d[zone_act];
        while(zone<m&&s[zone_act]>=s[zone])
        {
            act+=s[zone];
            distance+=d[zone];
            zone++;
        }
        int to_add=(max(distance-act,0)/s[zone_act]+(max(distance-act,0)%s[zone_act]==0?0:1))*s[zone_act];
        temps_tot+=to_add/s[zone_act]*k+distance;
        act+=to_add-distance;
        zone_act=zone;
    }
    cout<<temps_tot;
}