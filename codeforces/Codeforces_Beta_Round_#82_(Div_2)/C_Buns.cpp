#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
 
int main()
{
    int n,m,c0,d0;
    cin>>n>>m>>c0>>d0;
    vector<vector<int> > dp(n+1,vector<int>(m+1,0));
    vector<int> a(m),b(m),c(m),d(m);
    for(int i=0;i<m;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
    int maxi = 0;
    for(int i=0;i*c0<=n;i++) dp[i*c0][0] = d0*i;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            for(int k=0;k*b[i]<=a[i]&&j-c[i]*k>=0;k++)
            {
                dp[j][i+1] = max(dp[j][i+1],dp[j-c[i]*k][i]+k*d[i]);
                maxi = max(maxi,dp[j][i+1]);
            }
        }
    }
    cout<<maxi;
 
}