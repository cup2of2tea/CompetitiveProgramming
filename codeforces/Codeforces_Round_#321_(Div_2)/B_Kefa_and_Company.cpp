#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n,d;
    cin>>n>>d;
    vector<pair<int,int> > infos(n);
    for(int c=0;c<n;c++) cin>>infos[c].first>>infos[c].second;
    sort(infos.begin(),infos.end());
    int l = 0, r = 0;
    long long int happiness = 0;
    long long res = 0;
    while(r < n){
            happiness += infos[r].second;
        while(r > l && infos[r].first - infos[l].first >= d){
            happiness -= infos[l++].second;
        }
        res = max(res, happiness);
        r++;
    }
    cout<<res;
}