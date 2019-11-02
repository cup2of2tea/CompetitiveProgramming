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
#include <limits>
#include <iterator>
#include <stack>
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
#ifdef LOCAL
#define cin in
#define COUT(s) cout<<"----"<<s<<"----"<<endl
#endif
#ifndef LOCAL
#define COUT(s);
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
 
using namespace std;
 
const long long INFLL=numeric_limits<long long int>::max();
const int INF=numeric_limits<int>::max();
 
class comparaison1
{
    public:
    comparaison1(){}
    bool operator()(const int &a,const int &b)
    {
        return a>b;
    }
};
 
class comparaison2
{
    public:
    comparaison2(){}
    bool operator()(const int &a,const int &b)
    {
        return b>a;
    }
};
 
 
int main()
{
#ifdef LOCAL
    ifstream cin("input.txt");
#endif
    int n;
    cin>>n;
    vector<pair<int,int> > drift(n);
    for(int c=0;c<n;c++)
        cin>>drift[c].first>>drift[c].second;
    vector<vector<bool> > matrice_adjacence(n,vector<bool>(n,false));
    for(int c=0;c<n;c++)
        for(int c2=0;c2<n;c2++)
            if(drift[c].first==drift[c2].first||drift[c].second==drift[c2].second)
                matrice_adjacence[c][c2]=true;
    vector<bool> visites(n,false);
    int nb_visites=0;
    int zone=0;
    while(nb_visites!=n)
    {
        int zone_dep;
        for(zone_dep=0;visites[zone_dep];zone_dep++);
        vector<int> to_do;
        to_do.push_back(zone_dep);
        visites[zone_dep]=true;
        nb_visites++;
        while(to_do.size()!=0)
        {
            int z=to_do.back();
            to_do.pop_back();
            for(int c=0;c<n;c++)
                if(matrice_adjacence[z][c]&&!visites[c])
                {
                    visites[c]=true;
                    nb_visites++;
                    to_do.push_back(c);
                }
        }
        zone++;
    }
    cout<<zone-1;
 
}