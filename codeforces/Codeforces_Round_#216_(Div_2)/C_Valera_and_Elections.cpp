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
 
vector<int> cities;
 
int parcours(int zone,vector<vector<pair<int,bool> > > &liste_adjacence,vector<bool> &visites)
{
    int res2=0;
    for(int c=0;c<liste_adjacence[zone].size();c++)
    {
        int new_zone=liste_adjacence[zone][c].first;
        bool to_repair=liste_adjacence[zone][c].second;
        if(!visites[new_zone])
        {
            visites[new_zone]=true;
            int res=parcours(new_zone,liste_adjacence,visites);
            res2+=max((to_repair?1:0),res);
            if(to_repair&&res==0)
                cities.push_back(new_zone);
        }
    }
    return res2;
}
 
 
 
int main()
{
 
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n;
    cin>>n;
    vector<vector<pair<int,bool> > > liste_adjacence(n);
    for(int c=0;c<n-1;c++)
    {
        int de,to,rep;
        cin>>de>>to>>rep;
        liste_adjacence[de-1].push_back(make_pair(to-1,rep==2));
        liste_adjacence[to-1].push_back(make_pair(de-1,rep==2));
    }
    vector<bool> visites(n,false);
    visites[0]=true;
    parcours(0,liste_adjacence,visites);
    cout<<cities.size()<<endl;
    for(int c=0;c<cities.size();c++)
        cout<<cities[c]+1<<" ";
}