#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
 
int main()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int> > distances(n);
    int previous=-1,act=0,act2=-1;
    for(int c=0;c<distances.size();c++)
    {
        cin>>distances[c].first;
        distances[c].second=c;
    }
    sort(distances.begin(),distances.end());
    vector<pair<int,int> > edges;
    if(distances[0].first!=0)
    {
        cout<<-1;
        return 0;
    }
 
    vector<int> degres(distances.size(),0);
    for(int c=1;c<distances.size();c++)
    {
        if(distances[c].first!=distances[c-1].first)
        {
            if(distances[c].first-1!=distances[c-1].first)
            {
                cout<<-1;
                return 0;
            }
            previous = act;
            act = c;
            act2 = previous;
        }
        if(act2==-1||degres[distances[act2].second] >= k)
        {
            cout<<-1;
            return 0;
        }
        degres[distances[act2].second]++;
        degres[distances[c].second]++;
        edges.push_back(make_pair(distances[c].second+1,distances[act2].second+1));
        act2++;
        if(act2==act) act2=previous;
    }
    cout<<edges.size()<<endl;
    for(int c=0;c<edges.size();c++) cout<<edges[c].first<<" "<<edges[c].second<<endl;
}