#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXL 100
#define MAXN 51
int memo[MAXL+1][MAXN][2*MAXL+1];
char str[MAXL];
int N;
int L;
 
int solve(int idx, int n, int dxx, int dir) {
        int &ret = memo[idx][n][dxx];
        if(ret != -1) return ret;
        int dx = dxx - L;
        
        if(idx == L) {
                if(n == 0)
                return ret = abs(dx);
                else
                return ret = 0;
        }
        // dont convert
        ret = 0;
        for(int ch=0;ch<=n;ch++) {
                if(ch%2 == 0) {
                        if(str[idx] == 'T') {
                                ret = max(ret, solve(idx+1, n-ch, dx + L, dir^1));
                        } else {
                                int disp = dir?1:-1;
                                ret = max(ret, solve(idx+1, n-ch, dx+disp+L, dir));
                        }
                } else {
                        if(str[idx] == 'T') {
                                int disp = dir?1:-1;
                                ret = max(ret, solve(idx+1, n-ch, dx+disp+L, dir));
                        } else {
                                ret = max(ret, solve(idx+1, n-ch, dx+L, dir^1));
                        }
                }
        }
        
        return ret;
}
int main() {
        scanf("%s", str);
        scanf("%d", &N);
        L = strlen(str);
        memset(memo, -1, sizeof memo);
        
        printf("%d\n", solve(0, N, L, 1));
        return 0;
}
 