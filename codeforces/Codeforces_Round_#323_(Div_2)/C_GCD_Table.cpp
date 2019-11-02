#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <map>
using namespace std;
 
long long mod = 1e9+7;
 
int pgcd(int a,int b) {
    if(a==0) return b;
    return pgcd(b%a,a);
}
 
 
int main()
{
    int n;
    cin>>n;
    vector<int>v(n*n);
    for(int c=0;c<n*n;c++) cin>>v[c];
    sort(v.rbegin(),v.rend());
    map<int,int> m;
    for(int c=0;c<v.size();c++) m[v[c]]++;
    vector<int> res(n);
    int i = 0;
    for(int c=0;c<n;c++)
    {
        while(m[v[i]]==0) i++;
        for(int c2=0;c2<c;c2++)
        {
            m[pgcd(v[i],res[c2])]-=2;
        }
        res[c]=(v[i]);
        m[v[i]]--;
        i++;
    }
    for(int c=0;c<res.size();c++) cout<<res[c]<<" ";
}