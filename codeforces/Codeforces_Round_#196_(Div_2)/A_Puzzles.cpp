#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(m);
    for(int c=0;c<m;c++) cin>>v[c];
    sort(v.begin(),v.end());
    int mini=1000+1000;
    for(int c=0;c+n<=m;c++)
    {
        mini=min(v[c+n-1]-v[c],mini);
    }
    cout<<mini;
}