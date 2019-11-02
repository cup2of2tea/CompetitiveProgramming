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
 
const long long UNIVERS = -4242424242LL;
 
 
 
 
int main()
{
ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n;
    cin>>n;
    if(n<3)
    {
        cout<<"NO";
        return 0;
    }
    vector<pair<int,int> > v(n);
    for(int c=0;c<n;c++)
    {
        cin>>v[c].first;
        v[c].second=c+1;
    }
    sort(v.begin(),v.end());
    vector<vector<pair<int,int> > > swaps;
    vector<pair<int,int> > tmp(1,v[0]);
    int nb2 = 0;
    for(int c=1;c<=v.size();c++)
    {
        if(v[c].first!=v[c-1].first||c==v.size())
        {
            swaps.push_back(tmp);
            if(tmp.size()==2) nb2++;
            else if(tmp.size()>=3) nb2+=2;
            tmp.clear();
        }
        if(c!=v.size())
            tmp.push_back(v[c]);
    }
    if(nb2<2)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    for(int c=0;c<swaps.size();c++)
    {
        for(int c2=0;c2<swaps[c].size();c2++)
            cout<<swaps[c][c2].second<<" ";
    }
    cout<<endl;
    int c;
    for(c=0;c<swaps.size();c++)
    {
        if(swaps[c].size()>=2){ next_permutation(swaps[c].begin(),swaps[c].end());break;}
    }
    for(int c=0;c<swaps.size();c++)
    {
        for(int c2=0;c2<swaps[c].size();c2++)
            cout<<swaps[c][c2].second<<" ";
    }
    cout<<endl;
    if(swaps[c].size()==2) c++;
    for(;c<swaps.size();c++)
    {
        if(swaps[c].size()>=2) { next_permutation(swaps[c].begin(),swaps[c].end());break;}
    }
    for(int c=0;c<swaps.size();c++)
    {
        for(int c2=0;c2<swaps[c].size();c2++)
            cout<<swaps[c][c2].second<<" ";
    }
    cout<<endl;
}