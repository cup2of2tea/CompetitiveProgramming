#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
 
int calculate1(vector<vector<int> > &v,int x1,int x2,int y1,int y2)
{
    int res = v[x2][y2];
    if(x1 > 0) res -= v[x1-1][y2];
    if(y1 > 0) res -= v[x2][y1-1];
    if(x1 > 0 && y1 > 0) res += v[x1-1][y1-1];
    return res;
}
 
 
 
int main()
{
 
    ios_base::sync_with_stdio(false);
    int n,m,q;
    cin>>n>>m>>q;
    vector<string> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
    vector<vector<int> > sum(n,vector<int>(m));
    for(int c=0;c<n;c++)
    {
        for(int c2=0;c2<m;c2++)
        {
            sum[c][c2]=v[c][c2]-'0';
            if(c>0) sum[c][c2]+=sum[c-1][c2];
            if(c2>0) sum[c][c2]+=sum[c][c2-1];
            if(c>0&&c2>0) sum[c][c2]-=sum[c-1][c2-1];
        }
    }
    vector<vector<vector<vector<int> > > > dp(n+1,vector<vector<vector<int> > > (m+1,vector<vector<int> >(n+1,vector<int>(m+1,0))));
    for(int c=0;c<n;c++)
    {
        for(int c2=0;c2<m;c2++)
        {
            for(int c3=0;c3<n;c3++)
            {
                for(int c4=0;c4<m;c4++)
                {
                    dp[c+1][c2+1][c3+1][c4+1]=((c3<c||c4<c2||calculate1(sum,c,c3,c2,c4))?0:1);
                    for(int c5=0;c5<(1<<4)-1;c5++)
                    {
                        int z = __builtin_popcount(c5);
                        int i=c+(c5&1),j=c2+((c5&2)>>1),k=c3+((c5&4)>>2),l=c4+((c5&8)>>3);
                        dp[c+1][c2+1][c3+1][c4+1] += (z%2?1:-1)*dp[i][j][k][l];
                    }
                }
            }
        }
    }
 
    for(int c=0;c<q;c++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int res = 0;
        for(int c5=0;c5<(1<<4);c5++)
        {
            int z = __builtin_popcount(c5);
            int i,j,k,l;
            if(c5&1)
                i = x2;
            else i = x1-1;
            if(c5&2)
                j = y2;
            else j = y1-1;
            if(c5&4)
                k = x2;
            else k = x1-1;
            if(c5&8)
                l = y2;
            else l = y1-1;
            res += (z%2?-1:1)*dp[i][j][k][l];
        }
        cout<<res<<endl;
    }
}