#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <ctime>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
 
const long long UNIVERS = -4242424242LL;
 
int main()
{
ios_base::sync_with_stdio(false);
 
    int n,m,k;
    cin>>n>>k>>m;
    vector<long long int> sum(n,0);
 
    for(int c=0;c<n;c++)
    {
        cin>>sum[c];
        if(c>0) sum[c]+=sum[c-1];
    }
    vector<vector<long long int> > dp(n+1,vector<long long int>(m+1,-4242424242LL));
    dp[0][0]=0;
    for(int c=0;c<=n;c++)
    {
        for(int c2=0;c2<=m;c2++)
        {
            if(c>0)
                dp[c][c2]=max(dp[c-1][c2],dp[c][c2]);
            if(c2<m&&c+k<=n&&dp[c][c2]!=UNIVERS)
            {
                dp[c+k][c2+1]=max(dp[c+k][c2+1],dp[c][c2]+sum[c+k-1]-(c>0?sum[c-1]:0));
            }
        }
    }
    cout<<dp[n][m];
}