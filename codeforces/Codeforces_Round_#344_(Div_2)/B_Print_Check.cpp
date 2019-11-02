#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > cols(m,make_pair(-1,0));
    vector<pair<int,int> > rows(n,make_pair(-1,0));
 
    int k;
    cin>>k;
    for(int c=0;c<k;c++) {
        int t,v,col;
        cin>>t>>v>>col;
        v--;
        if(t == 2) {
            cols[v] = make_pair(c,col);
        } else {
            rows[v] = make_pair(c,col);
        }
    }
    for(int c=0;c<n;c++)
    {
        for(int c2=0;c2<m;c2++)
        {
            if(rows[c].first > cols[c2].first) {
                cout<<rows[c].second<<" ";
            } else {
                cout<<cols[c2].second<<" ";
            }
        }
        cout<<endl;
    }
}