#include<cstdio>
#define F(i,n) for(int i=0;i<n;i++)
#define M(a,b) ((a<b)?a:b)
int n,m,a[406][406],c[406][406][8],r,f[]={-1,0,1,0,-1,1,1,-1},s[]={0,1,0,-1,1,1,-1,-1};int g(int i,int j,int k){int&r=c[i][j][k],y=i+f[k],z=j+s[k];return ~r?r:a[i][j]?0:(r=1+((y>=0&&y<n&&z>=0&&z<m)?g(y,z,k):0));}int main(){scanf("%d%d",&n,&m);F(i,n){getchar();F(j,m)a[i][j]=getchar()=='1';}F(i,n)F(j,m)F(k,8)c[i][j][k]=-1;F(i,n)F(j,m)F(k,8)g(i,j,k);F(i,n)F(j,m)if(!a[i][j])F(u,8)F(d,M(c[i][j][u],c[i][j][(u+1)%4+(u>=4)*4]))if(d)r+=c[i+d*f[u]][j+d*s[u]][(u+1+(u>=4))%4+(u<4)*4]>=(u>=4)*d+d+1;printf("%d",r);}