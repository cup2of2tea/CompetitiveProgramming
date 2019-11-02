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
        ofstream out("output2.txt");
    #endif
    int nb;
    cin>>nb;
    map<int,pair<int,int> > m;
    vector<vector<int> > v(51,vector<int>(51));
    vector<int> nb_colonnes(nb);
    for(int c=0;c<nb;c++)
        cin>>nb_colonnes[c];
    for(int c=0;c<nb;c++)
        for(int c2=0;c2<nb_colonnes[c];c2++)
        {
            int z;
            cin>>v[c][c2];
            m[v[c][c2]]=make_pair(c+1,c2+1);
        }
    vector<int> x1,x2,y1,y2;
    int i=1;
    for(int c=0;c<nb;c++)
        for(int c2=0;c2<nb_colonnes[c];c2++)
        {
            if(m[i].first!=c+1||m[i].second!=c2+1)
            {
                x1.push_back(c+1);
                y1.push_back(c2+1);
                x2.push_back(m[i].first);
                y2.push_back(m[i].second);
                m[v[c][c2]]=m[i];
                v[m[i].first-1][m[i].second-1]=v[c][c2];
                v[c][c2]=i;
                m[i]=make_pair(c+1,c2+1);
            }
            i++;
        }
    cout<<x1.size()<<endl;
    for(int c=0;c<x1.size();c++)
        cout<<x1[c]<<" "<<y1[c]<<" "<<x2[c]<<" "<<y2[c]<<endl;
}