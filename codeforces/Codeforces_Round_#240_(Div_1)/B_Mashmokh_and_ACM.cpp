#include <iostream>
#include <queue>
 
using namespace std;
const int MOD = 1e9+7;
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    vector<vector<int> > dp(2002,vector<int>(2002,0));
    int n,k;
    cin>>n>>k;
    for(int c=1;c<=n;c++) dp[0][c]=1;
    for(int c=0;c+1<k;c++)
    {
        for(int c2=1;c2<=n;c2++)
        {
            for(int c3=c2;c3<=n;c3+=c2)
            {
                dp[c+1][c3]+=dp[c][c2];
                dp[c+1][c3]%=MOD;
            }
        }
    }
    long long sum = 0;
    for(int c=1;c<=n;c++)
    {
        sum+=dp[k-1][c];
        sum%=MOD;
    }
    cout<<sum;
}