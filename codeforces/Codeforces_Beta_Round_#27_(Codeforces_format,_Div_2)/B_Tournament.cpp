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
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
 
#ifdef LOCAL
#define cin in
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
 
 
using namespace std;
 
 
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    int n;
    cin>>n;
    int nb_matchs=((n-1)*n)/2-1;
    vector<pair<int,int> > v(nb_matchs);
    for(int c=0;c<nb_matchs;c++)
        cin>>v[c].first>>v[c].second;
    vector<vector<int> > v2(n+1,vector<int>(n+1));
    for(int c=0;c<=n;c++)
        for(int c2=0;c2<=n;c2++)
            v2[c][c2]=0;
    for(int c=0;c<nb_matchs;c++)
    {
        v2[v[c].first][v[c].second]=1;
        v2[v[c].second][v[c].first]=-1;
    }
    for(int c=1;c<=n;c++)
    {
        for(int c2=c+1;c2<=n;c2++)
        {
            if(v2[c][c2]==0)
            {
                for(int c3=1;c3<=n;c3++)
                    if(c3==c||c3==c2)
                        continue;
                    else if(v2[c3][c]==1&&v2[c3][c2]==-1)
                    {
                        cout<<c2<<" "<<c;
                        return 0;
                    }
                    else if(v2[c3][c]==-1&&v2[c3][c2]==1)
                    {
                        cout<<c<<" "<<c2;
                        return 0;
                    }
                cout<<c<<" "<<c2;
            }
        }
    }
}