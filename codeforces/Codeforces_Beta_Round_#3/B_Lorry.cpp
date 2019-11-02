#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=100005;
int n,m,v;
int Sa[N];
int Sb[N];
bool mark[N];
struct Node{int p,pos;}a[N],b[N];
 
void init(){
     int k,i,t,p;
     scanf("%d%d",&k,&v);
     n=m=0;
     for (i=1;i<=k;i++){
         scanf("%d%d",&t,&p);
         if (t==1) { a[++m].p=p; a[m].pos=i; }
              else { b[++n].p=p; b[n].pos=i; }
     }
}
 
inline bool cmp(const Node &A,const Node &B){return A.p>B.p;}
void work(){
     int i,j,ans=0,cuti=0,cutj=0;
     sort(a+1,a+m+1,cmp);
     sort(b+1,b+n+1,cmp);
     for (Sa[0]=0,i=1;i<=m;i++) Sa[i]=Sa[i-1]+a[i].p;
     for (Sb[0]=0,i=1;i<=n;i++) Sb[i]=Sb[i-1]+b[i].p;
     for (i=0,j=n;i<=m && i<=v;i++){
         while (j && i+2*j>v) j--;
         if (Sa[i]+Sb[j]>ans){
           ans=Sa[i]+Sb[j];
           cuti=i;
           cutj=j;
         }
     }
     printf("%d\n",ans);
     memset(mark,0,sizeof(mark));
     for (i=1;i<=cuti;i++) mark[a[i].pos]=true;
     for (j=1;j<=cutj;j++) mark[b[j].pos]=true;
     for (i=1;i<=n+m;i++)
       if (mark[i]) printf("%d ",i);
     puts("");
}
 
int main(){
    init();
    work();
}