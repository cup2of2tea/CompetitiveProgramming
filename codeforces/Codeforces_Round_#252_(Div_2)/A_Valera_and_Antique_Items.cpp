#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
    int n,v;
    cin>>n>>v;
    vector<int> res;
    for(int c=0;c<n;c++)
    {
        int a;
        cin>>a;
        int tmp = 1e8;
        while(a--)
        {
            int z;
            cin>>z;
            tmp = min(tmp,z);
        }
        if(v>=tmp+1) res.push_back(c);
    }
    cout<<res.size()<<endl;
    for(int c=0;c<res.size();c++) cout<<res[c]+1<<" ";
}