#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
    int n,w;
    cin>>n>>w;
    vector<int> capacity(2*n);
    for(int c=0;c<2*n;c++)
    {
        cin>>capacity[c];
    }
    sort(capacity.begin(),capacity.end());
    cout<<fixed<<min((double)w,min((double)capacity[0],(double)capacity[n]/2.)*3.*(double)n)<<endl;
}