#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;
 
struct comparaison
{
    bool operator()(const pair<int,int> &p1,const pair<int,int> &p2)
    {
        if(p1.first==p2.first)
            return p1.second<p2.second;
        return p1.first<p2.first;
    }
};
 
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
#define cin in
#define cout out
    int n;
    cin>>n;
    vector<pair<int,int> > v(n*2);
    for(int c=0;c<n*2;c++)
    {
        cin>>v[c].first;
        v[c].second=c;
    }
    sort(v.begin(),v.end(),comparaison());
    vector<pair<int,int> > res;
    for(int c=0;c<v.size();c+=2)
    {
       // cout<<v[c].first<<" "<<v[c+1].first<<endl;
        if(v[c].first!=v[c+1].first)
        {
            cout<<-1;
            return 0;
        }
        res.push_back(make_pair(v[c].second+1,v[c+1].second+1));
    }
    for(int c=0;c<res.size();c++)
        cout<<res[c].first<<" "<<res[c].second<<endl;
}