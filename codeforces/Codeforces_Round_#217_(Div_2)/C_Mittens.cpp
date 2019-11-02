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
 
int countcol[1001];
 
int blabla = -1;
 
 
bool comparaison(const pair<int,int> &p1,const pair<int,int> &p2)
{
    return p1.second!=blabla&&(countcol[p1.second]>countcol[p2.second]||p2.second==blabla||
    (countcol[p1.second]==countcol[p2.second]&&p1.second>p2.second));
}
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
//#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > v(n);
    for(int c=0;c<n;c++)
    {
        v[c].first=c;
        cin>>v[c].second;
        countcol[v[c].second]++;
    }
    sort(v.begin(),v.end(),comparaison);
    //for(int c=0;c<v.size();c++) cout<<v[c].first<<" "<<v[c].second<<endl;
    //cout<<endl;
    vector<pair<int,int> > v2(n);
    copy(v.begin(),v.end(),v2.begin());
    blabla=v[0].second;
    sort(v2.begin(),v2.end(),comparaison);
    //for(int c=0;c<v.size();c++) cout<<v2[c].first<<" "<<v2[c].second<<endl;
    //cout<<endl;
    int res = 0;
    vector<pair<int,int> > match(n);
    for(int c=0;c<v.size();c++)
    {
        if(v[c].second!=v2[c].second)
            res++;
        match[v[c].first]=make_pair(v[c].second,v2[c].second);
    }
    cout<<res<<endl;
    for(int c=0;c<v.size();c++)
    {
        cout<<match[c].first<<" "<<match[c].second<<endl;
    }
}
 