#include <bits/stdc++.h>
 
 
using namespace std;
 
int main()
{
    int n,x;
    cin>>n>>x;
    vector<vector<pair<int,int> > > v(2);
    for(int c=0;c<n;c++)
    {
        int t,h,m;
        cin>>t>>h>>m;
        v[t].push_back(make_pair(h,m));
    }
    //sort(v[0].begin(),v[0].end());
    //sort(v[1].begin(),v[1].end());
    int res = 0;
    for(int c=0;c<2;c++)
    {
        //int i[2] = {0,0};
        int t = c;
        int bond = x;
        int n = 0;
        vector<vector<bool> > visites(2,vector<bool>(max(v[0].size(),v[1].size()),false));
        while(1)
        {
            int best = -1;
            for(int c=0;c<v[t].size();c++) if(v[t][c].first <= bond && (best == -1 ||v[t][c].second > v[t][best].second) && !visites[t][c]) best = c;
            if(best!=-1)
            {
                visites[t][best] = true;
                bond += v[t][best].second;
                n++;
                t++;
                t%=2;
            }
            else
            {
                break;
            }
        }
        res = max(res,n);
    }
    cout<<res;
}