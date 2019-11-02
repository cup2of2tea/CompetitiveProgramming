#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> yummy(n);
    for(int c=0;c<n;c++) cin>>yummy[c];
    vector<vector<int> > rules(n,vector<int>(n,0));
    for(int c=0;c<k;c++){
        int from, to, apport;
        cin>>from>>to>>apport;
        from--;
        to--;
        rules[from][to]=apport;
    }
 
    vector<vector<long long > > dp(1<<n,vector<long long int>(n,0));
    for(int c=0;c<n;c++) {
        dp[(1<<c)][c] = yummy[c];
    }
    for(int c=0;c<(1<<n);c++) {
        for(int c2=0;c2<n;c2++) {
            if((1<<c2) & c){
                for(int c3=0;c3<n;c3++) {
                    if((1<<c3) & c) continue;
                    dp[c|(1<<c3)][c3] = max(dp[c|(1<<c3)][c3], dp[c][c2] + rules[c2][c3] + yummy[c3]);
                }
            }
        }
    }
    long long int res = 0;
    for(int c=0;c<(1<<n);c++) {
        if(__builtin_popcount(c) == m) {
            for(int c2=0;c2<n;c2++) {
                res = max(res,dp[c][c2]);
            }
        }
    }
    cout<<res;
}