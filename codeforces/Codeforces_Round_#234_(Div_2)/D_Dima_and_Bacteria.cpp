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
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> sum(k);
    vector<vector<int> > floyd(k,vector<int>(k,500*1e5+1));
    vector<vector<pair<int,int> > > liste_adjacence(n+1);
    vector<int> type(n+1);
    for(int c=0;c<k;c++)
    {
        cin>>sum[c];
        if(sum[c]==1) floyd[c][c]=0;
        if(c>0) sum[c]+=sum[c-1];
        for(int c2=(c==0?1:sum[c-1]+1);c2<=sum[c];c2++) type[c2]=c;
    }
    for(int c=0;c<m;c++)
    {
        int a,b,cost;
        cin>>a>>b>>cost;
        liste_adjacence[a].push_back(make_pair(b,cost));
        liste_adjacence[b].push_back(make_pair(a,cost));
        int t1 = type[a];
        int t2 = type[b];
        floyd[t1][t2]=min(floyd[t1][t2],cost);
        floyd[t2][t1]=floyd[t1][t2];
    }
    for(int c=0;c<k;c++)
    {
        for(int c2=0;c2<k;c2++)
        {
            for(int c3=0;c3<k;c3++)
            {
                floyd[c2][c3] = min(floyd[c2][c3],floyd[c2][c]+floyd[c][c3]);
            }
        }
    }
    for(int c=0;c<k;c++)
    {
        priority_queue<pair<int,int> > dijkstra;
        dijkstra.push(make_pair(sum[c],0));
        int found = 0;
        vector<bool> visites(n+1,false);
        while(dijkstra.size() && found != sum[c] - (c==0?0:sum[c-1]))
        {
            pair<int,int> act = dijkstra.top();
            dijkstra.pop();
            int d = -act.second;
            int node = act.first;
            if(d!=0) continue;
            if(visites[node]) continue;
            if(type[node]==c){ found++;}
            visites[node]=true;
            for(int c2=0;c2<liste_adjacence[node].size();c2++)
            {
                int new_node = liste_adjacence[node][c2].first;
                int new_d = -(d + liste_adjacence[node][c2].second);
                if(!visites[new_node]&&new_d == 0)
                {
                    dijkstra.push(make_pair(new_node,new_d));
                }
            }
        }
        if(found != sum[c] - (c==0?0:sum[c-1]))
        {
            cout<<"No";
            return 0;
        }
    }
 
    cout<<"Yes"<<endl;
    for(int c=0;c<k;c++,cout<<endl)
        for(int c2=0;c2<k;c2++)if(floyd[c][c2]==500*1e5+1) cout<<-1<<" "; else  cout<<floyd[c][c2]<<" ";
}