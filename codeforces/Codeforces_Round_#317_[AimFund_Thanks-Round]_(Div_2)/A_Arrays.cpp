#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    int na,nb;
    cin>>na>>nb;
    int k,m;
    cin>>k>>m;
    vector<int> v(na),v2(nb);
    for(int c=0;c<na;c++) cin>>v[c];
    for(int c=0;c<nb;c++) cin>>v2[c];
    if(v[k-1]<v2[nb-m]) {
        cout<<"YES";
    }
    else {
        cout<<"NO";
    }
}