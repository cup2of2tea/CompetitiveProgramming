#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int n;
    cin>>n;
    vector<long long> count(10000,0);
    vector<long long> count2(10000,0);
    long long res = 0;
    for(int c=0;c<n;c++) {
        int x;
        int y;
        cin>>x>>y;
        int lol = x-y+2000;
        int lol2 = (1001-x)-y+2000;
        res+=count[lol]+count2[lol2];
        count[lol]++;
        count2[lol2]++;
    }
    cout<<res;
}