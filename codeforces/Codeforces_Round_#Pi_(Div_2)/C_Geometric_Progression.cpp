#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long int n,k;
    cin>>n>>k;
    vector<long long > v(n);
    for(int c=0;c<n;c++)
    {
        cin>>v[c];
    }
    long long res = 0;
    map<long long,long long int> m;
    map<long long,long long int> m2;
    for(int c=0;c<n;c++)
    {
        if(v[c]%k==0)
        {
            res+=m2[v[c]/k];
            m2[v[c]]+=m[v[c]/k];
        }
        m[v[c]]++;
    }
    cout<<res;
}