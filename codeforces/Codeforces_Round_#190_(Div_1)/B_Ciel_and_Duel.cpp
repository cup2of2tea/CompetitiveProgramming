#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <ctime>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
 
 
bool comparaison(const pair<string,int> &p1,const pair<string,int> &p2)
{
    if(p1.second==p2.second)
    {
        if(p1.first!="DEF"&&p2.first=="DEF")
        {
            return true;
        }
        return false;
    }
    return p1.second<p2.second;
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n,m;
    cin>>n>>m;
    vector<pair<string,int> > v(n);
    for(int c=0;c<n;c++)
        cin>>v[c].first>>v[c].second;
    sort(v.begin(),v.end(),comparaison);
    vector<int> v2(m);
    for(int c=0;c<m;c++) cin>>v2[c];
    sort(v2.begin(),v2.end());
    int maxi1 = 0;
    int indice = m-1;
    for(int c=0;c<n&&indice>=0&&v2[indice]>=v[c].second;c++)
    {
        if(v[c].first=="ATK")
        {
            maxi1+=v2[indice]-v[c].second;
            indice--;
        }
    }
    int maxi2 = 0;
    vector<bool> visites(m,false);
    indice = 0;
    for(int c=0;c<n;c++)
    {
        if(v[c].first=="DEF")
        {
            while(indice<m&&v2[indice]<=v[c].second)
                indice++;
            if(indice!=m)
                visites[indice]=true;
            else goto nop;
            indice++;
        }
    }
    indice = 0;
    for(int c=0;c<n;c++)
    {
        if(v[c].first=="ATK")
        {
            while(indice<m&&(v2[indice]<v[c].second||visites[indice]))
                indice++;
            if(indice!=m)
                visites[indice]=true;
            else goto nop;
            maxi2+=v2[indice]-v[c].second;
            indice++;
        }
    }
    for(int c=0;c<m;c++)
    {
        if(!visites[c])
        {
                maxi2+=v2[c];
        }
    }
 
    nop:
        cout<<max(maxi1,maxi2);
 
}
 