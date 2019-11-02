#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 
    int N;
    cin>>N;
    vector<int> v(N);
    for(int c=0;c<N;c++) cin>>v[c];
    sort(v.begin(),v.end());
    for(int c=0;c<v.size();c++)
    {
        if(c==0) cout<<v[c+1]-v[c]<<" "<<v.back()-v[c]<<endl;
        else if(c+1==v.size()) cout<<v[c]-v[c-1]<<" "<<v[c]-v[0]<<endl;
        else cout<<min(v[c]-v[c-1],v[c+1]-v[c])<<" "<<max(v.back()-v[c],v[c]-v[0])<<endl;
 
    }
}