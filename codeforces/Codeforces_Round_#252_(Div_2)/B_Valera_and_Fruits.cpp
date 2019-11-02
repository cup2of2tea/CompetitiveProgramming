#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
 
 
    int n,v;
    cin>>n>>v;
    vector<pair<int,int> > trees(n);
    for(int c=0;c<n;c++) cin>>trees[c].first>>trees[c].second;
    sort(trees.begin(),trees.end());
    queue<pair<int,int> > act;
    int res = 0;
    int moins = 0;
    for(int c=0;c<=3010;c++)
    {
        for(int c2=0;c2<trees.size();c2++)
        {
            if(trees[c2].first==c) act.push(trees[c2]);
        }
        while(act.size()!=0&&act.front().first+1<c)
        {
            moins = 0;
            act.pop();
        }
        int v2 = v;
        while(v2!=0&&act.size()!=0)
        {
            int z= act.front().second-moins;
            if(v2 < z)
            {
                moins += v2;
                res += v2;
                v2=0;
            }
            else
            {
                moins = 0;
                act.pop();
                res+=z;
                v2-=z;
            }
        }
    }
    cout<<res;
}