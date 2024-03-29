#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
 
long long dp[55][10];
char s[100];
 
int main(void) {
        scanf("%s", s);
        int n = strlen(s);
        for(int i=0;i<10;i++)
                dp[0][i] = 1;
        for(int i=1;s[i];i++) {
                int t=s[i]-'0';
                for(int j=0;j<10;j++) {
                        int l=(t+j)/2, r=(t+j+1)/2;
                        dp[i][l] += dp[i-1][j];
                        if (l!=r) dp[i][r] += dp[i-1][j];
                }
        }
        int flag=0;
        for(int i=1;s[i];i++) {
                int t=s[i]-'0', j=s[i-1]-'0';
                if (t != (j+t)/2 && t != (j+t+1)/2) flag=1;
        }
        long long ans=-1+flag;
        for(int i=0;i<10;i++)
                ans += dp[n-1][i];
        printf("%I64d\n", ans);
        return 0;
}